function sort (array, left, right) {
    let pivot_index = right;
    let pivot_value = array[pivot_index];
    [array[left], array[pivot_index]] = [array[pivot_index], array[left]];
    let border = left;
    for (let index = left + 1; index <= right; index++) {
        if (array[index] < pivot_value) {
            ++border;
            [array[border], array[index]] = [array[index], array[border]];
        }        
    }
    [array[border], array[left]] = [array[left], array[border]];
    return border;
}

function quickSort (array, left, right) {
    if (left < right) {
        let pivot = sort(array, left, right);
        quickSort(array, left, pivot - 1);
        quickSort(array, pivot + 1, right);
    }
}

function main() {
    let array = [6, 3, 7, 5, 1, 9, 2, 8, 4]
    console.log(array);
    quickSort(array, 0, array.length - 1);
    console.log(array);
}

main();