import * as _ from 'lodash';

let length_metric_units = ['Centimeter', 'Kilometre', 'Meter', 'Millimetre'];
let mass_metric_units = ['Gram', 'Kilogram', 'Milligram', 'Tonne',];
let frequency_metric_units = ['Hertz', 'Kilohertz', 'Megahertz'];

let mass_coefficient = {
    'Milligram': 0.000001,
    'Gram': 0.001,
    'Kilogram': 1,
    'Tonne': 1000
} 

let length_coefficient = {
    'Millimetre': 0.001,
    'Centimeter': 0.01,
    'Meter': 1,
    'Kilometre': 1000,
}


let frequency_coefficient = {
    'Hertz': 1,
    'Kilohertz': 1000,
    'Megahertz': 1000000
}

function main() {
    const select_object = document.querySelector('#select-parameter');
    select_object.addEventListener('change', (event) => {
        document.querySelector('#left-input').value = '';
        document.querySelector('#right-input').value = '';
        switch (event.target.value) {
            case 'Length':
                converting(length_metric_units, length_coefficient);
                break;
            case 'Mass':
                converting(mass_metric_units, mass_coefficient);
                break;
            case 'Frequency':
                converting(frequency_metric_units, frequency_coefficient);
                break;
            default:
                document.querySelector('.metric-units').innerHTML = '';
                break;
        }
    });
}

function generateMetricUnitSelects(block_to_append, metric_units) {
    const left_select = document.createElement('select');
    const right_select = document.createElement('select');
    left_select.className = 'left-select';
    right_select.className = 'right-select';
    for (let index = 0; index < metric_units.length; index++) {
        //create and append to left select
        const option1 = document.createElement('option');
        option1.value = metric_units[index];
        option1.textContent = metric_units[index];
        left_select.appendChild(option1);
        //create and append to right select
        const option2 = document.createElement('option');
        option2.value = metric_units[index];
        option2.textContent = metric_units[index];
        right_select.appendChild(option2);
    }
    const swap_button = document.createElement('button');
    swap_button.id = 'swap-button';
    swap_button.textContent = 'Swap';
    left_select.value = metric_units[0];
    right_select.value = metric_units[1];
    block_to_append.appendChild(left_select);
    block_to_append.appendChild(swap_button);
    block_to_append.appendChild(right_select);
}

function converting(metric_units, coefficient) {
    const metric_units_block = document.querySelector('.metric-units');
    metric_units_block.innerHTML = '';
    generateMetricUnitSelects(metric_units_block, metric_units);
    swapMetricUnits();
    leftSelectChange(coefficient);
    rightSelectChange(coefficient);
    const left_input = document.querySelector('#left-input');
    const right_input = document.querySelector('#right-input');
    const right_select = document.querySelector('.right-select');
    const left_select = document.querySelector('.left-select');
    left_input.addEventListener('input', function (event) {
        if (event.target.value > 0) {
            right_input.value = event.target.value * coefficient[left_select.value]/ coefficient[right_select.value];
        } else {
            right_input.value = '';
        }
    });
}

function rightSelectChange(coefficient) {
    const right_input = document.querySelector('#right-input');
    const left_input = document.querySelector('#left-input');
    const right_select = document.querySelector('.right-select');
    const left_select = document.querySelector('.left-select');
    right_select.addEventListener('change', (event) => {
        if (left_input.value > 0) {
            right_input.value = left_input.value * coefficient[left_select.value] / coefficient[event.target.value];
        } else {
            right_input.value = '';
        }
    });
}

function leftSelectChange(coefficient) {
    const right_input = document.querySelector('#right-input');
    const left_input = document.querySelector('#left-input');
    const right_select = document.querySelector('.right-select');
    const left_select = document.querySelector('.left-select');
    left_select.addEventListener('change', (event) => {
        if (left_input.value > 0) {
            right_input.value = left_input.value * coefficient[event.target.value] / coefficient[right_select.value];
        } else {
            right_input.value = '';
        }
    });
}

function swapMetricUnits() {
    const swap_button = document.querySelector('#swap-button');
    swap_button.addEventListener('click', function (event) {
        let left_input = document.querySelector('#left-input');
        let right_input = document.querySelector('#right-input');
        let left_select = document.querySelector('.left-select');
        let right_select = document.querySelector('.right-select');
        let temporary = left_select.value;
        left_select.value = right_select.value;
        right_select.value = temporary;
        temporary = left_input.value;
        left_input.value = right_input.value;
        right_input.value = temporary;
    })
}

main();

