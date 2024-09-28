import obj from '../../resources/measurements.json'
import createSelectButton from '../UsedFunctions/selectButtonCreater'

const mainSelect = document.getElementById('mainSelector')
const leftSelect = document.getElementById('leftSelect')
const rightSelect = document.getElementById('rightSelect')

export default function createLeftSelectOptions() {
    mainSelect.addEventListener("click", () => {
        let key = mainSelect.options[mainSelect.selectedIndex].text;
        createSelectButton(Object.keys(obj[key]), leftSelect)
        createSelectButton(Object.keys(obj[key]), rightSelect)
    })
}