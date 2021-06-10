export default function createSelectButton(optionsArray, selectButton) {
    selectButton.innerHTML = ""
    for (let value of optionsArray) {
        const newOption = document.createElement('option');
        newOption.innerHTML = value
        selectButton.appendChild(newOption)
    }
}