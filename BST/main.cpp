#include <iostream>
#include "BST.hpp"

int main()  {
    int arr[5] = {2, 1, 3, 7, 5};
    BST t(arr, 5);
    t.Print();
    
    return 0;
}