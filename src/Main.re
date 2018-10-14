let component = ReasonReact.statelessComponent("Main");

let printSky = (sky: Model.sky) => {
  Js.log(sky);
}

let make = _children => {
  ...component,
  render: _self => {
    let sky = Util.random(30);
    let constellations = sky.constellations;
    let stars = sky.stars;
    Js.log(sky);
    <div className="columns full-height">
      <div className="column"> <Sky sky /> </div>
      <Sidebar constellations stars />
    </div>;
  },
};