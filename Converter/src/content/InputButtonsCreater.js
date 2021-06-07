export default function inputButtonsCreater() {
    const selectbutton1 = document.getElementById('selectbutton1')
    const selectbutton2 = document.getElementById('selectbutton2')
    const input1 = document.createElement('input');
    input1.type = "number"
    input1.id = "input1"
    const input2 = document.createElement('input');
    input2.type = "text"
    input2.id = "input2"
    selectbutton1.appendChild(input1)
    selectbutton2.appendChild(input2)
}

