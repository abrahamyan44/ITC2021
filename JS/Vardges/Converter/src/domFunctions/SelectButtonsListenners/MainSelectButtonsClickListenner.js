import changeResult from '../../UsedFunctions/resultsAutomaticChanger'

const mainSelector = document.getElementById("mainSelector");

export default function mainSelectButtonsClickListenner() {
    mainSelector.addEventListener("click", () => {
        changeResult()
    })
}