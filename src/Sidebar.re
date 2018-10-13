let component = ReasonReact.statelessComponent("Sidebar");

let make =
    (
      ~constellations: list(Model.constellation),
      ~stars: list(Model.star),
      _children,
    ) => {
  ...component,
  render: _self => {
    let constellationCards =
      constellations
      |> List.map(constellation => <ConstellationCard constellation stars />)
      |> Array.of_list;
    <div className="column is-one-fifth"> ...constellationCards </div>;
  },
};