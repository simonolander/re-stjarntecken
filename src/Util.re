let theLover = () => {
  let stars: list(Model.star) = [
    {
      id: 1,
      size: 4.,
      position: {
        x: 245.,
        y: 159.,
      },
    },
    {
      id: 2,
      size: 4.,
      position: {
        x: 212.,
        y: 187.,
      },
    },
    {
      id: 3,
      size: 4.,
      position: {
        x: 183.,
        y: 165.,
      },
    },
    {
      id: 4,
      size: 4.,
      position: {
        x: 195.,
        y: 103.,
      },
    },
    {
      id: 5,
      size: 3.,
      position: {
        x: 226.,
        y: 82.,
      },
    },
    {
      id: 6,
      size: 4.,
      position: {
        x: 301.,
        y: 86.,
      },
    },
    {
      id: 7,
      size: 3.,
      position: {
        x: 323.,
        y: 139.,
      },
    },
    {
      id: 8,
      size: 4.,
      position: {
        x: 299.,
        y: 167.,
      },
    },
    {
      id: 9,
      size: 3.,
      position: {
        x: 312.,
        y: 218.,
      },
    },
    {
      id: 10,
      size: 4.,
      position: {
        x: 280.,
        y: 214.,
      },
    },
    {
      id: 11,
      size: 4.,
      position: {
        x: 275.,
        y: 334.,
      },
    },
    {
      id: 12,
      size: 4.,
      position: {
        x: 212.,
        y: 287.,
      },
    },
  ];
  let constellations: list(Model.constellation) = [
    {
      name: "Karlavagnen",
      edges: [
        (1, 2),
        (2, 3),
        (3, 4),
        (4, 5),
        (5, 6),
        (6, 7),
        (7, 8),
        (8, 9),
        (9, 10),
        (10, 11),
        (11, 12),
      ],
      found: false,
    },
  ];
  let sky: Model.sky = {stars, constellations};
  sky;
};

let karlavagnen = () => {
  let stars: list(Model.star) = [
    {
      id: 1,
      size: 4.,
      position: {
        x: 16.,
        y: 25.,
      },
    },
    {
      id: 2,
      size: 4.,
      position: {
        x: 31.,
        y: 23.,
      },
    },
    {
      id: 3,
      size: 4.,
      position: {
        x: 45.,
        y: 31.,
      },
    },
    {
      id: 4,
      size: 4.,
      position: {
        x: 48.,
        y: 50.,
      },
    },
    {
      id: 5,
      size: 4.,
      position: {
        x: 70.,
        y: 52.,
      },
    },
    {
      id: 6,
      size: 4.,
      position: {
        x: 76.,
        y: 33.,
      },
    },
  ];
  let constellations: list(Model.constellation) = [
    {
      name: "Karlavagnen",
      edges: [(1, 2), (2, 3), (3, 4), (4, 5), (5, 6), (3, 6)],
      found: false,
    },
  ];
  let sky: Model.sky = {stars, constellations};
  sky;
};

let theApprentice = () => {
  let stars: list(Model.star) = [
    {
      id: 1,
      size: 4.,
      position: {
        x: 191.,
        y: 49.,
      },
    },
    {
      id: 2,
      size: 3.,
      position: {
        x: 208.,
        y: 175.,
      },
    },
    {
      id: 3,
      size: 4.,
      position: {
        x: 214.,
        y: 225.,
      },
    },
    {
      id: 4,
      size: 4.,
      position: {
        x: 247.,
        y: 333.,
      },
    },
    {
      id: 5,
      size: 4.,
      position: {
        x: 137.,
        y: 205.,
      },
    },
    {
      id: 6,
      size: 4.,
      position: {
        x: 157.,
        y: 251.,
      },
    },
    {
      id: 7,
      size: 3.,
      position: {
        x: 265.,
        y: 219.,
      },
    },
    {
      id: 8,
      size: 4.,
      position: {
        x: 343.,
        y: 201.,
      },
    },
    {
      id: 9,
      size: 4.,
      position: {
        x: 305.,
        y: 130.,
      },
    },
    {
      id: 10,
      size: 3.,
      position: {
        x: 260.,
        y: 175.,
      },
    },
    {
      id: 11,
      size: 4.,
      position: {
        x: 330.,
        y: 69.,
      },
    },
  ];
  let constellations: list(Model.constellation) = [
    {
      name: "The Apprentice",
      edges: [
        (1, 2),
        (2, 3),
        (3, 4),
        (3, 5),
        (3, 6),
        (3, 7),
        (3, 10),
        (5, 6),
        (7, 8),
        (8, 9),
        (9, 10),
        (9, 11),
      ],
      found: false,
    },
  ];
  let sky: Model.sky = {stars, constellations};
  sky;
};

