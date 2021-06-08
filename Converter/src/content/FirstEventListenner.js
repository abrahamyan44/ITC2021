import createSelectOptions from '../containers/selectItemCreater'
import obj from '../containers/valuesForSelectOptions'
const firstSelect = document.getElementById('fSelect')

const root = document.getElementById('root');
const newElement = document.createElement('select')
newElement.id = "lastSelect";
newElement.className = "selectItems";
newElement.hidden = true;
root.appendChild(newElement);
const selectbutton1 = document.getElementById('selectbutton1')

export default function MainSelectEventsListenner() {
    firstSelect.addEventListener('click', () => {
        newElement.innerHTML = ""
        obj.forEach(element => {
            element.selectOp.hidden = true
            newElement.hidden = true
        })
        for (let i = 0; i < obj.length; ++i) {
            if (obj[i].id == firstSelect.selectedIndex) {
                obj[i].selectOp.hidden = false;
                obj[i].selectOp.innerHTML = ""
                createSelectOptions(Object.keys(obj[i].value), obj[i].selectOp, selectbutton1)
            }
            else {
                obj[i].selectOp.hidden = true;
            }
        }
    }
    )
}