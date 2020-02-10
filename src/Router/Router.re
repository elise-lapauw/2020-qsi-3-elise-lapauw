[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";

let goToGreeting= _ => {
  ReasonReactRouter.push("/greetings")
}
let goTo404 = _ => {
  ReasonReactRouter.push("/error")
}
let goTo = () => {
  let urlok = ReasonReactRouter.useUrl();
    switch (urlok.path) {
      | ["greetings"] => goToGreeting()
      | _ => goTo404()
    };
};


[@react.component]
let make = () => { 
  let (goTo) = React.useCallback0() => {};
   
  <div onClick={_ => goTo("greeting")}> Greeting </div>;
};