let theAtronach = () => {
  let stars: list(Model.star) = [
    {
      id: 1,
      size: 4.,
      position: {
        x: 222.,
        y: 295.,
      },
    },
    {
      id: 2,
      size: 4.,
      position: {
        x: 213.,
        y: 229.,
      },
    },
    {
      id: 3,
      size: 4.,
      position: {
        x: 186.,
        y: 196.,
      },
    },
    {
      id: 4,
      size: 4.,
      position: {
        x: 185.,
        y: 120.,
      },
    },
    {
      id: 5,
      size: 4.,
      position: {
        x: 208.,
        y: 79.,
      },
    },
    {
      id: 6,
      size: 4.,
      position: {
        x: 279.,
        y: 85.,
      },
    },
    {
      id: 7,
      size: 4.,
      position: {
        x: 264.,
        y: 161.,
      },
    },
    {
      id: 8,
      size: 4.,
      position: {
        x: 283.,
        y: 294.,
      },
    },
    {
      id: 9,
      size: 4.,
      position: {
        x: 336.,
        y: 137.,
      },
    },
    {
      id: 10,
      size: 4.,
      position: {
        x: 304.,
        y: 236.,
      },
    },
  ];
  let constellations: list(Model.constellation) = [
    {
      name: "The Atronach",
      edges: [
        (1, 2),
        (2, 3),
        (2, 8),
        (3, 4),
        (4, 5),
        (5, 6),
        (6, 7),
        (6, 9),
        (7, 8),
        (9, 10),
      ],
      found: false,
    },
  ];
  let sky: Model.sky = {stars, constellations};
  sky;
};

let theLord = () => {
  let stars: list(Model.star) = [
    {
      id: 1,
      size: 4.,
      position: {
        x: 299.,
        y: 79.,
      },
    },
    {
      id: 2,
      size: 3.,
      position: {
        x: 320.,
        y: 80.,
      },
    },
    {
      id: 3,
      size: 4.,
      position: {
        x: 321.,
        y: 116.,
      },
    },
    {
      id: 4,
      size: 4.,
      position: {
        x: 317.,
        y: 165.,
      },
    },
    {
      id: 5,
      size: 4.,
      position: {
        x: 250.,
        y: 228.,
      },
    },
    {
      id: 6,
      size: 3.,
      position: {
        x: 309.,
        y: 232.,
      },
    },
    {
      id: 7,
      size: 3.,
      position: {
        x: 304.,
        y: 284.,
      },
    },
    {
      id: 8,
      size: 4.,
      position: {
        x: 292.,
        y: 317.,
      },
    },
    {
      id: 9,
      size: 4.,
      position: {
        x: 260.,
        y: 331.,
      },
    },
    {
      id: 10,
      size: 3.,
      position: {
        x: 244.,
        y: 318.,
      },
    },
    {
      id: 11,
      size: 3.,
      position: {
        x: 255.,
        y: 298.,
      },
    },
    {
      id: 12,
      size: 3.,
      position: {
        x: 291.,
        y: 126.,
      },
    },
    {
      id: 13,
      size: 3.,
      position: {
        x: 272.,
        y: 126.,
      },
    },
    {
      id: 14,
      size: 3.,
      position: {
        x: 250.,
        y: 129.,
      },
    },
    {
      id: 15,
      size: 3.,
      position: {
        x: 375.,
        y: 149.,
      },
    },
    {
      id: 16,
      size: 4.,
      position: {
        x: 332.,
        y: 236.,
      },
    },
    {
      id: 17,
      size: 4.,
      position: {
        x: 328.,
        y: 327.,
      },
    },
    {
      id: 18,
      size: 3.,
      position: {
        x: 356.,
        y: 318.,
      },
    },
    {
      id: 19,
      size: 3.,
      position: {
        x: 359.,
        y: 281.,
      },
    },
  ];
  let constellations: list(Model.constellation) = [
    {
      name: "The Lord",
      edges: [
        (1, 2),
        (2, 3),
        (3, 4),
        (3, 12),
        (3, 15),
        (4, 5),
        (5, 6),
        (6, 7),
        (6, 16),
        (7, 8),
        (8, 9),
        (8, 17),
        (9, 10),
        (10, 11),
        (12, 13),
        (13, 14),
        (17, 18),
        (18, 19),
      ],
      found: false,
    },
  ];
  let sky: Model.sky = {stars, constellations};
  sky;
};

