#include <iostream>
#include <fstream>
#include "gcd.hpp"

int main()
{
	int number1 = 0;
	int number2 = 0;
	std::ifstream inputfile;
	std::ofstream outputfile;
	outputfile.open("tst/output.txt");
	inputfile.open("tst/input.txt");
	if (outputfile.is_open() && inputfile.is_open()) {
	    while (inputfile >> number1 >> number2) {
	        outputfile << GreatestCommonDivisor(number1, number2) << std::endl;
	    }
    } else {
	    std::cout << "Unable to open." << std::endl;
    } 
    outputfile.close();
    inputfile.close();
	return 0;
}
