#include <iostream>

int SearchItem(int array[], int start, int end, int item)
{
    int position = start + (item - array[start]) * (end - start) / (array[end] - array[start]) ;

    if (array[position] == item) {
        return  position;      
    } 
    
    if (start < end) {
        if (item < array[position]) {
          return SearchItem(array, start, position - 1, item);
        } else {
          return SearchItem(array, position + 1, end, item);
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
