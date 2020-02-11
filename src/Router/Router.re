[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";

let goTo404 = _ => {
  ReasonReactRouter.push("/error")
}
 
let goToAtomic = () => {
  ReasonReactRouter.push("/atomic");
 
};
let goToBlinkingGreeting = () => {
  ReasonReactRouter.push("/blinking-greeting");
};

let goToFetched = () => {
  ReasonReactRouter.push("/fetched-dog");
};
let goToRandom = () => {
  ReasonReactRouter.push("/random-dog");
};

let goToGreetings = () => {
  ReasonReactRouter.push("/greetings")
}
 
let goToReducer = () => {
  ReasonReactRouter.push("/reducer");
};
let allComponent = () => {
  ReasonReactRouter.push("/random");
};
 
[@react.component]
let make = () => {
    let url = ReasonReactRouter.useUrl();
    let content = switch (url.path) {
        |["atomic"] => <Greeting />
        |["blinking-greeting"] =><BlinkingGreeting> {React.string("Hello!")} </BlinkingGreeting>
        |["fetched-dog"] => <FetchedDogPictures />
        |["random-dog"] => <FetchRandomDog />
        |["greetings"] => <Greeting />
        |["reducer"] => <ReducerFromReactJSDocs />
        | _ => <div> {React.string("Erreur 404")}</div>
  };
<>
  <div>
  <button onClick={_ => goToAtomic()}> {React.string("Atomic")} </button>
  <button onClick={_ => goToBlinkingGreeting()}> {React.string("Blinking greetings")} </button>
  <button onClick={_ => goToFetched()}> {React.string("Fetched dog")} </button>
  <button onClick={_ => goToRandom()}> {React.string("Random dog")} </button>
  <button onClick={_ => goToGreetings()}> {React.string("Greetings")} </button>
  <button onClick={_ => goToReducer()}> {React.string("Reducer")} </button>
  <button onClick={_ => ReasonReactRouter.push("/random")}> {React.string("All")} </button>
  </div>
{content}
</>