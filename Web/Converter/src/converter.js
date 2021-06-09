//import _ from "lodash";

const data = require("./converter.json");
const selectId = document.querySelector("#select-id");
const tables = document.querySelector(".tables");

const objOfMass = { Kilogram: "Gram", Tonne: "Kilogram", Gram: "Tonne" };
const objOfArea = {
  "Square Kilometre": "Square Mile",
  "Square Meter": "Square Kilometre",
  "Square Mile": "Square Meter",
};
const objofLength = {
  Centimeter: "Meter",
  Meter: "Kilometre",
  Kilometre: "Centimeter",
};

selectId.addEventListener("change", function (evt) {
  const value = evt.target.value;
  if (value === "1") {
    CreateTables(objOfMass);
  } else if (value === "2") {
    CreateTables(objOfArea);
  } else if (value === "3") {
    CreateTables(objofLength);
  } else {
    tables.innerHTML = "";
  }
});

function CreateTables(obj) {
  tables.innerHTML = "";
  const div1 = document.createElement("div");
  const div2 = document.createElement("div");
  const select1 = document.createElement("select");
  const select2 = document.createElement("select");
  const input1 = document.createElement("input");
  const input2 = document.createElement("input");
  const swap = document.createElement("div");

  div1.className = "div-1";
  div2.className = "div-2";
  input1.className = "first-input";
  input2.className = "second-input";
  select1.className = "first-select";
  select2.className = "second-select";
  swap.className = "swap";

  //initialisation
  for (let key in obj) {
    const option = document.createElement("option");
    option.value = key;
    option.text = key;
    select1.appendChild(option);
  }

  Object.values(obj).forEach(function (val) {
    const option = document.createElement("option");
    option.value = val;
    option.text = val;
    select2.appendChild(option);
  });

  div1.appendChild(input1);
  div2.appendChild(input2);
  div1.appendChild(select1);
  div2.appendChild(select2);
  tables.appendChild(div1);
  tables.appendChild(swap);
  tables.appendChild(div2);

  Converting(input1, input2, select1, select2, swap);
}

function Converting(input1, input2, select1, select2, swap) {
  input2.value = "";
  input1.value = "";

  input1.addEventListener("input", function () {
    input2.value =
      (input1.value * data[selectId.value][select1.value]) /
      data[selectId.value][select2.value];
  });

  select1.addEventListener("change", function () {
    Converting(input1, input2, select1, select2);
  });

  select2.addEventListener("change", function () {
    Converting(input1, input2, select1, select2);
  });

  swap.addEventListener("click", function () {
    let tmp = input1.value;
    input1.value = input2.value;
    input2.value = tmp;

    tmp = select1.value;
    select1.value = select2.value;
    select2.value = tmp;
  });
  Converting(input1, input2, select1, select2);
}