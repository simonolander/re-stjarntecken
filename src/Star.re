let component = ReasonReact.statelessComponent("Star");

let make =
    (~position: Model.position, ~radius: float, ~onEnter, ~onLeave, _children) => {
  ...component,
  render: _self => {
    let cx = Strings.ofFloat(position.x);
    let cy = Strings.ofFloat(position.y);
    let r = Strings.ofFloat(radius);
    let innerRadius = Strings.ofFloat(radius /. 3.);
    <g onMouseEnter={_ => onEnter()} onMouseLeave={_ => onLeave()}>
      <circle className="star-hover" cx cy r />
      <circle cx cy r=innerRadius fill="white" />
    </g>;
  },
};