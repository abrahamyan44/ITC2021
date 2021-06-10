import obj from '../../resources/measurements.json'

const input2 = document.getElementById("input2");

export default function convert(measure, from, to, value) {
    input2.value = value * obj[measure][from] / obj[measure][to];
}