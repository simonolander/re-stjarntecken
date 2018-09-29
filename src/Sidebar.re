type state = {
  count: int,
  show: bool,
};

type action =
  | Click
  | Toggle;

let component = ReasonReact.reducerComponent("Sidebar");

let make = _children => {
  ...component,
  initialState: () => {count: 0, show: true},
  reducer: (action, state) =>
    switch (action) {
    | Click => ReasonReact.Update({...state, count: state.count + 1})
    | Toggle => ReasonReact.Update({...state, show: !state.show})
    },
  render: self => {
    let message =
      "You've clicked this " ++ string_of_int(self.state.count) ++ " times(s)";
    <div className="column is-one-fifth">
      {ReasonReact.string("sidebar")}
    </div>;
  },
};