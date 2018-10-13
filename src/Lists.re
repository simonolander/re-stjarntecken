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

let rec nth = (list, n) =>
  switch (list) {
  | [] => None
  | [head, ...tail] =>
    if (n == 0) {
      Some(head);
    } else {
      nth(tail, n - 1);
    }
  };

let randomElement = list =>
  switch (list) {
  | [] => None
  | [head] => Some(head)
  | [_head, ..._tail] => nth(list, Random.int(List.length(list)))
  };

let rec range = (fromInclusive, toInclusive) =>
  if (fromInclusive > toInclusive) {
    [];
  } else {
    [fromInclusive, ...range(fromInclusive + 1, toInclusive)];
  };

let init = (size, func) => range(0, size - 1) |> List.map(func);

let flatMap = (func, list) => List.map(func, list) |> List.flatten;

let rec distinct = list =>
  switch (list) {
  | [] => []
  | [head, ...tail] => [head, ...distinct(remove(head, tail))]
  };