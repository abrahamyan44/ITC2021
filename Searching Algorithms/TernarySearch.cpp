#include <iostream>

int SearchItem(int array[], int start, int end, int item)
{
    int mid1 = start + (end - start) / 3;
    int mid2 = start + (end - start) / 3;

    if (array[mid1] == item) {
        return  mid1;      
    } 
 
    if (array[mid2] == item) {
        return  mid2;      
    }  

    if (start < end) {
        if (item < array[mid1]) {
          return SearchItem(array, start, mid1 - 1, item);
        } else if (item > array[mid2]) {
          return SearchItem(array, mid2 + 1, end, item);
        } else {
          return SearchItem(array, mid1 + 1, mid2 - 1, item);
        }
    }

    return -1;
} 

int main()
{
    int arr[5] = {1, 3, 5, 7, 9};
    std::cout << "Searched item index is ";
    std::cout << SearchItem(arr, 0, 5, 3) << std::endl;

    return 0;
}

