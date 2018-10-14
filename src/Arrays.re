let pickDifferent2 = array =>
  switch (Array.length(array)) {
  | 0 => None
  | 1 => None
  | 2 => Option.both(Belt.Array.get(array, 0), Belt.Array.get(array, 1))
  | length =>
    let i1 = Random.int(length);
    let i2 = {
      let itemp = Random.int(length - 1);
      if (itemp >= i1) {
        itemp + 1;
      } else {
        itemp;
      };
    };
    Option.both(Belt.Array.get(array, i1), Belt.Array.get(array, i2));
  };