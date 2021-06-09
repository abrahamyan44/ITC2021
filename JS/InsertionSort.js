function InsertionSort(array) {
	for (let i = 1; i < array.length; ++i) {
		let j = i - 1;
		while (j >= 0 && array[j] > array[i]) {
			let temp = array[j];
	        array[j] = array[i];
	        array[i] = temp;
			j = j - 1;
			i = i - 1;
		}
	}
    for (let k = 0; k < array.length; ++k) {
		console.log(array[k]);
	}
}
