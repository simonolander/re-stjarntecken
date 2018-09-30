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
      size: 0.7,
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
      size: 0.7,
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
      size: 0.7,
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

let theApprentice = () => {
  let stars: list(Model.star) = [
    {
      id: 1,
      size: 1.,
      position: {
        x: 191.,
        y: 49.,
      },
    },
    {
      id: 2,
      size: 0.7,
      position: {
        x: 208.,
        y: 175.,
      },
    },
    {
      id: 3,
      size: 1.,
      position: {
        x: 214.,
        y: 225.,
      },
    },
    {
      id: 4,
      size: 1.,
      position: {
        x: 247.,
        y: 333.,
      },
    },
    {
      id: 5,
      size: 1.,
      position: {
        x: 137.,
        y: 205.,
      },
    },
    {
      id: 6,
      size: 1.,
      position: {
        x: 157.,
        y: 251.,
      },
    },
    {
      id: 7,
      size: 0.7,
      position: {
        x: 265.,
        y: 219.,
      },
    },
    {
      id: 8,
      size: 1.,
      position: {
        x: 343.,
        y: 201.,
      },
    },
    {
      id: 9,
      size: 1.,
      position: {
        x: 305.,
        y: 130.,
      },
    },
    {
      id: 10,
      size: 0.7,
      position: {
        x: 260.,
        y: 175.,
      },
    },
    {
      id: 11,
      size: 1.,
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