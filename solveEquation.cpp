#include <iostream>
#include <cmath>

void solveEquation(double a, double b, double c){

	double discrim = (b*b - 4*a*c);
	double x1,x2 = 0; 
	if( discrim == 0 ) //If the discriminate is zero
	{
   		x1 = x2 = ( -1*b ) / (2 * a);
   		std::cout << "The equation has only one solution:  " << x1 << std::endl;
	}

	else if(discrim > 0) //If discriminate is greater then zero
	{
	   	 x1 = ( -1*b + sqrt(discrim) ) / (2 * a);
	   	 std::cout << "The first solution is: " << x1 << std::endl;
	   	 x2 = ( -1*b - sqrt(discrim) ) / (2 * a);
	    	 std::cout << "The second solution is: " << x2 << std::endl;
	}
	else{
	
		std::cout << "Discriminate is less then zero! Eqation has no solution!" << std::endl;	

	}

}

int main(){

	double a, b, c;
	std::cout << "Enter a: ";
	std::cin >> a;
	std::cout << "Enter b: ";
	std::cin >> b;
	std::cout << "Enter c: ";
	std::cin >> c;
	solveEquation(a,b,c);



};
