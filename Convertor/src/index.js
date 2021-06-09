import * as _ from 'lodash';

let length_metric_units = ['Centimeter', 'Kilometre', 'Metre', 'Millimetre'];
let mass_metric_units = ['Gram', 'Kilogram', 'Milligram', 'Tonne',];
let frequency_metric_units = ['Hertz', 'Kilohertz', 'Megahertz'];

let frequency = {
    'Hertz': 1,
    'Kilohertz': 1000,
    'Megahertz': 1000000
}

let mass = {
    'Milligram': 0.000001,
    'Gram': 0.001,
    'Kilogram': 1,
    'Tonne': 1000
} 

let length = {
    'Millimetre': 0.001,
    'Centimeter': 0.01,
    'Meter': 1,
    'Kilometre': 1000,
}

function main() {
    const select_object = document.querySelector('#select-parameter');
    let select_result = 0;
    select_object.addEventListener('change', function (event) {
        select_result = event.target.value;
        switch (select_result) {
            case 'Length':
                convertingLength();
                break;
            case 'Mass':
                convertingMass();
                break;
            case 'Frequency':
                convertingFrequency();
                break;
            default:
                document.querySelector('.metric-units').innerHTML = '';
                break;
        }
    });
}

function generateMetricUnitSelects(block_to_append,  metric_units) {
    const left_select = document.createElement('select');
    left_select.className = 'left-select';
    const right_select = document.createElement('select');
    right_select.className = 'right-select';
    for (let index = 0; index < metric_units.length; index++) {
        //create and append to left select
        const option1 = document.createElement('option');
        option1.value = metric_units[index];
        option1.textContent = metric_units[index];
        left_select.appendChild(option1);
        console.log(left_select);
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

function convertingLength() {
    const metric_units_block = document.querySelector('.metric-units');
    metric_units_block.innerHTML = '';
    generateMetricUnitSelects(metric_units_block, length_metric_units);
    swapMetricUnits();
    const left_input = document.querySelector('#left-input');
    left_input.addEventListener('input', function (event) {
        const right_input = document.querySelector('#right-input');
        const right_select = document.querySelector('.right-select');
        const left_select = document.querySelector('.left-select');
        if (event.target.value > 0) {
            right_input.value = event.target.value * length[left_select.value]/ length[right_select.value];
        } else {
            right_input.value = '';
        }
    });
}

function convertingMass() {
    const metric_units_block = document.querySelector('.metric-units');
    const left_input = document.querySelector('#left-input');
    metric_units_block.innerHTML = '';
    generateMetricUnitSelects(metric_units_block, mass_metric_units);
    swapMetricUnits();
    left_input.addEventListener('input', function (event) {
        const left_select = document.querySelector('.left-select');
        const right_input = document.querySelector('#right-input');
        const right_select = document.querySelector('.right-select');
        if (event.target.value > 0) {
            right_input.value = event.target.value * mass[left_select.value]/ mass[right_select.value];
        } else {
            right_input.value = '';
        }
    });
}

function convertingFrequency() {
    const metric_units_block = document.querySelector('.metric-units');
    metric_units_block.innerHTML = '';
    generateMetricUnitSelects(metric_units_block, frequency_metric_units);
    swapMetricUnits();
    const left_input = document.querySelector('#left-input');
    left_input.addEventListener('input', function (event) {
        const right_input = document.querySelector('#right-input');
        const right_select = document.querySelector('.right-select');
        const left_select = document.querySelector('.left-select');
        if (event.target.value > 0) {
            right_input.value = event.target.value * frequency[left_select.value]/ frequency[right_select.value];
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

