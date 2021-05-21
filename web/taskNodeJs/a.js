function print(val) {
    console.log( val);
}

function f1() {}

module.exports.printA = print;

// module.exports = {
//     ff1: f1,
//     printA: print
// }
module.exports.f1A = f1;

