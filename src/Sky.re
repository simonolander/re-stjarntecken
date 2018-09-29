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

let viewBoxWidth = 100.0;
let viewBoxHeight = 100.0;
let viewBox =
  "0 0 " ++ Util.str(viewBoxWidth) ++ " " ++ Util.str(viewBoxHeight);

let style = ReactDOMRe.Style.make(~backgroundColor="black", ());

let renderConstellationEdge = (star1: Model.star, star2: Model.star) => {
  let x1 = Util.str(star1.position.x);
  let y1 = Util.str(star1.position.y);
  let x2 = Util.str(star2.position.x);
  let y2 = Util.str(star2.position.y);
  <line x1 y1 x2 y2 stroke="white"/>;
};

let make = (~sky: Model.sky, _children) => {
  ...component,
  initialState: () => {
    let stars = sky.stars;
    let constellations = sky.constellations;
    let enteredStarId = None;
    let focusedStarId = None;
    let currentEdges = [];
    {stars, constellations, enteredStarId, focusedStarId, currentEdges};
  },
  reducer: (action, state) =>
    switch (action) {
    | EnterStar(starId) =>
      let enteredStarId = Some(starId);
      let focusedStarId =
        if (Option.isPresent(state.focusedStarId)) {
          Some(starId);
        } else {
          None;
        };
      let edge =
        Option.flatMap2(Model.createEdge, focusedStarId, state.focusedStarId);
      let currentEdges = Option.apply(Lists.toggle, state.currentEdges, edge);
      ReasonReact.Update({
        ...state,
        enteredStarId,
        focusedStarId,
        currentEdges,
      });
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
    let stars =
      self.state.stars
      |> List.map((star: Model.star) =>
           <Star
             position={star.position}
             radius={
                      if (Option.contains(star.id, self.state.focusedStarId)) {
                        5.;
                      } else {
                        4.;
                      }
                    }
             onEnter={() => self.send(EnterStar(star.id))}
             onLeave={() => self.send(LeaveStar(star.id))}
           />
         )
      |> Array.of_list;
    let currentEdges =
      self.state.currentEdges
      |> List.map(Model.findStars(self.state.stars))
      |> List.map(
           Option.map(Functions.uncurry(renderConstellationEdge)),
         )
      |> Option.flattenList
      |> Array.of_list;
    let elements = Array.concat([currentEdges, stars]);
    <svg
      className="full-size"
      viewBox
      style
      onMouseDown={_ => self.send(Down)}
      onMouseUp={_ => self.send(Up)}>
      ...elements
    </svg>;
  },
};