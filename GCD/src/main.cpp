#include <iostream>
#include <fstream>
#include "gcd.hpp"

int main()
{
	int num1 = 0;
	int num2 = 0;
	std::ifstream inputfile;
	std::ofstream outputfile;
	outputfile.open("tst/output.txt");
	inputfile.open("tst/input.txt");
	if (outputfile.is_open() && inputfile.is_open()) {
			while (inputfile >> num1 >> num2){
				outputfile << GreatestCommonDivisor(num1, num2) << std::endl;
		}
	} else {
		std::cout << "Unable to open." << std::endl;
	} outputfile.close();
	inputfile.close();
	return 0;
}
