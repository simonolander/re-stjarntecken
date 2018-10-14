let normalizeStarPositions =
    (viewBox: Model.rectangle, stars: list(Model.star)) =>
  switch (stars) {
  | [] => []
  | [head, ...tail] =>
    let xs = List.map((star: Model.star) => star.position.x, tail);
    let ys = List.map((star: Model.star) => star.position.y, tail);
    let minX = List.fold_left(min, head.position.x, xs);
    let minY = List.fold_left(min, head.position.y, ys);
    let maxX = List.fold_left(max, head.position.x, xs);
    let maxY = List.fold_left(max, head.position.y, ys);
    let width = maxX -. minX;
    let height = maxY -. minY;
    let defaultMarginMultiplier = 0.05;
    let (marginX, marginY) =
      if (width == 0. || height == 0.) {
        (
          viewBox.width *. defaultMarginMultiplier,
          viewBox.height *. defaultMarginMultiplier,
        );
      } else if (width > height) {
        let marginX = viewBox.width *. defaultMarginMultiplier;
        let marginY =
          (
            viewBox.height
            -. (viewBox.width -. marginX *. 2.)
            *. height
            /. width
          )
          /. 2.;
        (marginX, marginY);
      } else {
        let marginY = viewBox.height *. defaultMarginMultiplier;
        let marginX =
          (
            viewBox.width
            -. (viewBox.height -. marginY *. 2.)
            *. width
            /. height
          )
          /. 2.;
        (marginX, marginY);
      };
    let normalizeX = x =>
      if (width == 0.) {
        viewBox.x +. viewBox.width /. 2.;
      } else {
        viewBox.x
        +. marginX
        +. (x -. minX)
        *. (viewBox.width -. marginX *. 2.)
        /. width;
      };
    let normalizeY = y =>
      if (height == 0.) {
        viewBox.y +. viewBox.height /. 2.;
      } else {
        viewBox.y
        +. marginY
        +. (y -. minY)
        *. (viewBox.height -. marginY *. 2.)
        /. height;
      };
    let normalizePosition = (position: Model.position) =>
      Model.{x: normalizeX(position.x), y: normalizeY(position.y)};
    let normalizeStarPosition = (star: Model.star) => {
      ...star,
      position: normalizePosition(star.position),
    };
    List.map(normalizeStarPosition, stars);
  };

let equalsEpsilon = (~epsilon=0.00001, f1, f2) =>
  abs_float(f1 -. f2) < epsilon;

let lineLineIntersection =
    (
      ~includeEndpoints=false,
      ~epsilon=0.00001,
      l1p1: Model.position,
      l1p2: Model.position,
      l2p1: Model.position,
      l2p2: Model.position,
    ) => {
  let s1x = l1p2.x -. l1p1.x;
  let s1y = l1p2.y -. l1p1.y;
  let s2x = l2p2.x -. l2p1.x;
  let s2y = l2p2.y -. l2p1.y;
  let denum = -. s2x *. s1y +. s1x *. s2y;
  let s = (-. s1y *. (l1p1.x -. l2p1.x) +. s1x *. (l1p1.y -. l2p1.y)) /. denum;
  let t = (s2x *. (l1p1.y -. l2p1.y) -. s2y *. (l1p1.x -. l2p1.x)) /. denum;
  if (s > 0.
      && s < 1.
      && t > 0.
      && t < 1.
      || includeEndpoints
      && (
        equalsEpsilon(s, 0., ~epsilon)
        || equalsEpsilon(s, 1., ~epsilon)
        || equalsEpsilon(t, 0., ~epsilon)
        || equalsEpsilon(t, 1., ~epsilon)
      )) {
    Some(Model.{x: l1p1.x +. t *. s1x, y: l1p1.y +. t *. s1y});
  } else {
    None;
  };
};

let lineSegmentsIntersect =
    (
      ~includeEndpoints=false,
      ~epsilon=0.00001,
      l1p1: Model.position,
      l1p2: Model.position,
      l2p1: Model.position,
      l2p2: Model.position,
    ) =>
  Belt.Option.isSome(
    lineLineIntersection(~includeEndpoints, ~epsilon, l1p1, l1p2, l2p1, l2p2),
  );

let dot = (p1: Model.position, p2: Model.position) =>
  p1.x *. p2.x +. p1.y *. p2.y;

let projectPointOnLine =
    (point: Model.position, l1p1: Model.position, l1p2: Model.position) =>
  if (l1p1 == l1p2) {
    l1p1;
  } else {
    let ax = point.x -. l1p1.x;
    let ay = point.y -. l1p1.y;
    let bx = l1p2.x -. l1p1.x;
    let by = l1p2.y -. l1p1.y;
    let r = (ax *. bx +. ay *. by) /. (bx *. bx +. by *. by);
    Model.{x: l1p1.x +. bx *. r, y: l1p1.y +. by *. r};
  };

let closestPointOnLineSegment =
    (point: Model.position, l1p1: Model.position, l1p2: Model.position) =>
  if (l1p1 == point) {
    l1p1;
  } else if (l1p2 == point) {
    l1p2;
  } else if (l1p1 == l1p2) {
    l1p1;
  } else {
    let projection = projectPointOnLine(point, l1p1, l1p2);
    let dProjection = Model.distance(point, projection);
    let dp1 = Model.distance(point, l1p1);
    let dp2 = Model.distance(point, l1p2);
    if (dp1 < dp2) {
      if (dProjection < dp1) {
        projection;
      } else {
        l1p1;
      };
    } else if (dProjection < dp2) {
      projection;
    } else {
      l1p2;
    };
  };

let pointLineSegmentDistance =
    (point: Model.position, l1p1: Model.position, l1p2: Model.position) =>
  Model.distance(closestPointOnLineSegment(point, l1p1, l1p2), point);

let viewBoxString = (rectangle: Model.rectangle) =>
  Strings.ofFloat(rectangle.x)
  ++ " "
  ++ Strings.ofFloat(rectangle.y)
  ++ " "
  ++ Strings.ofFloat(rectangle.width)
  ++ " "
  ++ Strings.ofFloat(rectangle.height);