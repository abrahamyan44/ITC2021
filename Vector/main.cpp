#include <iostream>
#include "Vector.hpp"

int main()
{
    Vector<int> V1(10,3);
    Vector<int> V;
    std::cout << "-----V1------\n";
    V1.Print();

    V.PushBack(4);
    V.PushBack(6);
    V.PushBack(3);
    V.PushBack(8);
    V.PushBack(2);
    V.PushBack(5);
    V.PushBack(7);
    std::cout << "------V------\n";
    V.Print();
    
    
    V1.PopBack();
    V1.PopBack();
    V1.PopBack();
    std::cout << "-----V1------\n";
    V1.Print();
    std::cout << "V[4] = " << V[4] << std::endl;
    
    Vector<int> V1_copy;
    V = V1;
    V1_copy = V1;
    V1_copy.PushBack(10);
    V1_copy.PushBack(45);
    V1_copy.PushBack(11);
    std::cout << "\n------V1_copy------\n";
    V1_copy.Print();

}
