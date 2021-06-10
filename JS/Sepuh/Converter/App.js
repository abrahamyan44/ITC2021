// let selector1 = "mg";
// let selector2 = "mg";
// let global = "weight"
let object = {
  'weight': {
    'Miligram': 0.000001,
    'Gram': 0.001,
    'Kilogram': 1,
    'Megagram': 1000,
  },
  'length': {
    'Milimetr': 0.001,
    'Santimetr': 0.01,
    'Metr': 1, 
    'Kilometr': 1000,
  },
  'speed': {
    'Milimetr/second': 0.0036, 
    'Metr/second': 3.6, 
    'Kilometr/hour': 1,
    'Kilometr/minute': 60,
  }
}

const global = document.querySelector('.global_select');
const select1 = document.querySelector('.selector1');
const select2 = document.querySelector('.selector2');
const end_block = document.querySelector('.value');
const start_block = document.querySelector('.input_num');

function createGlobalSelect() {
    for (measure in object) {
        const el = document.createElement('option');
        el.value = measure;
        el.text = measure;
        global.appendChild(el)
    }
}

function createSelector(selector) {
    selector.innerHTML = "";
    for (unit in object[global.value]) {
        const el = document.createElement('option');
        el.value = unit;
        el.text = unit;
        selector.appendChild(el);
    }
}

function getValue() {
    const value = start_block.value;
    return Math.round(value * object[global.value][select1.value] / object[global.value][select2.value] * 1000000) / 1000000;
}

function main() {
    createGlobalSelect();
    createSelector(select1);
    createSelector(select2);
    global.addEventListener('change', function (event) {
        createSelector(select1);
        createSelector(select2);
    })
    end_block.textContent = getValue();
    select1.addEventListener('change', function (event) {
        end_block.textContent = getValue();
    })
    select2.addEventListener('change', function (event) {
        end_block.textContent = getValue();
    })

    start_block.addEventListener('input', function (event) {
        end_block.textContent = getValue();
    })
}

main()