const form = document.querySelector('.formList');
const container = document.querySelector('.container');
const firstNum = document.querySelector('.firstNum');
const secondNum = document.querySelector('.secondNum');
const firstContainer = document.querySelector('.first-form-list');
const secondContainer = document.querySelector('.second-form-list');


function CreateSelect(data, containerName, className, selectClassName, selected) {

    let Select = document.createElement('select');
    Select.className = selectClassName;

    for(let i = 0; i < data.length; i++) { 
        let option1 = document.createElement('option');
        option1.value = data[i].value;
        option1.textContent = data[i].text;
        option1.className = className;

        if((selected && option1.value == 'kilometer') || (selected && option1.value == 'kilogram')) {
          option1.selected = true;
        }
        Select.appendChild(option1);
        containerName.appendChild(Select);
    }

    return containerName;
}

const lengthArray = [
    {
        value: 'meter',
        text: 'm',
    },
    {
        value: 'kilometer',
        text: 'km',
    }
] 

const massArray = [
    {
        value: 'gram',
        text: 'g'
    },
    {
        value: 'kilogram',
        text: 'kg'
    }
]

form.addEventListener('click', function(event) {
    let val;
    let firstVal;
    let secondtVal;

    firstNum.value = '';
    secondNum.value = '';
    firstNum.disabled = false;
    secondNum.disabled = false; 
    firstNum.placeholder = '0';
    secondNum.placeholder = '0';
    firstContainer.innerHTML = '';
    secondContainer.innerHTML = '';

    const el = document.querySelector('.selectMesure').value;
    console.log(el);
    if(el === 'length') {
        CreateSelect(lengthArray, firstContainer, 'first-option', 'first-select');
        CreateSelect(lengthArray, secondContainer, 'second-option', 'second-select', true);
    } else if(el === 'mass') {
        CreateSelect(massArray, firstContainer, 'first-option', 'first-select');
        CreateSelect(massArray, secondContainer, 'second-option', 'second-select', true);
    }

    firstContainer.addEventListener('click', function(event) {
        firstNum.value = '';
        secondNum .value = '';
        firstVal = event.target.value;
    })

    secondContainer.addEventListener('click', function(event) {
        firstNum.value = '';
        secondNum.value = '';
        secondtVal = event.target.value;
    })

    let switchButton = document.querySelector('.switch');
    let a = document.querySelector('.first-select')
    let opt1 = a.options[a.selectedIndex].text;
    let b = document.querySelector('.second-select')
    let opt2 = b.options[b.selectedIndex].text;

    switchButton.addEventListener('click', function(event) {
        let temp = firstNum.value;
        firstNum.value = secondNum.value;
        secondNum .value = temp;

        let tmp = opt1;
        opt1.value = opt2;
        opt2 = tmp;
    })

    firstNum.addEventListener('input', function(event) {
        if(firstVal === 'meter' && secondtVal === 'kilometer') {
            val = event.target.value * 1000;
        } else if(firstVal === 'kilometer' && secondtVal === 'meter') {
            val = event.target.value / 1000;
        } else if(firstVal === 'gram' && secondtVal === 'kilogram') {
            val = event.target.value * 1000;
        } else if(firstVal === 'kilogram' && secondtVal === 'gram') {
            val = event.target.value / 1000;
        } else  if (firstVal === secondtVal) {
            val = event.target.value * 1000;
        } else {
            val = event.target.value;
        }
        
        secondNum.value = val;
    })
})