open ReasonUrql;
open Hooks;

type viewer = {
    login: string,
};

/* module GetQuery = [%graphql {| { viewer { login }} |};{schema: "pokedex_schema.json"}]; */
/* Create a module with your GraphQL query. */

[@react.component]
let make = _ => {
     /* let request = GetQuery.make(~login=elise-lapauw, ()); 
    let ({response}, _) = useQuery(~request, ());
  /* 
  cle github : 991221a987266f17070bd4209867a7256341bb10*/

  /* Pattern match on the response variant.
  This variant has constructors for Fetching, Data(d), Error(e), and NotFound. */
  switch (response) {
    | Fetching => <Greeting />
    | Data(d) => {
      Array.map(d =>
        <div>
          <span> {js|$d##login $d##login|js}->React.string </span>
        </div>,
        d##v
      )
    }
    | Error(e) =>
      switch (e.networkError) {
      | Some(_exn) => <div> "Network Error"->React.string </div>
      | None => <div> "Other Error"->React.string </div>
      }
    | NotFound => <div> "Something went wrong!"->React.string </div>
  } */
};