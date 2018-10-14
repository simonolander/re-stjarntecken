type state = {
  stars: list(Model.star),
  constellations: list(Model.constellation),
  enteredStarId: option(Model.starId),
  focusedStarId: option(Model.starId),
  currentEdges: list(Model.constellationEdge),
};

type action =
  | EnterStar(Model.starId)
  | LeaveStar(Model.starId)
  | Down
  | Up;

let component = ReasonReact.reducerComponent("Sky");

let viewBox: Model.rectangle = {x: 0., y: 0., width: 100., height: 100.};

let viewBoxString = Geometry.viewBoxString(viewBox);

let style = ReactDOMRe.Style.make(~backgroundColor="black", ());

let updateConstellationsFound =
    (currentEdges, constellations: list(Model.constellation)) => {
  let isFound = (constellationEdges: list(Model.constellationEdge)) => {
    let isNotWrongEdge = edge =>
      Lists.contains(edge, constellationEdges)
      || !
           List.exists(
             e => fst(e) == fst(edge) || snd(e) == snd(edge),
             constellationEdges,
           );
    List.for_all(e => Lists.contains(e, currentEdges), constellationEdges)
    && List.for_all(isNotWrongEdge, currentEdges);
  };
  constellations
  |> List.map(constellation =>
       Model.{
         ...constellation,
         found: constellation.found || isFound(constellation.edges),
       }
     );
};

let starIdBelongsToFoundConstellation = (starId, constellations) =>
  constellations
  |> List.filter(Model.constellationIsFound)
  |> List.map(Model.getConstellationEdges)
  |> List.exists(Model.constellationEdgesContainStarId(starId));

let make = (~sky: Model.sky, _children) => {
  ...component,
  initialState: () => {
    let stars = Geometry.normalizeStarPositions(viewBox, sky.stars);
    let constellations = sky.constellations;
    let enteredStarId = None;
    let focusedStarId = None;
    /* let currentEdges = List.hd(sky.constellations).edges; */
    let currentEdges = [];
    {stars, constellations, enteredStarId, focusedStarId, currentEdges};
  },
  reducer: (action, state) =>
    switch (action) {
    | EnterStar(enteredStarId) =>
      switch (state.focusedStarId) {
      | None =>
        ReasonReact.Update({...state, enteredStarId: Some(enteredStarId)})
      | Some(oldFocusedStarId) =>
        let newFocusedStarId = enteredStarId;
        let edge = Model.createEdge(newFocusedStarId, oldFocusedStarId);
        let currentEdgesBeforeRemoval =
          Option.apply(Lists.toggle, state.currentEdges, edge);
        let constellations =
          updateConstellationsFound(
            currentEdgesBeforeRemoval,
            state.constellations,
          );
        let foundEdges =
          constellations
          |> List.filter(Model.constellationIsFound)
          |> Lists.flatMap(Model.getConstellationEdges);
        let isEdgeFound = edge => !Lists.contains(edge, foundEdges);
        let currentEdges =
          currentEdgesBeforeRemoval |> List.filter(isEdgeFound);
        ReasonReact.Update({
          ...state,
          enteredStarId: Some(enteredStarId),
          focusedStarId: Some(newFocusedStarId),
          currentEdges,
          constellations,
        });
      }
    | LeaveStar(starId) =>
      switch (state.enteredStarId) {
      | Some(id) =>
        if (id == starId) {
          ReasonReact.Update({...state, enteredStarId: None});
        } else {
          ReasonReact.NoUpdate;
        }
      | None => ReasonReact.NoUpdate
      }
    | Down =>
      ReasonReact.Update({...state, focusedStarId: state.enteredStarId})
    | Up => ReasonReact.Update({...state, focusedStarId: None})
    },
  render: self => {
    let idStarMap =
      self.state.stars
      |> Array.of_list
      |> Array.map((star: Model.star) => (star.id, star))
      |> Belt.Map.Int.fromArray;
    let foundConstellations =
      self.state.constellations
      |> List.filter(Model.constellationIsFound)
      |> List.map((constellation: Model.constellation) => {
           let stars =
             Model.getConstellationStarIds(constellation)
             |> List.map(Belt.Map.Int.get(idStarMap))
             |> Option.flattenList
             |> List.map((star: Model.star) =>
                  <Star position={star.position} radius={star.size *. 0.7} />
                )
             |> Array.of_list;
           let edges =
             constellation.edges
             |> List.map(Model.findStars(self.state.stars))
             |> List.map(
                  Option.map(((star1, star2)) =>
                    <ConstellationEdge star1 star2 />
                  ),
                )
             |> Option.flattenList
             |> Array.of_list;
           Array.concat([edges, stars]);
         })
      |> Array.concat;
    let foundStarIds =
      self.state.constellations
      |> List.filter(Model.constellationIsFound)
      |> Lists.flatMap(Model.getConstellationEdges)
      |> Lists.flatMap(Model.getConstellationEdgeStarIds)
      |> Array.of_list
      |> Belt.Set.Int.fromArray;
    let stars =
      self.state.stars
      |> List.filter((star: Model.star) =>
           !Belt.Set.Int.has(foundStarIds, star.id)
         )
      |> List.map((star: Model.star) =>
           <Star
             position={star.position}
             radius={
               Option.filter((==)(star.id), self.state.focusedStarId)
               |> Option.map(Functions.always(1.2))
               |> Option.withDefault(1.)
               |> ( *. )(star.size)
             }
             active=true
             focused={Option.contains(star.id, self.state.focusedStarId)}
             entered={Option.contains(star.id, self.state.enteredStarId)}
             onEnter={() => self.send(EnterStar(star.id))}
             onLeave={() => self.send(LeaveStar(star.id))}
           />
         )
      |> Array.of_list;
    let currentEdges =
      self.state.currentEdges
      |> List.map(Model.findStars(self.state.stars))
      |> List.map(
           Option.map(((star1, star2)) => <ConstellationEdge star1 star2 />),
         )
      |> Option.flattenList
      |> Array.of_list;
    let elements = Array.concat([foundConstellations, currentEdges, stars]);
    <svg
      className="full-size"
      viewBox=viewBoxString
      style
      onMouseDown={_ => self.send(Down)}
      onMouseUp={_ => self.send(Up)}>
      ...elements
    </svg>;
  },
};