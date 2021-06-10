const form = document.querySelector('.formList');
const container = document.querySelector('.selectMesure');
const firstNum = document.querySelector('.firstNum');
const secondNum = document.querySelector('.secondNum');
const firstContainer = document.querySelector('.first-form-list');
const secondContainer = document.querySelector('.second-form-list');

let measurements = {
    "select": {},
    "mass": {
        "kg": 1,
        "g": 0.001,
        "mg": 0.000001,
        "t": 1000
    },
    "length": {
        "m": 1,
        "sm": 0.01,
        "mm": 0.001,
        "km": 1000
    }
}

function CreateSelect(data, containerName, className, selectClassName) {

    let Select = document.createElement('select');
    Select.className = selectClassName;

    for(let i = 0; i < data.length; i++) { 
        let option1 = document.createElement('option');
        option1.textContent = data[i];
        option1.className = className;
        Select.appendChild(option1);
        containerName.appendChild(Select);
    }

    return containerName;
}

// function Convert() {
//     let toVal = firstNum.value * measurements[measure][a.value] / measurements[measure][b.value];
//     secondNum.value = toVal;
// }

let measureData = Object.keys(measurements);
let Select = document.createElement('select');
Select.className = 'select-mesure';

for(let i = 0; i < measureData.length; i++) { 
    let option1 = document.createElement('option');
    option1.textContent = measureData[i];
    Select.appendChild(option1);
    container.appendChild(Select);
}

form.addEventListener('click', function(event) {
    firstNum.disabled = false;
    secondNum.disabled = false; 
    firstNum.placeholder = '0';
    secondNum.placeholder = '0';
    firstContainer.innerHTML = '';
    secondContainer.innerHTML = '';

    let measure = Select.value;
    let data = Object.keys(measurements[measure]);
    CreateSelect(data, firstContainer, 'first-option', 'first-select');
    CreateSelect(data, secondContainer, 'second-option', 'second-select');

    function Convert() {
        let toVal = firstNum.value * measurements[measure][a.value] / measurements[measure][b.value];
        secondNum.value = toVal;
    }

    firstContainer.addEventListener('click', function(event) {
        firstVal = event.target.value;
        Convert();
    })

    secondContainer.addEventListener('click', function(event) {
        secondtVal = event.target.value;
        Convert();
    })

    let switchButton = document.querySelector('.switch');
    let a = document.querySelector('.first-select');
    let b = document.querySelector('.second-select')

    switchButton.addEventListener('click', function(event) {
        let temp = firstNum.value;
        firstNum.value = secondNum.value;
        secondNum .value = temp;

        let tmp = a.value;
        a.value = b.value;
        b.value = tmp;
    })

    firstNum.addEventListener('input', function(event) {
        Convert();
    })

    Convert();
})