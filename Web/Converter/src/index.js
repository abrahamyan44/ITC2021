import _ from 'lodash';

const measurements = require('./measurements.json');

let input = document.getElementById('input');
let result = document.getElementById('result');
let inputType = document.getElementById('inputType');
let resultType = document.getElementById('resultType');
let measureType = document.getElementById('measureType')

input.addEventListener('keyup', converter);
inputType.addEventListener('change', converter);
resultType.addEventListener('change', converter);


function options() {
    let data = Object.keys(measurements)
    for(let i = 0; i < data.length; i++) {
        let options = document.createElement("option");
        options.value = data[i];
        options.text = data[i];
        measureType.appendChild(options);
    
        let objName = data[i];
       let arrayname = Object.keys(measurements[objName]);
            for(let j = 0; j < arrayname.length; j++) {
                let option1 = document.createElement("option");
                option1.value = arrayname[j];
                option1.text = arrayname[j];
                inputType.appendChild(option1);
                let option2 = document.createElement("option");
                option2.value = arrayname[j];
                option2.text = arrayname[j];
                resultType.appendChild(option2);
            }
    }
}

options();
function converter() {
    result.value = input.value * measurements[measureType.value][inputType.value] / measurements[measureType.value][resultType.value];
    return result.value;
}

