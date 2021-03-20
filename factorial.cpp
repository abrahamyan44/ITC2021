#include <iostream>
#include <cctype>

long calcFactorialRecursive(long n) //recursive
{
	if (n == 0) return 1;
	return n * calcFactorialRecursive(n-1);
}
	
long calcFactorialIterative(long n)	//iterative
{
	long iter = 1;

	while (n) {
		iter *= n;
		--n;
	}
	return iter;
}

bool checkValidation(long n)
{
	if ( !n ) return false;  // not a number
	if (n < 0) return false; // negative
	return true;
}

int main()
{	
	//initialization
	ulong number = 0;
	ulong iternum = 0, recnum = 0;

	std::cout << "Input number: ";
	std::cin >> number;

	// check validation
	if (checkValidation(number)) {
	// if valid 
	recnum = calcFactorialRecursive(number);
	iternum = calcFactorialIterative(number);

	//output
	std::cout << "Recursive: " << recnum << std::endl;
	std::cout << "Iterative: " << iternum << std::endl;
	} else {
		std::cout << "Invalid input: ";
	}

	return 0;
}
