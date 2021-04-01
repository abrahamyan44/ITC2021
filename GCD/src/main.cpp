#include <iostream>
#include <fstream>
#include "GCD.hpp"


int main()
{
    std::ifstream inputFile;
    std::ofstream outputFile;
    outputFile.open("tst/output.txt");
    inputFile.open("tst/input.txt");
    int x, y;
    while(inputFile >> x >> y)
    {
        //std::cout << x << ", " << y << "  GCD = " << GCD(x,y) << std::endl;
        outputFile << GCD(x, y) << '\n';
    }
    outputFile.close();
    inputFile.close();
}
