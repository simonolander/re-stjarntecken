let component = ReasonReact.statelessComponent("Star");

let hoverFillFocused = "rgba(78, 82, 153, 0.5)";

let hoverFillUnfocused = "transparent";

let make =
    (
      ~position: Model.position,
      ~radius: float=1.,
      ~focused: bool=false,
      ~active: bool=false,
      ~entered: bool=false,
      ~onEnter=() => (),
      ~onLeave=() => (),
      _children,
    ) => {
  ...component,
  render: _self => {
    let cx = Strings.ofFloat(position.x);
    let cy = Strings.ofFloat(position.y);
    let r = Strings.ofFloat(radius);
    let innerRadius = Strings.ofFloat(radius /. 3.);
    let outerFill =
      switch (active, focused, entered) {
      | (true, true, _) => "#7f85fd80"
      | (true, false, true) => "#4e529980"
      | _ => "transparent"
      };
    <g onMouseEnter={_ => onEnter()} onMouseLeave={_ => onLeave()}>
      <circle fill=outerFill cx cy r />
      <circle cx cy r=innerRadius fill="white" />
    </g>;
  },
};