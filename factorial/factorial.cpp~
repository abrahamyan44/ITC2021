#include <iostream>
#include <cassert>
#include <exception>
#include <stdexcept>
#include "factorial.h"



ul Recursive_Factorial (const int& n) {
	if (n < 0) {
		throw std::runtime_error ("Please enter non negative number.");
	} if (n >= 20) {
		throw std::out_of_range ("It is not possible to count.");
	} else {
		if (n == 0) return 1;
		else return n*Recursive_Factorial(n - 1);
	}
}

ul Iterative_Factorial (const int& n) {
	ul f = 1;
	if (n == 0 || n == 1) return 1;
	else 
		for (int i = 1; i <= n; ++i) {
			f *= i;
		} return f;	
}

int main () {

	int n;
	std::cout << "Enter number:" << std::endl;
	std::cin >> n;
	try {
		ul r = Recursive_Factorial(n);
	std::cout << "recursive_factorial: " << n << "!=" << r << "\n";
	std::cout << "iterative_factorial: " << n << "!=" << Iterative_Factorial(n) << "\n";
	} catch (std::runtime_error& ex) {
		std::cout << ex.what() << std::endl;
	} catch (std::out_of_range& e) {
                std::cout << e.what() << std::endl;
        } catch (std::exception& c) {
		std::cout << "std::exception" << std::endl;
	} catch (...) {
		std::cout << "another exception" << std::endl;
	}

	return 0;
}
