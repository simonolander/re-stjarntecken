let theLover = () => {
  let stars: list(Model.star) = [
    {
      id: 1,
      size: 1.,
      position: {
        x: 245.,
        y: 159.,
      },
    },
    {
      id: 2,
      size: 1.,
      position: {
        x: 212.,
        y: 187.,
      },
    },
    {
      id: 3,
      size: 1.,
      position: {
        x: 183.,
        y: 165.,
      },
    },
    {
      id: 4,
      size: 1.,
      position: {
        x: 195.,
        y: 103.,
      },
    },
    {
      id: 5,
      size: 0.4,
      position: {
        x: 226.,
        y: 82.,
      },
    },
    {
      id: 6,
      size: 1.,
      position: {
        x: 301.,
        y: 86.,
      },
    },
    {
      id: 7,
      size: 0.4,
      position: {
        x: 323.,
        y: 139.,
      },
    },
    {
      id: 8,
      size: 1.,
      position: {
        x: 299.,
        y: 167.,
      },
    },
    {
      id: 9,
      size: 0.4,
      position: {
        x: 312.,
        y: 218.,
      },
    },
    {
      id: 10,
      size: 1.,
      position: {
        x: 280.,
        y: 214.,
      },
    },
    {
      id: 11,
      size: 1.,
      position: {
        x: 275.,
        y: 334.,
      },
    },
    {
      id: 12,
      size: 1.,
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
      size: 1.,
      position: {
        x: 16.,
        y: 25.,
      },
    },
    {
      id: 2,
      size: 1.,
      position: {
        x: 31.,
        y: 23.,
      },
    },
    {
      id: 3,
      size: 1.,
      position: {
        x: 45.,
        y: 31.,
      },
    },
    {
      id: 4,
      size: 1.,
      position: {
        x: 48.,
        y: 50.,
      },
    },
    {
      id: 5,
      size: 1.,
      position: {
        x: 70.,
        y: 52.,
      },
    },
    {
      id: 6,
      size: 1.,
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