let template = () => {
  let stars: list(Model.star) = [
    {
      id: 1,
      size: 4.,
      position: {
        x: 0.,
        y: 0.,
      },
    },
  ];
  let constellations: list(Model.constellation) = [
    {
      name: "Template",
      edges: [
        (1, 2),
        (2, 3),
        (3, 4),
        (3, 5),
        (3, 6),
        (3, 7),
        (3, 10),
        (5, 6),
        (7, 8),
        (8, 9),
        (9, 10),
        (9, 11),
      ],
      found: false,
    },
  ];
  let sky: Model.sky = {stars, constellations};
  sky;
};

let rec spanningTree =
        (
          all: list(Model.star),
          inside: list(Model.star),
          outside: list(Model.star),
          edges: list(Model.constellationEdge),
        ) =>
  switch (outside) {
  | [] => edges
  | [head, ...tail] =>
    let edge =
      Lists.randomElement(inside)
      |> Option.map((star: Model.star) => star.id)
      |> Option.flatMap(Model.createEdge(head.id));
    switch (edge) {
    | None => edges
    | Some(e) => spanningTree(all, [head, ...inside], tail, [e, ...edges])
    };
  };

let minimumSpanningTree = (starList: list(Model.star)) => {
  let stars = Array.of_list(starList);
  let rec minimumSpanningTreeRec =
          (
            inside: Belt.Set.Int.t,
            outside: Belt.Set.Int.t,
            edges: list(Model.constellationEdge),
            closenesses: array((int, float)),
          ) => {
    let getDistance = (i1, i2) =>
      Option.map2(
        Model.distance,
        Belt.Array.get(stars, i1) |> Option.map(Model.getStarPosition),
        Belt.Array.get(stars, i2) |> Option.map(Model.getStarPosition),
      );
    let keepClosest = (opt1, i2) =>
      switch (opt1) {
      | Some(i1) =>
        switch (
          Belt.Array.get(closenesses, i1),
          Belt.Array.get(closenesses, i2),
        ) {
        | (Some((_, c1)), Some((_, c2))) =>
          if (c1 < c2) {
            Some(i1);
          } else {
            Some(i2);
          }
        | (Some(_), None) => Some(i1)
        | (None, Some(_)) => Some(i2)
        | (None, None) => None
        }
      | None => Some(i2)
      };
    let optClosest = Belt.Set.Int.reduce(outside, None, keepClosest);
    switch (optClosest) {
    | Some(closestIndex) =>
      switch (Belt.Array.get(closenesses, closestIndex)) {
      | Some((parentIndex, _distance)) =>
        let newInside = Belt.Set.Int.add(inside, closestIndex);
        let newOutside = Belt.Set.Int.remove(outside, closestIndex);
        let starId1 =
          Belt.Array.get(stars, closestIndex) |> Option.map(Model.getStarId);
        let starId2 =
          Belt.Array.get(stars, parentIndex) |> Option.map(Model.getStarId);
        let edge = Option.flatMap2(Model.createEdge, starId1, starId2);
        let newEdges = Option.prepend(edges, edge);
        let newClosenesses =
          closenesses
          |> Array.mapi((index, (i, d)) =>
               if (index == closestIndex) {
                 (i, 0.);
               } else {
                 switch (getDistance(index, closestIndex)) {
                 | Some(distance) =>
                   if (distance < d) {
                     (closestIndex, distance);
                   } else {
                     (i, d);
                   }
                 | None => (i, d)
                 };
               }
             );
        minimumSpanningTreeRec(
          newInside,
          newOutside,
          newEdges,
          newClosenesses,
        );
      | None => edges
      }
    | None => edges
    };
  };
  switch (starList) {
  | [] => []
  | [head, ..._] =>
    let inside = Belt.Set.Int.empty->Belt.Set.Int.add(0);
    let outside =
      Belt.Set.Int.fromArray(Array.mapi((index, _) => index, stars))
      ->Belt.Set.Int.remove(0);
    let edges = [];
    let closenesses =
      stars
      |> Array.map(star =>
           if (star == head) {
             (0, 0.);
           } else {
             (0, Model.distance(head.position, star.position));
           }
         );
    minimumSpanningTreeRec(inside, outside, edges, closenesses);
  };
};

