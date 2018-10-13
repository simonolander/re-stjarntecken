let component = ReasonReact.statelessComponent("Main");

let make = _children => {
  ...component,
  render: _self => {
    let sky = Util.random(30);
    let constellations = sky.constellations;
    let stars = sky.stars;
    <div className="columns full-height">
      <div className="column"> <Sky sky /> </div>
      <Sidebar constellations stars />
    </div>;
  },
};