#include <iostream>
#include "bst.hpp"



int main() {

    const int size = 6;
    int array[size] = { 7, 8, 12, 54, 31, 4 };
    BST tree = BST(array, size);
    tree.print_inOrder();
    tree.print_preOrder();
    tree.print_postOrder();

}
