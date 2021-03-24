#include <fstream>
#include "factorial.hpp"

using namespace std;

void test()
{
	fstream inputf;
	inputf.open("tst/input.txt", ios::in);

	// Check if the file opened
	if (!inputf) {
		cerr << "No file: 1";
		exit (1);
	}

	ulong  number;
    ofstream createdf("tst_run/output.txt");

	while (inputf >> number) {
      createdf <<  calcFactorialRecursive(number) << endl;
	  cout << calcFactorialRecursive(number) << endl;
    }

	createdf.close();
	inputf.close();
}

int main()
{
	test();
    return 0;
}
