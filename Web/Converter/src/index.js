import _ from "lodash";

const measurements = require("./measurements.json");

let input = document.getElementById("input");
let result = document.getElementById("result");
let inputType = document.getElementById("inputType");
let resultType = document.getElementById("resultType");
let measureType = document.getElementById("measureType");

input.addEventListener("keyup", converter);
measureType.addEventListener("click", options_input_result);
inputType.addEventListener("change", converter);
resultType.addEventListener("change", converter);

let data = Object.keys(measurements);
function options_measureType() {
  console.log("--- data: ", data);
  for (let i = 0; i < data.length; i++) {
    let options = document.createElement("option");
    options.value = data[i];
    options.text = data[i];
    measureType.appendChild(options);
  }
}

function options_input_result() {
  console.log("begin......");
  let object_name = measureType.value;
  let data_input = Object.keys(measurements[object_name]);
  console.log(data_input);
  console.log(data_input.length);
  for (let i = 0; i < data_input.length; i++) {
    console.log(data_input[i]);
    let option1 = document.createElement("option");
    option1.value = data_input[i];
    option1.text = data_input[i];
    inputType.appendChild(option1);
    let option2 = document.createElement("option");
    option2.value = data_input[i];
    option2.text = data_input[i];
    resultType.appendChild(option2);
  }
}

options_measureType();
function converter() {
  result.value =
    (input.value * measurements[measureType.value][inputType.value]) /
    measurements[measureType.value][resultType.value];
  return result.value;
}
