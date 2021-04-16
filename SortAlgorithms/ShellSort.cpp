#include <iostream>

void ShellSort(int array[], int size)
{
	for (int gap = size / 2; gap >= 1; gap /= 2) {
		int j;
		for (int i = gap; i < size; ++i) {
			int temp = array[i];

			for (j = i; array[j - gap] > temp && j >= gap; j -= gap) {
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
	}
}

void Print(int array[], int size) 
{
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() 
{
    int array[]={2, 3, 4, 5, 1};
    int size = sizeof(array) / sizeof(array[0]);

    Print(array, size);
    ShellSort(array, size);
    Print(array, size);

    return 0;
}

