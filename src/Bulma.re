let component = ReasonReact.statelessComponent("Bulma");

let make = _children => {
  ...component,
  render: _self =>
    <section className="section">
    <div className="container">
      <h1 className="title">
        (ReasonReact.string("Hello World"))
      </h1>
      <p className="subtitle">
        (ReasonReact.string("My first website with "))
        <strong>(ReasonReact.string("Bulma"))</strong>
        (ReasonReact.string("!"))
      </p>
    </div>
  </section>,
};