void BubbleSortByArtaxiad(int size, int* array);

void MergeSortByArtaxiad(int size, int* array);

void ShellSortByArtaxiad(int size, int* array);

void QuickSortByArtaxiad(int size, int* array);

void InsertionSortByArtaxiad(int size, int* array);

void SelectionSortByArtaxiad(int size, int* array);

void HeapSortByArtaxiad(int size, int* array);

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSortByArtaxiad(int size, int* array) {
    bool swapped = false;
    for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size - i; ++j) {
			if (array[j] > array[j + 1]) {
				Swap(&array[j], &array[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false) {
			break;
		}
    }
}

void Merge(int* array, int* array1, int* array2, int left, int middle, int right) {
    int length1 = middle - left + 1;
    int length2 = right - middle;
    int index1 = 0;
    int index2 = 0;
        for (int i = left; i <= right; ++i) {
            if (index1 < length1 && (index2 >= length2 || array1[index1] < array2[index2])) {
                array[i] = array1[index1];
                ++index1;
            } else {
                array[i] = array2[index2];
                ++index2;
                }
        }
}

void MergeSortRecursivly(int* array, int left, int right) {
    int middle = (right + left) / 2;
    if (left < right) {
		int* array1 = new int[middle - left + 1];
		int* array2 = new int[right - middle];
		for (int i = 0; i <= middle - left; i++) {
			array1[i] = array[i + left];
		}
		for (int j = middle + 1; j <= right; j++) {
			array2[j - middle - 1] = array[j];
		}
		MergeSortRecursivly(array1, 0 , middle - left);
		MergeSortRecursivly(array2, 0, right - middle - 1);
		Merge(array, array1, array2, left, middle, right);
		delete[] array1;
		delete[] array2;
    }
}

void MergeSortByArtaxiad(int size, int* array) {
    MergeSortRecursivly(array, 0, size - 1);
}

void ShellSortByArtaxiad(int size, int* array) {
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

void QuickSortByArtaxiad(int size, int* array) {
    if (size == 1) {
		return;
    }
    QuickSort(array, 0, size - 1);
}

void InsertionSortByArtaxiad(int size, int* array) {
    int key;
    int j;
    for (int i = 1; i < size; ++i) {
		key = array[i];
        j = i - 1;
        while (array[j] > key && j >= 0) {
			array[j + 1] = array[j];
            j -= 1;
		}
		array[j + 1] = key;
    }
}

void SelectionSortByArtaxiad(int size, int* array) {
    int min_index;
    for (int i = 0; i < size; ++i) {
        min_index = i;
       	for (int j = i + 1; j < size; ++j) {
			if (array[j] < array[min_index]) {
				min_index = j;
            }
		}
        if (i != min_index) {
			Swap(&array[i], &array[min_index]);
        }
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

void HeapSortByArtaxiad(int size, int* array) {
    for (int i = size / 2 - 1; i >= 0; --i) {
		Heapify(array, size, i);
    }
    for (int i = size - 1; i > 0; --i) {
		Swap(&array[i], &array[0]);
		Heapify(array, i, 0);
    }
}
