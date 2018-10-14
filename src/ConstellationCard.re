let component = ReasonReact.statelessComponent("ConstellationCard");

let viewBox = Model.{x: 0., y: 0., width: 100., height: 100.};

let make =
    (
      ~constellation: Model.constellation,
      ~stars: list(Model.star),
      _children,
    ) => {
  ...component,
  render: _self => {
    let starIds = Model.getConstellationStarIds(constellation);
    let relevantStars =
      stars
      |> List.filter((star: Model.star) => Lists.contains(star.id, starIds))
      |> Geometry.normalizeStarPositions(viewBox);
    let constellationEdgeElements =
      constellation.edges
      |> List.map(Model.findStars(relevantStars))
      |> List.map(
           Option.map(((star1, star2)) => <ConstellationEdge star1 star2 />),
         )
      |> Option.flattenList
      |> Array.of_list;
    let starElements =
      relevantStars
      |> List.map((star: Model.star) => <Star position={star.position} />)
      |> Array.of_list;
    let elements = Array.concat([constellationEdgeElements, starElements]);
    <div className="card">
      <div className="card-content">
        <svg
          style={ReactDOMRe.Style.make(~backgroundColor="black", ())}
          viewBox={Geometry.viewBoxString(viewBox)}>
          ...elements
        </svg>
      </div>
    </div>;
  },
};