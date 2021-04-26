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

int main()
{
    int arr[5] = {1, 0, 5, 4, 9};
    std::cout << "The searched item index is ";
    std::cout << SearchItem(arr, 0, 5, 9) << std::endl;

    return 0;
}
