#include <iostream>
#include "Tree.hpp"

int main()
{
    int arr[]={1,2,3,4,5,6,7,8};
    Tree<int> BinaryTreeObject(arr, 7);
    BinaryTreeObject.PrintPreOrder();   //prints node value left childe value and right childe value
    std::cout << std::endl;
    
    BinaryTreeObject.PrintInOrder();  //prints left childe value node value and right childe value
    std::cout << std::endl;
    
    BinaryTreeObject.PrintPostOrder();   //prints left childe value right childe value and node value
    std::cout << std::endl;

    Tree<int> TemporaryObject;
    TemporaryObject.PrintPreOrder();

    TemporaryObject.Insert(3);
    TemporaryObject.Insert(76);
    TemporaryObject.Insert(2);
    TemporaryObject.Insert(35);
    TemporaryObject.Insert(4);
    TemporaryObject.Insert(18);
    TemporaryObject.Insert(7);
    TemporaryObject.Insert(19);
    TemporaryObject.PrintInOrder();
    std::cout << std::endl;
    
    BinaryTreeObject.Insert(9);
    BinaryTreeObject.PrintInOrder();
    std::cout << std::endl;
}
