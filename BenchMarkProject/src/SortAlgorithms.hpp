#include <iostream>

void Swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int* array,int size) {
    bool swapped=false;
    for (int i = 0; i < size ; ++i) {
        for (int j = 0; j < size-i; ++j) {
            if (array[j] > array[j+1]) {
                Swap(&array[j],&array[j+1]);
                swapped = true;
            }
    }
			if (swapped == false) {
            break;
			}
    }
}

void ShellSort(int* array, int size) {
    for (int gap = size / 2; gap >= 1; gap /= 2) {
        for (int i = gap; i < size; ++i) {
            int temp = array[i];
			int j;
            for (j = i; array[j - gap] > temp && j >= gap; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}


void Merge(int* array, int start, int end, int mid) {
    int newArray[end + 1];
    int i = start;
    int j = mid+1;
    int k = start;
    while (i <= mid && j <= end) {
        if (array[i] < array[j]) {
            newArray[k] = array[i];
            ++i; ++k;
        } else {
            newArray[k] = array[j];
            ++j; ++k;
        }
    }
    while (i <= mid) {
        newArray[k] = array[i];
        ++i; ++k;
    }
    while (j <= end) {
        newArray[k] = array[j];
        ++j; ++k;
    }
    for (int index = 0; index < k; ++index) {
        array[index] = newArray[index];
    }
}

void MergeSort(int* array, int start, int end) {
    int mid;
    if (start < end) {
        mid = (start + end)/2;
        MergeSort(array, start, mid);
        MergeSort(array, mid + 1, end);
        Merge(array, start, end, mid);
    }

}

 void Heapify(int* array, int size, int i) {
     int largest = i;
     int l = 2 * i + 1;
     int r = 2 * i + 2;
     i = largest;
     if (l < size && array[l] > array[largest]) {
         largest = l;
     }
     if (r < size && array[r] > array[largest]) {
         largest = r;
     }
     if (i != largest) {
         Swap(&array[largest], &array[i]);
         Heapify(array, size, largest);
     }
 }

void HeapSort(int* array, int size){
    for (int i = size / 2 - 1; i >= 0; --i) {
        Heapify(array, size, i);
    }
    for (int i = size-1; i > 0; --i) {
        Swap(&array[i], &array[0]);
        Heapify(array, i, 0);
    }
}

int Partition(int* array, int start, int end) {
    int wall = start - 1;
    int pivot = array[end];
    for (int i = start; i < end; ++i) {
        if (array[i] <  pivot) {
            wall++;
            Swap(&array[i], &array[wall]);
        }
    }
    Swap(&array[wall + 1], &array[end]);
    return (wall + 1);
}

void QuickSort(int* array, int start, int end) {
    if (start < end) {
        int index = Partition(array, start, end);
        QuickSort(array, start, index - 1);
        QuickSort(array, index + 1, end);
    }
}

void DeclareSortedArray(int* array, int* array1, int* array2, int size) {
	int index1 = 0;
	int index2 = 0;
	for (int i = 0; i < size; ++i) {
		if (index2 >= size - size / 2 || (index1 < size / 2 && array1[index1] < array2[index2])) {
			array[i] = array1[index1];
			++index1;
		} else {
			array[i] = array2[index2];
			++index2;
		}
	}
}

void DivideMyArray(int* array, int* array1, int* array2, int size) {
    for (int i = 0; i < size / 2; ++i) {
		array1[i] = array[i];
	}
	for (int i = 0; i < size - size / 2; ++i) {
		array2[i] = array[i + size / 2];
	}
}

void MergeSort(int* array, int size) {
	if (size == 1) {
		return;
	}
	if (size == 2) {
		if (array[0] > array[1]) {
			Swap(&array[0], &array[1]);
		}
		return;
	}
	int* array1 = new int[size / 2];
	int* array2 = new int[size - size / 2];
	DivideMyArray(array, array1, array2, size);
	MergeSort(array1, size / 2);
	MergeSort(array2, size - size / 2);
	DeclareSortedArray(array, array1, array2, size);
	delete[] array1;
	delete[] array2;
}
