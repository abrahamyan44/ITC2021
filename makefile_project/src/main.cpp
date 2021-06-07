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
	finput.open("test/input.txt", std::ios::in);
	if (!finput) {
		std::cout << "No such file";
	}
	else {
		std::fstream my_file;
				int a, b;
                std::ofstream MyFile("test_run/output.txt");
		while (finput >> a >> b)
		{
          MyFile << gcd(a, b) << std::endl;
        }
		MyFile.close();
	}
	finput.close();
        return 0;
}
