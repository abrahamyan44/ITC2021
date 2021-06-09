#include <iostream>
void Merge(int array[], int start, int middle, int end)
{
    int left_arr_index = middle - start + 1;
    int right_arr_index = end - middle;
    int left_arr[left_arr_index];
    int right_arr[right_arr_index];

    for(int i = 0; i < left_arr_index; ++i) {
        left_arr[i] = array[start + i];
    }
    for(int j = 0; j < right_arr_index; ++j) {
        right_arr[j] = array[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = start;

    while(i < left_arr_index && j < right_arr_index) {
        if(left_arr[i] <= right_arr[j]) {
            array[k] = left_arr[i];
            i++;
        } else {
            array[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while(i < left_arr_index) {
        array[k] = left_arr[i];
        i++;
        k++;
    }

    while(j < right_arr_index) {
        array[k] = right_arr[j];
        j++;
        k++;
    }
}

void MergeSort(int array[], int start, int end) {
        if (start < end) {
            int middle = start + (end - start) / 2;
            MergeSort(array, start, middle);
            MergeSort(array, middle + 1, end);
            Merge(array, start, middle, end);
        }
}

void Print(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	int array[] = {4, 5, 15, 0, 9, 111};
	int size = sizeof(array) / sizeof(array[0]);
	MergeSort(array, 0, size);
	Print(array, size);
	
	return 0;
}
