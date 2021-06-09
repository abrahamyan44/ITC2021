let input = document.getElementById('input');
let result = document.getElementById('result');
let inputType = document.getElementById('inputType');
let resultType = document.getElementById('resultType');
let measureType = document.getElementById('measureType')

input.addEventListener('keyup', converter);
inputType.addEventListener('change', converter);
resultType.addEventListener('change', converter);

const measurements = require('./measurements.json')

function converter() {
    let inputType = inputType.value;
    alert(inputType);
    result.value = input.value * measurements[measureType.value][inputType.value] / measurements[measureType.value][resultType.value];
}