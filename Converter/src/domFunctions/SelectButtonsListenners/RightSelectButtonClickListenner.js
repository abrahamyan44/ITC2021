import changeResult from '../../UsedFunctions/resultsAutomaticChanger'

const rightSelect = document.getElementById('rightSelect')

export default function rightSelectButtonsClickListenner() {
    rightSelect.addEventListener("click", () => {
        changeResult();
    })
}