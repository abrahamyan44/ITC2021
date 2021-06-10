import convert from '../UsedFunctions/ConvertFunction'

const input1 = document.getElementById("input1")
const mainSelector = document.getElementById("mainSelector");
const leftSelect = document.getElementById('leftSelect')
const rightSelect = document.getElementById('rightSelect')

export default function changeResult() {
    let measure = mainSelector.options[mainSelector.selectedIndex].text;
    let from = leftSelect.options[leftSelect.selectedIndex].text;
    let to = rightSelect.options[rightSelect.selectedIndex].text;
    convert(measure, from, to, input1.value)
}