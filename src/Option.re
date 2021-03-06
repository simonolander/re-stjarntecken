let filter = (func, opt) =>
  switch (opt) {
  | Some(value) =>
    if (func(value)) {
      opt;
    } else {
      None;
    }
  | None => None
  };

let isPresent = opt =>
  switch (opt) {
  | Some(_) => true
  | None => false
  };

let withDefault = (default, opt) =>
  switch (opt) {
  | Some(value) => value
  | None => default
  };

let contains = (value, opt) => opt |> filter((==)(value)) |> isPresent;

let map = (func, opt) =>
  switch (opt) {
  | None => None
  | Some(value) => Some(func(value))
  };

let map2 = (func, opt1, opt2) =>
  switch (opt1, opt2) {
  | (Some(v1), Some(v2)) => Some(func(v1, v2))
  | _ => None
  };

let apply = (func, operand, opt) =>
  switch (opt) {
  | None => operand
  | Some(value) => func(value, operand)
  };

let flatten = opt =>
  switch (opt) {
  | None => None
  | Some(opt') => opt'
  };

let flatMap = (func, opt) => flatten(map(func, opt));

let flatMap2 = (func, op1, op2) => flatten(map2(func, op1, op2));

let both = (opt1, opt2) =>
  switch (opt1, opt2) {
  | (Some(v1), Some(v2)) => Some((v1, v2))
  | _ => None
  };

let rec flattenList = list =>
  switch (list) {
  | [Some(value), ...tail] => [value, ...flattenList(tail)]
  | [None, ...tail] => flattenList(tail)
  | [] => []
  };

let prepend = (list, opt) =>
  switch (opt) {
  | Some(value) => [value, ...list]
  | None => list
  };

let choose = (func, opt1, opt2) =>
  switch (opt1, opt2) {
  | (Some(v1), Some(v2)) => Some(func(v1, v2))
  | (Some(v), None) => Some(v)
  | (None, Some(v)) => Some(v)
  | (None, None) => None
  };