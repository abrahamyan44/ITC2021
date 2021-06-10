import measurements from '../resources/measurements.json'

const values = Object.keys(measurements);
let input1 = document.getElementById('input1');
let input2 = document.getElementById('input2');
let select1 = document.getElementById("measurements1");
let select2 = document.getElementById("measurements2");

const select = document.getElementById("measurements");

for (const val of values) {
    var option = document.createElement("option");
    option.value = val;
    option.text = val
    select.appendChild(option);
}

let label = document.createElement("label");

document.getElementById("container").appendChild(label).appendChild(select);

let selectGlobalMeasurement = document.getElementById("measurements")


selectGlobalMeasurement.addEventListener('click', () => {
    let values_d1 = selectGlobalMeasurement.options[selectGlobalMeasurement.selectedIndex].text;
    input1.value = 0
    input2.value = 0;
    select1.innerHTML = ""
    for (const val of Object.keys(measurements[values_d1])) {

        let option = document.createElement("option");
        option.value = val;
        option.text = val;
        select1.appendChild(option);
    }
    let label = document.createElement("label");
    document.getElementById("container").appendChild(label).appendChild(select);
    console.log(select1.options[select1.selectedIndex].value)
})


selectGlobalMeasurement.addEventListener('click', () => {
    input1.value = 0
    input2.value = 0;
    select2.innerHTML = ""
    let values_d2 = selectGlobalMeasurement.options[selectGlobalMeasurement.selectedIndex].text;

    for (const val of Object.keys(measurements[values_d2])) {
        let option = document.createElement("option");
        option.value = val;
        option.text = val;
        select2.appendChild(option);
    }
    let label = document.createElement("label");
    document.getElementById("container").appendChild(label).appendChild(select);
})

function convert(measure, from, to) {
    const toValue = from.value * measurements[measure][from.type] / measurements[measure][to.type];
    return toValue;
}




input1.addEventListener('input', () => {
    input2.value = convert(selectGlobalMeasurement.options[selectGlobalMeasurement.selectedIndex].value,
        { value: input1.value, type: select1.options[select1.selectedIndex].value },
        { type: select2.options[select2.selectedIndex].value }
    )
})


input2.addEventListener('input', () => {
    input1.value = convert(selectGlobalMeasurement.options[selectGlobalMeasurement.selectedIndex].value,
        { value: input2.value, type: select2.options[select2.selectedIndex].value },
        { type: select1.options[select1.selectedIndex].value }
    )
})

select2.addEventListener('click', () => {
    input1.value = convert(selectGlobalMeasurement.options[selectGlobalMeasurement.selectedIndex].value,
        { value: input2.value, type: select2.options[select2.selectedIndex].value },
        { type: select1.options[select1.selectedIndex].value }
    )
})

select1.addEventListener('click', () => {
    input2.value = convert(selectGlobalMeasurement.options[selectGlobalMeasurement.selectedIndex].value,
        { value: input1.value, type: select1.options[select1.selectedIndex].value },
        { type: select2.options[select2.selectedIndex].value }
    )
})

