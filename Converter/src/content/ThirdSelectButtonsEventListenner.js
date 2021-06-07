import { setSelectItem } from './SecondSelectButtonsEventListenner'
const lastSelect = document.getElementById('lastSelect');


export default function rememberSelectedValue() {
    lastSelect.addEventListener('click', (ev) => {
        setSelectItem(ev.target.value);
        document.getElementById('input1').value = 0;
        document.getElementById('input2').value = 0;
    })
}

