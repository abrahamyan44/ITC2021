import * as _ from 'lodash';


function main() {
    // generateLengtSelect();
    debugger;
    const select_object = document.querySelector('#select-parameter');
    let select_result = 0;
    select_object.addEventListener('change', (event) {
        // select_result = 
        console.log(event.target.value);
    });
    // debugger;
    if (select_result === 'Length') {
        generateLengtSelect();
    }
    const left_select = document.querySelector('.left-select');
    const right_select = document.querySelector('.right-select');
    switch (left_select) {
        case 'Kilometre':
            switch (right_select) {
                case 'Metre':
                    kilometreToMetre();
                    break;
            }
            break;
        case 'Metre':
            switch (right_select) {
                case 'Kilometre':
                    metreToKilometre();
                    break;
            }
            break;
    }

}


function generateLengtSelect() {
    const left_select = document.createElement('select');
    left_select.className = 'left-select';
    console.log(left_select);
    const right_select = document.createElement('select');
    right_select.className = 'right-select';
    
    const array_metric_units = ['Kilometre', 'Meter',]
    
    for (let index = 0; index < array_metric_units.length; index++) {
        const option1 = document.createElement('option');
        option1.value = array_metric_units[index];
        option1.textContent = array_metric_units[index];
        left_select.appendChild(option1);

        const option2 = document.createElement('option');
        option2.value = array_metric_units[index];
        option2.textContent = array_metric_units[index];
        right_select.appendChild(option2);
    }
    
    const metric_units = document.querySelector('.metric-units');
    console.log(metric_units);
    console.log(left_select);
    metric_units.appendChild(left_select);
    metric_units.appendChild(right_select);
}

function kilometreToMetre() {
    const input = document.querySelector('.first-input');
    const output = document.querySelector('.second-input');
    output.textContent = input.textContent * 1000;
}

function metreToKilometre() {
    const input = document.querySelector('.first-input');
    const output = document.querySelector('.second-input');
    output.textContent = input.textContent / 1000;
}


function generateMassSelect() {
    const left_select = document.createElement('select');
    left_select.className = 'first_select';

    
}


main();