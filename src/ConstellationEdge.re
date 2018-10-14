let component = ReasonReact.statelessComponent("ConstellationEdge");

let make =
    (
      ~star1: Model.star,
      ~star2: Model.star,
      ~stroke: string="#a0a0a0",
      _children,
    ) => {
  ...component,
  render: _self => {
    let x1 = Strings.ofFloat(star1.position.x);
    let y1 = Strings.ofFloat(star1.position.y);
    let x2 = Strings.ofFloat(star2.position.x);
    let y2 = Strings.ofFloat(star2.position.y);
    <line x1 y1 x2 y2 stroke />;
  },
};