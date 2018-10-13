let component = ReasonReact.statelessComponent("Main");

let make = _children => {
  ...component,
  render: _self =>
    <div className="columns full-height">
      <div className="column"> <Sky sky={Util.random(30)} /> </div>
      <Sidebar />
    </div>,
};