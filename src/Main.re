let component = ReasonReact.statelessComponent("Main");

let make = _children => {
  ...component,
  render: _self =>
    <div className="columns full-height">
      <div className="column"> <Sky sky={Util.generateSky()} /> </div>
      <Sidebar />
    </div>,
};