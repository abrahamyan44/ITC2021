import data from '../containers/data'
import { selectedValueInFirstSelectButton, selectedValueInSecondSelectButton } from './SecondSelectButtonsEventListenner'


export default function writeValueInInputButton() {
    document.getElementById('input1').addEventListener("input", (ev) => {
        input2.value = 0;
        for (let key in data) {
            if (key == selectedValueInFirstSelectButton) {
                for (let objKey in data[key]) {
                    if (objKey == selectedValueInSecondSelectButton) {
                        input2.value = ev.target.value * data[key][objKey];
                        break;
                    }
                }
            }
        }
    })
}