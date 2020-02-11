[@react.component]
let make = _ => {
  let atom = {js|This page doesn't exist|js};
  <div> {React.string(atom)} </div>;
};