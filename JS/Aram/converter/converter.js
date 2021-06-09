const measurements =  require('./measurements.json');

function convert(measure, from, to) {
    const toValue = from.value * measurements[measure][from.type] / measurements[measure][to.type];
    return toValue;
}

console.log('2 kg to gr: ', convert('massa', { value: 2, type: 'kg' }, { type: 'gr' }));
console.log('2 gr to kg: ', convert('massa', { value: 2, type: 'gr' }, { type: 'kg' }));
