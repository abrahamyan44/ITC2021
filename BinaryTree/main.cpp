#include <iostream>
#include "Tree.hpp"

int main()
{
    int array[] = {1,2,3,4,5,6,7,8};
    Tree<int> Object(array, 7);
    
    Object.PrintPreOrder(); //NLR
    std::cout << std::endl;
    
    Object.PrintInOrder();  //LNR
    std::cout << std::endl;
    
    Object.PrintPostOrder();    //LRN
    std::cout << std::endl;

    Tree<int> TMP;
    TMP.PrintPreOrder();

    TMP.Insert(3);
    TMP.Insert(76);
    TMP.Insert(2);
    TMP.Insert(35);
    TMP.Insert(4);
    TMP.Insert(18);
    TMP.Insert(7);
    TMP.Insert(19);
    TMP.PrintInOrder();
    std::cout << std::endl;
    
    Object.Insert(9);
    Object.PrintInOrder();
    std::cout << std::endl;
}
