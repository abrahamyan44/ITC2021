using namespace std;


void BubbleSortByBagratid(int size, int* array);

void QuickSortByBagratid(int size, int* array);

void SelectionSortByBagratid(int size, int* array);

void InsertionSortByBagratid(int size, int* array);

void ShellSortByBagratid(int size, int* array);

void HeapSortByBagratid(int size, int* array);

void MergeSortByBagratid(int size, int* array);

void Swap(int& value1, int& value2) {
    int temporary = value1;
    value1 = value2;
    value2 = temporary;
}

void BubbleSortByBagratid(int size, int* array) {
    bool swapped = false;
    for (int i = 0; i < size; ++i) {
        for (int j = 1; j < size - i; ++j) {
            if (array[j - 1] > array[j]) {
                Swap(array[j - 1], array[j]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
	return;
}

void QuickSortRecursive(int start, int wall, int end, int* array) {
    if (start >= end) {
        return;
    }
    if (start + 1 == end) {
        if (array[start] > array[end]) {
            Swap(array[start], array[end]);
        }
        return;
    }
    for (int i = wall; i < end; ++i) {
        if (array[i] < array[end]) {
            Swap(array[wall], array[i]);
            ++wall;
        }
    }
    Swap(array[wall], array[end]);
    QuickSortRecursive(start, start, wall - 1, array);
    QuickSortRecursive(wall + 1, wall + 1, end, array);
}

void QuickSortByBagratid(int size, int* array) {
    QuickSortRecursive(0, 0, size - 1, array);
}

void SelectionSortByBagratid(int size, int* array) {
    for (int i = 0; i < size; ++i) {
        int minimum = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[minimum] > array[j]) {
                minimum = j; 
            }
        }
        Swap(array[minimum], array[i]); 
    }
}

void InsertionSortByBagratid(int size, int* array) {
    for (int i = 1; i < size; ++i) {
        int element = array[i];
        int j = i;
        while (j > 0 && array[j - 1] > element) {
            array[j] = array[j - 1];
            j = j - 1;
        }
        array[j] = element;
    }
}

void ShellSortByBagratid(int size, int* array) {
	for (int interval = size / 2; interval > 0; interval /= 2)	{
		for (int i = interval; i < size; ++i) {
			for (int j = i; j >= interval; j -= interval) {
				if (array[j] < array[j - interval]) {
					Swap(array[j], array[j - interval]);
				} else {
					break;
				}
			}
		}
	}
}

void HeapSwapping(const int& size, int index, int* array) {
	int maximum = index;
	int left = 2 * index + 1, right = 2 * index + 2;
	if (left < size && array[left] > array[maximum]) {
		maximum = left;
	}
	if (right < size && array[right] > array[maximum]) {
		maximum = right;
	}
	if (maximum != index) {
		Swap(array[maximum], array[index]);
		HeapSwapping(size, maximum, array);
	}
}

void HeapSortByBagratid(int size, int* array) {
	for (int i = size / 2 - 1; i >= 0; --i) {
		HeapSwapping(size, i, array);
	}
	for (int i = size - 1; i >= 0; --i) {
		Swap(array[0], array[i]);
		HeapSwapping(i, 0, array);
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
	for (int i = 0; i < size - size / 2; ++i)	{
		array2[i] = array[i + size / 2];
	}
}

void MergeSortByBagratid(int size, int* array) {
	if (size == 1) {
		return;
	}
	if (size == 2) {
		if (array[0] > array[1]) {
			Swap(array[0], array[1]);
		}
		return;
	}
	int* array1 = new int[size / 2];
	int* array2 = new int[size - size / 2];
	DivideMyArray(array, array1, array2, size);
	MergeSortByBagratid(size / 2, array1);
	MergeSortByBagratid(size - size / 2, array2);
	DeclareSortedArray(array, array1, array2, size);
	delete[] array1;
	delete[] array2;
}
