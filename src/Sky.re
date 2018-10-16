type state = {
  stars: list(Model.star),
  constellations: list(Model.constellation),
  enteredStarId: option(Model.starId),
  focusedStarId: option(Model.starId),
  currentEdges: list(Model.constellationEdge),
  viewBox: Model.rectangle,
};

type action =
  | EnterStar(Model.starId)
  | LeaveStar(Model.starId)
  | Down
  | Up
  | Zoom(float, Model.position)
  | Pan(float, float);

let component = ReasonReact.reducerComponent("Sky");

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

let bounds = Model.{x: 0., y: 0., width: 100., height: 100.};

let starIdBelongsToFoundConstellation = (starId, constellations) =>
  constellations
  |> List.filter(Model.constellationIsFound)
  |> List.map(Model.getConstellationEdges)
  |> List.exists(Model.constellationEdgesContainStarId(starId));

let make = (~sky: Model.sky, _children) => {
  ...component,
  initialState: () => {
    let viewBox = Model.{x: 0., y: 0., width: 100., height: 100.};
    let stars = Geometry.normalizeStarPositions(viewBox, sky.stars);
    let constellations = sky.constellations;
    let enteredStarId = None;
    let focusedStarId = None;
    /* let currentEdges = List.hd(sky.constellations).edges; */
    let currentEdges = [];
    {
      stars,
      constellations,
      enteredStarId,
      focusedStarId,
      currentEdges,
      viewBox,
    };
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
        let isEdgeNotFound = edge => !Lists.contains(edge, foundEdges);
        let currentEdges =
          currentEdgesBeforeRemoval |> List.filter(isEdgeNotFound);
        let foundStarIds =
          constellations
          |> List.filter(Model.constellationIsFound)
          |> Lists.flatMap(Model.getConstellationStarIds);
        let isStarNotFound = starId => !Lists.contains(starId, foundStarIds);
        ReasonReact.Update({
          ...state,
          enteredStarId:
            Some(enteredStarId) |> Option.filter(isStarNotFound),
          focusedStarId:
            Some(newFocusedStarId) |> Option.filter(isStarNotFound),
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
    | Zoom(delta, position) =>
      ReasonReact.Update({
        ...state,
        viewBox: Geometry.zoomViewBox(state.viewBox, delta, position, bounds),
      })
    | Pan(dx, dy) =>
      ReasonReact.Update({
        ...state,
        viewBox: Geometry.panViewBox(state.viewBox, dx, dy, bounds),
      })
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
      preserveAspectRatio="none"
      className="full-size"
      viewBox={Geometry.viewBoxString(self.state.viewBox)}
      style
      onMouseDown={_ => self.send(Down)}
      onMouseUp={_ => self.send(Up)}
      onWheel={
        event => {
          let deltaY = event->ReactEvent.Wheel.deltaY;
          let delta = 1. +. deltaY *. 0.001;
          let clientX = event->ReactEvent.Wheel.nativeEvent##clientX;
          let clientY = event->ReactEvent.Wheel.nativeEvent##clientY;
          let svg =
            event->ReactEvent.Wheel.nativeEvent##target##tagName == "svg" ?
              event->ReactEvent.Wheel.nativeEvent##target :
              event->ReactEvent.Wheel.nativeEvent##target##viewportElement;
          let clientWidth = svg##clientWidth;
          let clientHeight = svg##clientHeight;
          let x =
            self.state.viewBox.x
            +. clientX
            /. clientWidth
            *. self.state.viewBox.width;
          let y =
            self.state.viewBox.y
            +. clientY
            /. clientHeight
            *. self.state.viewBox.height;
          self.send(Zoom(delta, {x, y}));
        }
      }
      onMouseMove={
        event => {
          let buttons = event->ReactEvent.Mouse.buttons;
          let primaryButtonPressed = buttons land 0x1 == 1;
          if (Belt.Option.isNone(self.state.focusedStarId)
              && primaryButtonPressed) {
            let optMovementX =
              event->ReactEvent.Mouse.nativeEvent##movementX
              ->Js.Nullable.toOption;
            let optMovementY =
              event->ReactEvent.Mouse.nativeEvent##movementY
              ->Js.Nullable.toOption;
            switch (Option.both(optMovementX, optMovementY)) {
            | None => ()
            | Some((movementX, movementY)) =>
              let svg =
                event->ReactEvent.Mouse.nativeEvent##target##tagName == "svg" ?
                  event->ReactEvent.Mouse.nativeEvent##target :
                  event->ReactEvent.Mouse.nativeEvent##target##viewportElement;
              let clientWidth = svg##clientWidth;
              let clientHeight = svg##clientHeight;
              let dx = -. movementX /. clientWidth *. self.state.viewBox.width;
              let dy =
                -. movementY /. clientHeight *. self.state.viewBox.height;
              self.send(Pan(dx, dy));
            };
          } else {
            ();
          };
        }
      }>
      ...elements
    </svg>;
  },
};