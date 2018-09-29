let contains = value => List.exists((==)(value));

let remove = value => List.filter((!=)(value));

let toggle = (value, list) =>
  if (contains(value, list)) {
    remove(value, list);
  } else {
    [value, ...list];
  };

let rec find = (func, list) =>
  switch (list) {
  | [] => None
  | [head, ...tail] =>
    if (func(head)) {
      Some(head);
    } else {
      find(func, tail);
    }
  };