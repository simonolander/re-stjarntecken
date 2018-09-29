let component = ReasonReact.statelessComponent("Star");

let make =
    (~position: Model.position, ~radius: float, ~onEnter, ~onLeave, _children) => {
  ...component,
  render: _self => {
    let cx = Util.str(position.x);
    let cy = Util.str(position.y);
    let r = Util.str(radius);
    let innerRadius = Util.str(radius /. 3.);
    <g onMouseEnter={_ => onEnter()} onMouseLeave={_ => onLeave()}>
      <circle className="star-hover" cx cy r />
      <circle cx cy r=innerRadius fill="white" />
    </g>;
  },
};