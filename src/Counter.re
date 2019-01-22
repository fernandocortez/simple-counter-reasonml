type action =
  | Increment
  | Decrement;

type state = int;

let component = ReasonReact.reducerComponent("Counter");

let make = _children => {
    ...component,
    initialState: () => 0,
    reducer: (action, state) =>
        switch (action) {
        | Increment => ReasonReact.Update(state + 1)
        | Decrement => ReasonReact.Update(state - 1)
        },
    render: ({send, state}) =>
        ([@JSX] [
            <button onClick=(_event => send(Increment))>
                {ReasonReact.string("+")}
            </button>,
            <strong>{ReasonReact.string(string_of_int(state))}</strong>,
            <button onClick=(_event => send(Decrement))>
                {ReasonReact.string("-")}
            </button>
        ])
};
