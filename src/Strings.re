let ofFloat = f => {
  let s = string_of_float(f);
  if (s.[String.length(s) - 1] == '.') {
    s ++ "0";
  } else {
    s;
  };
};