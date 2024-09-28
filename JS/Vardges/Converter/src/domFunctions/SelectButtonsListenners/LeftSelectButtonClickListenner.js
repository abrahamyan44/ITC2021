import changeResult from '../../UsedFunctions/resultsAutomaticChanger'

const leftSelect = document.getElementById('leftSelect')

export default function leftSelectButtonsClickListenner() {
    leftSelect.addEventListener("click", () => {
        changeResult();
    })
}