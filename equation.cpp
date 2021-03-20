#include <iostream>
#include <cmath>

void equation(int a, int b, int c, double& root1, double& root2)
{
	if (a == 0) {
		std::cout << "Invalid." << std::endl << std::endl;
        return;
    }

	double D = b*b - 4*a*c;

	if (D > 0) {
		root1 = (-b + sqrt(D)) / (2*a);
		root2 = (-b - sqrt(D)) / (2*a);
		std::cout << "Roots are real and different." << std::endl;
		std::cout << "root1 = " << root1 << ' ' << "root2 = " << root2 << std::endl;
    } else if (D == 0) {
	    root1 = -b / (2*a);
		root2 = root1;
		std::cout << "Roots are real and same." << std::endl;    
		std::cout << "root1 = root2 = " << root1 << std::endl;
    } else {
        root1 = -b / (2*a);
        root2 = sqrt(-D) / (2*a);
		std::cout << "Roots are complex and different."  << std::endl;
		std::cout << "root1 = " << root1 << ' ' << "root2 = " << root2 << std::endl;
	}
}

void test_equation(double a, double b, double c, double expRes1, double expRes2)
{	
	if (a == 0) {
		std::clog << "Invalid." << std::endl << std::endl;
		return;
	}
	if (a == 1 ) {
		std::clog << "testing equation:  " << "x^2 + " << b << "x + "
				  << c << " = 0" << std::endl;
	} else {
		std::clog << "testing equation:  " << a << "x^2 + " << b << "x + "
				  << c << " = 0" << std::endl;
	}

	double root1 = 0, root2 = 0;
	equation(a,b,c,root1,root2);

	if (root1 != expRes1 || root2 != expRes2) {
		std::cout << "Expected to get " << expRes1 << " " << expRes2
				  << " but got " << root1 << " " << root2 << std::endl
	   			  << std::endl;
	} else {
		std::cout << "ok" << std::endl << std::endl;
	}	
}

int main()
{
	//initialization
	int a = 0, b = 0, c = 0;
	double root1 = 0, root2 = 0;

	std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "Enter b: ";
    std::cin >> b;
    std::cout << "Enter c: ";
    std::cin >> c;

    equation(a,b,c,root1,root2);

	/*
	//for testing
	test_equation(1,7,12,-3,-4);
	test_equation(1,5,6,-2,-3);
	test_equation(1,2,1,-1,-1);
	test_equation(1,2,3,999,999); //invalid
	*/
	return 0;
}
