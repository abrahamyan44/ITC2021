#include <iostream>
#include <cctype>

long CalcFactorialRecursive(long n) //recursive
{
	if (n == 0) return 1;
	return n * CalcFactorialRecursive(n-1);
}
	
long CalcFactorialIterative(long n)	//iterative
{
	long iter = 1;

	while (n) {
		iter *= n;
		--n;
	}
	return iter;
}

bool CheckValidation(long n)
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
	if (CheckValidation(number)) {
	// if valid 
	recnum = CalcFactorialRecursive(number);
	iternum = CalcFactorialIterative(number);

	//output
	std::cout << "Recursive: " << recnum << std::endl;
	std::cout << "Iterative: " << iternum << std::endl;
	} else {
		std::cout << "Invalid input: ";
	}

	return 0;
}
