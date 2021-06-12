const selectId = document.querySelector("#select-id");
const table = document.querySelector(".table");
const measurements = {
    "massa": {
        "kilogram": 1,
        "gram": 0.001,
        "tonne": 1000,
    },
    "distance": {
        "m": 1,
        "sm": 0.01,
        "mm": 0.001,
        "km": 1000
    }
}
const options = {
    1: 'massa',
    2: 'distance'
}

selectId.addEventListener("change", function (event) {
    const value = event.target.value;
    if (value === "1") {
        CreateTable(measurements["massa"]);
    } else if (value === "2") {
        CreateTable(measurements["distance"]);
    } else {
        table.innerHTML = "";
    }
});

function CreateTable(obj) {
    table.innerHTML = "";
    const div1 = document.createElement("div");
    const div2 = document.createElement("div");
    const select1 = document.createElement("select");
    const select2 = document.createElement("select");
    const input1 = document.createElement("input");
    const input2 = document.createElement("input");
    const swap = document.createElement("div");

    div1.className = "div1";
    div2.className = "div2";
    input1.className = "left-input";
    input2.className = "right-input";
    select1.className = "first-select";
    select2.className = "second-select";
    swap.className = "swap";

    for (let val in obj) {
        const option = document.createElement("option");
        option.value = val;
        option.text = val;
        select1.appendChild(option);
    }
    for (let value in obj) {
        const option = document.createElement("option");
        option.value = value;
        option.text = value;
        select2.appendChild(option);
    }

    div1.appendChild(input1);
    div2.appendChild(input2);
    div1.appendChild(select1);
    div2.appendChild(select2);
    table.appendChild(div1);
    table.appendChild(swap);
    table.appendChild(div2);

    Convert(input1, input2, select1, select2, swap);
}

function Convert(input1, input2, select1, select2, swap) {
    input2.value = "";
    input1.value = "";

    input1.addEventListener("input", function () {
        Converting(input1, input2, select1, select2);
    });

    select1.addEventListener("change", function (event) {
        select1.value = event.target.value;
        Converting(input1, input2, select1, select2);
    });

    select2.addEventListener("change", function (event) {
        select2.value = event.target.value;
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
}
function Converting(input1, input2, select1, select2) {
    const measure = options[selectId.value];
    if (selectId.selectedIndex < 1) {
        return
    }
    input2.value = input1.value * measurements[measure][select1.value] / measurements[measure][select2.value];
}
