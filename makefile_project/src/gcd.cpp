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
		int a, b;
                std::ofstream created_file("test_run/output.txt");
		while (finput >> a >> b)
		{
          created_file << gcd(a, b) << std::endl;
        }
		created_file.close();
	}
	finput.close();
        return 0;
}

