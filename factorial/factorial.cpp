#include <iostream>
#include <cassert>
#include <exception>
#include <stdexcept>
#include "factorial.h"


ul RecursiveFactorial (const int& num) {
	if (num < 0) {
		throw std::runtime_error ("Please enter non negative number.");
	} if (num >= 20) {
		throw std::out_of_range ("It is not possible to count.");
	} else {
		if (num == 0) {
			return 1;
		} else {
			return num*RecursiveFactorial(num - 1);
		}
	}
}

ul IterativeFactorial (const int& num) {
	if (num < 0) {
        throw std::runtime_error ("Please enter non negative number.");
    } if (num >= 20) {
        throw std::out_of_range ("It is not possible to count.");
    } ul factorial = 1;
	if (num < 2) {
	   	return 1;
	} else { 
		for (int i = 1; i <= num; ++i) {
			factorial *= i;
		} return factorial;	
	}
}

int main () 
{
	int number = 0;
	std::cout << "Enter number:" << std::endl;
	std::cin >> number;
	try {
		ul factorial = RecursiveFactorial(number);
	    std::cout << "recursive_factorial: " << number << "!=" << factorial << "\n";
	    std::cout << "iterative_factorial: " << number << "!=" << IterativeFactorial(number) << "\n";
	} catch (std::runtime_error& ex_for_negative) {
		std::cout << ex_for_negative.what() << std::endl;
	} catch (std::out_of_range& ex_greater_range) {
        std::cout << ex_greater_range.what() << std::endl;
    } catch (std::exception& std_ex) {
		std::cout << "std::exception" << std::endl;
	} catch (...) {
		std::cout << "another exception" << std::endl;
	}
	return 0;
}
