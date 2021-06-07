const root = document.getElementById('root');

export default function createSelectOptions(array, selectOptions, selectbutton1 = root) {
    selectOptions.className = "selectItems"
    for (let i = 0; i < array.length; ++i) {
        const optionForSelect = document.createElement('option')
        optionForSelect.innerHTML = array[i]
        optionForSelect.className = array[i]
        selectOptions.appendChild(optionForSelect)
    }
    selectbutton1.appendChild(selectOptions);
}
