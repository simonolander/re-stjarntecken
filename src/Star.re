let component = ReasonReact.statelessComponent("Star");

let hoverFillFocused = "rgba(78, 82, 153, 0.5)";

let hoverFillUnfocused = "transparent";

let make =
    (
      ~position: Model.position,
      ~radius: float,
      ~focused: bool,
      ~onEnter,
      ~onLeave,
      _children,
    ) => {
  ...component,
  render: _self => {
    let cx = Strings.ofFloat(position.x);
    let cy = Strings.ofFloat(position.y);
    let r = Strings.ofFloat(radius);
    let innerRadius = Strings.ofFloat(radius /. 3.);
    let className = focused ? "star-focused" : "star-hover";
    <g onMouseEnter={_ => onEnter()} onMouseLeave={_ => onLeave()}>
      <circle className cx cy r />
      <circle cx cy r=innerRadius fill="white" />
    </g>;
  },
};