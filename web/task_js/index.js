
//      var a = 5;
//     console.log('Yeva')
//    // string = `helllo $(a)`
//
//     console.log(a)

// console.log(a)
// function f1()
// {
//     let a = 1;
//     console.log(a);
// }

// const a = {
//     b:1
// };

// a.b = 5
// console.log(a);

/*function Partitioning(array, start, end) {
    let pivot = end; 	 
    let pindex = start;  // index for partitioning

    for (let i = start; i < end; ++i) {
        if (array[i] < array[pivot]) {
            let tmp = array[pindex];
            array[pindex] = array[i];
            array[i] = tmp;
            ++pindex;
        }
    }

    tmp = array[pindex];
    array[pindex] = array[pivot];
    array[pivot] = tmp;

    return pindex;
}

function QuickSort(array, start, end) {
    if (start >= end) {
        return;
    }

    let pivot = Partitioning(array, start, end); 

    QuickSort(array, start, pivot - 1);
    QuickSort(array, pivot + 1, end);
}

function main(){
    let array = [9, 0, 2, 7, -2, 6, 1 ];
    document.write("Original array: " + array);
    QuickSort(array, 0, 6);
    console.log(array);
    //document.write("Sorted array: " + array);
}

main();*/

/* 111111111111111111 */
function f(arr) {
let newArr = [...arr];
newArr[0].c1 = "hello";
return newArr;
}

const a1 = [{c1:1}, {c:2}];
const retArr = f(a1);

console.log(retArr)
console.log(a1);

/* 222222222222222222 */
// function f(arr) {
// let newArr = [...arr];
// newArr[0] = "hello";
// return newArr;
// }

// const a1 = [1, 2];
// const retArr = f(a1);

// console.log(retArr)
// console.log(a1);
