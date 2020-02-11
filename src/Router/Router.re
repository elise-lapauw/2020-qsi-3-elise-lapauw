[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";

let goTo404 = _ => {
  ReasonReactRouter.push("/error")
}

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

 
[@react.component]
let make = () => {
    let url = ReasonReactRouter.useUrl();
    let content = switch (url.path) {
        |["blinking-greeting"] =><BlinkingGreeting> {React.string("Hello !")} </BlinkingGreeting>
        |["fetched-dog"] => <FetchedDogPictures />
        |["random-dog"] => <FetchRandomDog />
        |["greetings"] => <Greeting />
        |["reducer"] => <ReducerFromReactJSDocs />
        | _ =>  {React.string("This URL doesn't exist")}
  };
<>
  <div>
  <div onClick={_ => goToBlinkingGreeting()}> {React.string("Blinking greetings")} </div>
  <br/>
  <div onClick={_ => goToFetched()}> {React.string("Fetched dog")} </div>
  <br/>
  <div onClick={_ => goToRandom()}> {React.string("Random dog")} </div>
  <br/>
  <div onClick={_ => goToGreetings()}> {React.string("Greetings")} </div>
  <br/>
  <div onClick={_ => goToReducer()}> {React.string("Reducer")} </div>
  <br/>
  </div>
  <br/>
  <br/>
{content}
</>
};