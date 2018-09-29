let curry = (func, a, b) => func((a, b));

let uncurry = (func, (a, b)) => func(a, b);

let flip = (func, a, b) => func(b, a);

let compose = (f1, f2, value) => f1(f2(value));