let addSomeRandomEdges =
    (stars: list(Model.star), edges: list(Model.constellationEdge)) => {
  let starArray = Array.of_list(stars);
  let rec f = (remainingTries, remainingEdges, edges) =>
    if (remainingTries == 0 || remainingEdges == 0) {
      edges;
    } else {
      switch (Arrays.pickDifferent2(starArray)) {
      | None => edges
      | Some((star1, star2)) =>
        switch (Model.createEdge(star1.id, star2.id)) {
        | None => f(remainingTries - 1, remainingEdges, edges)
        | Some(edge) =>
          if (Belt.Set.has(edges, edge)) {
            f(remainingTries - 1, remainingEdges, edges);
          } else {
            let edgeIntersects = (edge: Model.constellationEdge) =>
              switch (Model.findStars(stars, edge)) {
              | None => false
              | Some((star3, star4)) =>
                Geometry.lineSegmentsIntersect(
                  star1.position,
                  star2.position,
                  star3.position,
                  star4.position,
                )
              };
            let starIsTooClose = (star: Model.star) =>
              star != star1
              && star != star2
              && Geometry.pointLineSegmentDistance(
                   star.position,
                   star1.position,
                   star2.position,
                 )
              < star.size
              *. 2.;
            if (List.exists(starIsTooClose, stars)
                || Belt.Set.some(edges, edgeIntersects)) {
              f(remainingTries - 1, remainingEdges, edges);
            } else {
              f(
                remainingTries - 1,
                remainingEdges - 1,
                Belt.Set.add(edges, edge),
              );
            };
          }
        }
      };
    };
  f(
    List.length(stars) * List.length(stars),
    List.length(stars) / 6,
    Belt.Set.fromArray(
      Array.of_list(edges),
      ~id=(module Model.ConstellationEdgeComparable),
    ),
  )
  |> Belt.Set.toList;
};

let random = (numberOfStars: int) => {
  let width = 50. +. Random.float(50.);
  let height = 50. +. Random.float(50.);
  let randomPosition = () =>
    Model.{x: Random.float(width), y: Random.float(height)};
  let removeIfTooClose = list => {
    let rec f = (remaining: list(Model.star), kept) =>
      switch (remaining) {
      | [] => kept
      | [head, ...tail] =>
        let tooClose =
          List.exists(
            (k: Model.star) =>
              Model.distance(head.position, k.position) < head.size +. k.size,
            kept,
          );
        if (tooClose) {
          f(tail, kept);
        } else {
          f(tail, [head, ...kept]);
        };
      };
    f(list, []);
  };
  let stars =
    Lists.init(numberOfStars, id =>
      Model.{id, position: randomPosition(), size: Random.float(1.) +. 2.}
    )
    |> removeIfTooClose;
  let edges = minimumSpanningTree(stars) |> addSomeRandomEdges(stars);
  let constellations: list(Model.constellation) = [
    {name: "Random", edges, found: false},
  ];
  let sky: Model.sky = {stars, constellations};
  sky;
};