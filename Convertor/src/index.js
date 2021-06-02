import * as _ from 'lodash';

function main() {
    const select_object = document.querySelector('#select-parameter');
    const metric_units_block = document.querySelector('.metric-units');
    let select_result = 0;
    select_object.addEventListener('change', function (event) {
        select_result = event.target.value;
        if (select_result === 'Length') {
            removeAllCilds(metric_units_block);
            let metric_units = ['Kilometre', 'Metre'];
            generateMetricUnitSelects(metric_units_block, metric_units);
            swapMetricUnits();
            const left_input = document.querySelector('#left-input');
            left_input.addEventListener('input', function (event) {
                const right_input = document.querySelector('#right-input');
                const left_select = document.querySelector('.left-select');
                const right_select = document.querySelector('.right-select');
                switch (left_select.value) {
                    case 'Kilometre':
                        switch (right_select.value) {
                            case 'Metre':
                                right_input.value = kilometreToMetre(event.target.value);
                                break;
                        }
                        break;
                    case 'Metre':
                        switch (right_select.value) {
                            case 'Kilometre':
                                right_input.value = metreToKilometre(event.target.value);
                                break;
                        }
                        break;
                }

            });
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
    right_select.value = metric_units[1]
    block_to_append.appendChild(left_select);
    block_to_append.appendChild(swap_button);
    block_to_append.appendChild(right_select);
}

function removeAllCilds(block) {
    if (block.childElementCount > 0) {
      while (block.firstChild) {
        block.removeChild(block.firstChild);
      }
    }
  }

function kilometreToMetre(input_value) {
    return input_value * 1000;
}

function metreToKilometre(input_value) {
    return input_value / 1000;
}

function swapMetricUnits() {
    const swap_button = document.querySelector('#swap-button');
    swap_button.addEventListener('click', function (event) {
        let left_select = document.querySelector('.left-select');
        let right_select = document.querySelector('.right-select');
        let temporary = left_select.value;
        left_select.value = right_select.value;
        right_select.value = temporary;
    })
}

main();