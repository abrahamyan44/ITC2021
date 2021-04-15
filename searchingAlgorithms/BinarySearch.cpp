#include <iostream>

int SearchItem(int array[], int start, int end, int item)
{
    int mid = start + (end - start) / 2;

    if (array[mid] == item) {
        return  mid;      
    } 
    
    if (start < end) {
        if (item < array[mid]) {
          return SearchItem(array, start, mid - 1, item);
        } else {
          return SearchItem(array, mid + 1, end, item);
        }
    }

    return -1;
} 

int main ()
{
    int arr[5] = {1, 3, 5, 7, 9};
    std::cout << SearchItem(arr, 0, 5, 3) << std::endl;

    return 0;
}

