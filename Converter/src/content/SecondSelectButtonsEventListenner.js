import createSelectOptions from '../containers/selectItemCreater'
import obj from '../containers/valuesForSelectOptions'

const selectbutton2 = document.getElementById('selectbutton2')
let selectedValueInFirstSelectButton;
let selectedValueInSecondSelectButton;
const newELement = document.getElementById('lastSelect')

export default function secondSelectButtonsEventListenner() {
    obj.forEach(element => {
        element.selectOp.addEventListener("click", (ev) => {
            newELement.innerHTML = ""
            for (let key in element.value) {
                if (ev.target.value == key) {
                    createSelectOptions(element.value[element.selectOp.options[element.selectOp.selectedIndex].text],
                        newELement, selectbutton2)
                    selectedValueInFirstSelectButton = key;
                    newELement.hidden = false
                    selectedValueInSecondSelectButton = element.value[key][0]
                    break;
                }
            }
        })
    })
};

function setSelectItem(newSelectedValue) {
    selectedValueInSecondSelectButton = newSelectedValue;
}

export { selectedValueInFirstSelectButton, selectedValueInSecondSelectButton, setSelectItem };

