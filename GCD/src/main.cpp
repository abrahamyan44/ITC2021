#include <iostream>
#include <fstream>
#include "gcd.hpp"

int main()
{
	int a = 0;
	int b = 0;
	std::ifstream inputfile;
	std::ofstream outputfile;
	outputfile.open("tst/output.txt");
	inputfile.open("tst/input.txt");
	if (outputfile.is_open() && inputfile.is_open()) {
			while (inputfile >> a >> b){
				outputfile << gcd(a, b) << std::endl;
		}
	} else {
		std::cout << "Unable to open." << std::endl;
	} outputfile.close();
	inputfile.close();

	return 0;
}
