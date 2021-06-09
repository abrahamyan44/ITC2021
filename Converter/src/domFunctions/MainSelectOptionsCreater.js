import obj from '../../resources/measurements.json'
import createSelectButton from '../UsedFunctions/selectButtonCreater'
const mainSelector = document.getElementById("mainSelector");
const leftSelect = document.getElementById('leftSelect')
const rightSelect = document.getElementById('rightSelect')

export default function createMainSelectButtonsOptions() {
    createSelectButton(Object.keys(obj), mainSelector);
    let key = mainSelector.options[mainSelector.selectedIndex].text;
    createSelectButton(Object.keys(obj[key]), leftSelect)
    createSelectButton(Object.keys(obj[key]), rightSelect)
}

