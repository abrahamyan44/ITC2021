

swap(var x, var y) {
    var z = x;
    x = y;
    y = z;
}

function BubbleSort(array) {
    let size = array.lenght;
    for(let i = 0; i <= size; i++) {
        bool swaped = false;
        for(let j = 0; j <= size - i; i++) {
           if(array[j] > array[j+1]){
           swap(array[j], array[j+1]);
            swaped = true;
           }        
        }
         if (swapped == false) {
             return array;
         }
    }
}

var array = [87, 45, 98, 23, 15, 64, 96];
console.log(array);

BubbleSort(array);
console.log(array);