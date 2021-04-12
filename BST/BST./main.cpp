#include "BST.h"


int main()
{
    int* array;
    for (int i = 5; i >= 0; --i) {
        array[i] = i;
    }
    BinarySearchTree tree (array, 5);
    tree.Print();
    tree.Insert(9);
    tree.Insert(12);
    std::cout<<std::endl;
    tree.Remove(4);
    std::cout<<std::endl;
    tree.Print();
    tree.Remove(10);
    std::cout<<std::endl;
    tree.Print();
    return 0;
}

