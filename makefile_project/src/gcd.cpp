#include <iostream>
#include <fstream>

int gcd(int a, int b) {
        while (a != b) {
                if (a > b) {
                        a = a - b;
                } else {
                        b = b - a;
                }
        }
        return a;
}

int main() {
	std::fstream finput;
	finput.open("../../test/input.txt", std::ios::in);
	if (!finput) {
		std::cout << "No such file";
	}
	else {
		std::fstream my_file;
				int a, b;
		while (finput >> a >> b)
		{
			my_file.open("../test_run/output.txt", std::ios::out);
			if (!my_file) {
				std::cout << "File not created!";
       		        }
			my_file << gcd(a, b);
		}
		my_file.close();
	}
	finput.close();
        return 0;
}

