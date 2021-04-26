#include <iostream>

int SearchItem(int array[], int size, int item)
{
    int found_index = -1;

    for (int i = 0; i < size; i++) {
        if (array[i] == item) {
            found_index = i;
        }
    }

    return found_index;
} 

int main()
{
    int arr[5] = {1, 3, 5, 7, 9};
    std::cout << "Searched item index is ";
    std::cout << SearchItem(arr, 5, 3) << std::endl;

    return 0;
}
