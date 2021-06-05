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
  Meter: "Milimetre",
  Milimetre: "Centimeter",
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
    if (selectId.value === "1") {
      convertingMass(input1, input2, select1, select2);
    } else if (selectId.value === "2") {
      //TODO
      //convertingArea(input1, input2, select1, select2);
    } else {
      //TODO
      //convertingLength(input1, input2, select1, select2);
    }
  });

  select1.addEventListener("change", function () {
    Converting(input1, input2, select1, select2);
  });

  select2.addEventListener("change", function () {
    Converting(input1, input2, select1, select2);
  });

  swap.addEventListener("click", function(){
    let tmp = input1.value;
    input1.value = input2.value;
    input2.value = tmp;
  
    tmp = select1.value;
    select1.value = select2.value;
    select2.value = tmp;
  });
  Converting(input1, input2, select1, select2);
}

function convertingMass(input1, input2, select1, select2) {
  if (select1.value === "Kilogram" && select2.value === "Gram") {
    input2.value = kgToG(input1.value);
  } else if (select1.value === "Kilogram" && select2.value === "Tonne") {
    input2.value = kgToTonne(input1.value);
  } else if (select1.value === "Tonne" && select2.value === "Gram") {
    input2.value = tonneToG(input1.value);
  } else if (select1.value === "Tonne" && select2.value === "Kilogram") {
    input2.value = tonneToKg(input1.value);
  } else if (select1.value === "Gram" && select2.value === "Kilogram") {
    input2.value = gToKg(input1.value);
  } else if (select1.value === "Gram" && select2.value === "Tonne") {
    input2.value = gToTonne(input1.value);
  } else {
    // kgToKg or gToG or tonneToTonne
    input2.value = input1.value;
  }
}

function kgToG(value) {
  if (value > 0) {
    return value * 1000;
  } else {
    return "";
  }
}

function kgToTonne(value) {
  if (value > 0) {
    return value / 1000;
  } else {
    return "";
  }
}

function tonneToG(value) {
  if (value > 0) {
    return value * 1000000;
  } else {
    return "";
  }
}

function tonneToKg(value) {
  if (value > 0) {
    return value * 1000;
  } else {
    return "";
  }
}

function gToKg(value) {
  if (value > 0) {
    return value / 1000;
  } else {
    return "";
  }
}

function gToTonne(value) {
  if (value > 0) {
    return value / 1000000;
  } else {
    return "";
  }
}
