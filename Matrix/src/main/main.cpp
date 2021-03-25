#include <iostream>
#include "../class/Matrix.hpp"

int main(int argc, char* argv[])
{
    int size;
    std::cout << "size = "; std::cin >> size;
    
    Matrix M1(size);
    M1.print();
    
    std::cout << "\nAssignment operator.\n";
    Matrix M2 = M1;
    M2.print();

    std::cout << "\nAddition operator.\n";
    Matrix M3;
    M3 = M2 + M1;
    M3.print();
    
    std::cout << "\nSubtraction operator.\n";
    Matrix M4;
    M4 = M2 - M1;
    M4.print();

    std::cout << "\nMultiplying a matrix by another matrix.\n";
    Matrix M5;
    M5 = M3 * M1;
    M5.print();

    std::cout << "\nMultiplying a matrix by constant number.\n";
    Matrix M6;
    M6 = M3 * 3;
    M6.print();
}
