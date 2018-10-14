type position = {
  x: float,
  y: float,
};

let distance = (p1: position, p2: position) => {
  let dx = p2.x -. p1.x;
  let dy = p2.y -. p1.y;
  sqrt(dx *. dx +. dy *. dy);
};

type rectangle = {
  x: float,
  y: float,
  width: float,
  height: float,
};

type starId = int;

type star = {
  id: starId,
  size: float,
  position,
};

let getStarId = star => star.id;

let getStarPosition = star => star.position;

type constellationEdge = (starId, starId);

module ConstellationEdgeComparable =
  Belt.Id.MakeComparable({
    type t = constellationEdge;
    let cmp = ((id1, id2), (id3, id4)) =>
      if (id1 == id3) {
        Pervasives.compare(id2, id4);
      } else {
        Pervasives.compare(id1, id3);
      };
  });

let constellationEdgeSet = Belt.Set.make(~id=(module ConstellationEdgeComparable));

let getConstellationEdgeStarIds = edge => [fst(edge), snd(edge)];

type constellation = {
  edges: list(constellationEdge),
  name: string,
  found: bool,
};

let constellationIsFound = constellation => constellation.found;

let getConstellationEdges = constellation => constellation.edges;

let getConstellationStarIds = constellation =>
  constellation.edges
  |> Lists.flatMap(getConstellationEdgeStarIds)
  |> Lists.distinct;

let constellationContainsEdge = (edge, constellation) =>
  Lists.contains(edge, constellation.edges);

type sky = {
  stars: list(star),
  constellations: list(constellation),
};

let starHasId = (id, star) => star.id == id;

let constellationEdgeContainsStarId = (starId, constellationEdge) =>
  starId == fst(constellationEdge) || starId == snd(constellationEdge);

let constellationEdgesContainStarId = starId =>
  List.exists(constellationEdgeContainsStarId(starId));

let createEdge: (starId, starId) => option(constellationEdge) =
  (id1, id2) =>
    if (id1 == id2) {
      None;
    } else if (id1 < id2) {
      Some((id1, id2));
    } else {
      Some((id2, id1));
    };

let findStars = (stars, (id1, id2)) => {
  let star1 = Lists.find(starHasId(id1), stars);
  let star2 = Lists.find(starHasId(id2), stars);
  Option.both(star1, star2);
};