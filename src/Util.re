let karlavagnen = () => {
  let stars: list(Model.star) = [
    {
      id: 1,
      position: {
        x: 16.,
        y: 25.,
      },
    },
    {
      id: 2,
      position: {
        x: 31.,
        y: 23.,
      },
    },
    {
      id: 3,
      position: {
        x: 45.,
        y: 31.,
      },
    },
    {
      id: 4,
      position: {
        x: 48.,
        y: 50.,
      },
    },
    {
      id: 5,
      position: {
        x: 70.,
        y: 52.,
      },
    },
    {
      id: 6,
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