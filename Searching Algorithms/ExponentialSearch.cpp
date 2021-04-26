#include <iostream>

int FindMin(int a, int b)
{
    return (a > b ? a : b);
}

int BinarySearch(int array[], int start, int end, int item)
{
    int mid = start + (end - start) / 2;

    if (array[mid] == item) {
        return  mid;      
    } 
    
    if (start < end) {
        if (item < array[mid]) {
          return BinarySearch(array, start, mid - 1, item);
        } else {
          return BinarySearch(array, mid + 1, end, item);
        }
    }

    return -1;
} 

int SearchItem(int array[], int start, int end, int item)
{
    if (array[0] == item) {
        return 0; 
    }

    int i = 1;
    while (i < end + 1 && array[i] < item) {
        i *= 2;
    }

    return BinarySearch(array, i / 2, FindMin(i, end + 1), item);
} 

int main()
{
    int arr[5] = {1, 3, 5, 7, 9};
    std::cout << "Searched item intex is ";
    std::cout << SearchItem(arr, 0, 5, 3) << std::endl;

    return 0;
}
