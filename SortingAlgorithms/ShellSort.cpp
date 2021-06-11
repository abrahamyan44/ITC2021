#include <iostream>

void ShellSort(int* array, int n){
	for (int gap = n / 2; gap > 0; gap /= 2) {
		int j;
		for (int i = gap; i < n; ++i) {
			int temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap){
				array[j] = array[j - gap];
			}
		array[j] = temp;
		}
	}
}


void PrintArray(int* array, int n) {
    for(int i = 0; i < n; ++i){
        std::cout << array[i] << " " ;
    }   
    std::cout << std::endl;
}

int main() {
    int array[] = { 2, 3, 1, 5, 6, 4 };
    int n = sizeof(array) / sizeof(array[0]);
    std::cout << "Array before sorting" << std::endl;
    PrintArray(array, n); 
    ShellSort(array, n); 
    std::cout << "Array after shell sorting" << std::endl;
    PrintArray(array, n); 
    return 0;
}

