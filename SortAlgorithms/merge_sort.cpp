#include <iostream>

void Merge(int array[], int start, int end, int mid) {
	int newArray[50];
	int i = start;
	int j = mid+1;
	int k = start;
	while (i <= mid && j <= end) {
		if (array[i] < array[j]) {
			newArray[k] = array[i];
			++i; ++k;
		}else {
			newArray[k] = array[j];
			++j; ++k;
		}
	}
	while (i <= mid) {
		newArray[k] = array[i];
		++i; ++k;
	}
	while (j <= end){
		newArray[k] = array[j];
		++j; ++k;
	}
	for (int index = 0; index < k; ++index) {
		array[index] = newArray[index];
	}
}

void MergeSort(int array[], int start, int end) {
	int mid;
	if (start < end) {
		mid = (start + end)/2;
		MergeSort(array, start, mid);
		MergeSort(array, mid + 1, end);
		Merge(array, start, end, mid);
	}
	
}

void Print(int array[],int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	int array[]={2,3,4,5,1};
	Print(array,5);
	MergeSort(array,0,4);
	Print(array,5);
}     
