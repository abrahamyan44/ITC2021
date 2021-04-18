#include <iostream>
#include "Tree.hpp"

int main()
{
    int arr[]={1,2,3,4,5,6,7,8};
    Tree<int> Object(arr, 7);
    
    //Object.Preorder(); //NLR
    //std::cout << std::endl;
    
    Object.Inorder();  //LNR
    std::cout << std::endl;
    
    //Object.Postorder();    //LRN
    //std::cout << std::endl;

    //Tree<int> TMP;
    //TMP.Preorder();
    //std::cout << std::endl;

    //TMP.Insert(3);
    //TMP.Insert(4);
    //TMP.Insert(2);
    //TMP.Insert(7);
    //TMP.Insert(1);
    //TMP.Insert(9);
    //TMP.Inorder();
    //std::cout << std::endl;
}
