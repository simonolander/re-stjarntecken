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

let viewBoxMinX = 0.;
let viewBoxMinY = 0.;
let viewBoxWidth = 100.;
let viewBoxHeight = 100.;
let viewBox =
  Strings.ofFloat(viewBoxMinY)
  ++ " "
  ++ Strings.ofFloat(viewBoxMinY)
  ++ " "
  ++ Strings.ofFloat(viewBoxWidth)
  ++ " "
  ++ Strings.ofFloat(viewBoxHeight);

let style = ReactDOMRe.Style.make(~backgroundColor="black", ());

let renderConstellationEdge = (star1: Model.star, star2: Model.star) => {
  let x1 = Strings.ofFloat(star1.position.x);
  let y1 = Strings.ofFloat(star1.position.y);
  let x2 = Strings.ofFloat(star2.position.x);
  let y2 = Strings.ofFloat(star2.position.y);
  <line x1 y1 x2 y2 stroke="white" />;
};

let normalizeStarPositions = (stars: list(Model.star)) =>
  switch (stars) {
  | [] => []
  | [head, ...tail] =>
    let xs = List.map((star: Model.star) => star.position.x, tail);
    let ys = List.map((star: Model.star) => star.position.y, tail);
    let minX = List.fold_left(min, head.position.x, xs);
    let minY = List.fold_left(min, head.position.y, ys);
    let maxX = List.fold_left(max, head.position.x, xs);
    let maxY = List.fold_left(max, head.position.y, ys);
    let width = maxX -. minX;
    let height = maxY -. minY;
    let defaultMarginMultiplier = 0.1;
    let (marginX, marginY) =
      if (width == 0. || height == 0.) {
        (
          viewBoxWidth *. defaultMarginMultiplier,
          viewBoxHeight *. defaultMarginMultiplier,
        );
      } else if (width > height) {
        let marginX = viewBoxWidth *. defaultMarginMultiplier;
        let marginY =
          (viewBoxHeight -. (viewBoxWidth -. marginX *. 2.) *. height /. width)
          /. 2.;
        (marginX, marginY);
      } else {
        let marginY = viewBoxHeight *. defaultMarginMultiplier;
        let marginX =
          (viewBoxWidth -. (viewBoxHeight -. marginY *. 2.) *. width /. height)
          /. 2.;
        (marginX, marginY);
      };
    let normalizeX = x =>
      if (width == 0.) {
        viewBoxMinX +. viewBoxWidth /. 2.;
      } else {
        viewBoxMinX
        +. marginX
        +. (x -. minX)
        *. (viewBoxWidth -. marginX *. 2.)
        /. width;
      };
    let normalizeY = y =>
      if (height == 0.) {
        viewBoxMinY +. viewBoxHeight /. 2.;
      } else {
        viewBoxMinY
        +. marginY
        +. (y -. minY)
        *. (viewBoxHeight -. marginY *. 2.)
        /. height;
      };
    let normalizePosition = (position: Model.position) =>
      Model.{x: normalizeX(position.x), y: normalizeY(position.y)};
    let normalizeStarPosition = (star: Model.star) => {
      ...star,
      position: normalizePosition(star.position),
    };
    List.map(normalizeStarPosition, stars);
  };

let make = (~sky: Model.sky, _children) => {
  ...component,
  initialState: () => {
    let stars = normalizeStarPositions(sky.stars);
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
               Option.filter((==)(star.id), self.state.focusedStarId)
               |> Option.map(Functions.always(5.))
               |> Option.withDefault(4.)
             }
             onEnter={() => self.send(EnterStar(star.id))}
             onLeave={() => self.send(LeaveStar(star.id))}
           />
         )
      |> Array.of_list;
    let currentEdges =
      self.state.currentEdges
      |> List.map(Model.findStars(self.state.stars))
      |> List.map(Option.map(Functions.uncurry(renderConstellationEdge)))
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