import _ from 'lodash';

const measurements = require('./measurements.json');
// let measurements = {
//     "lenght": {
//         "m": 1,
//         "sm": 0.01,
//         "mm": 0.001,
//         "km": 1000
//     },
//     "massa": {
//         "kg": 1,
//         "gr": 0.001,
//         "mg": 0.000001,
//         "tonna": 1000
//     }

// }

let input = document.getElementById('input');
let result = document.getElementById('result');
let inputType = document.getElementById('inputType');
let resultType = document.getElementById('resultType');
let measureType = document.getElementById('measureType')

input.addEventListener('keyup', converter);
inputType.addEventListener('change', converter);
resultType.addEventListener('change', converter);


function converter() {
    result.value = input.value * measurements[measureType.value][inputType.value] / measurements[measureType.value][resultType.value];
    return result.value;
}