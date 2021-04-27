#include <iostream>

int findMin(int x, int y) { //find min number
	if	(x <= y) return x;
	return y;
}

int findMax(int x, int y) { //find max number
	if (x >= y) return x;
	return y;
}

int calcSum(int x, int y) { //calculate sum of numbers
	return x+y;
}

int main()
{
	//initialization
	int a = 0, b = 0;
	int min = 0, max = 0, sum = 0;

	std::cout << "Insert a: ";
	std::cin >> a;
	std::cout << "Insert b: ";
	std::cin >> b;
	std::cout << "a: " << a << "	" << "b: " << b << std::endl;

	//functions call
	min = findMin(a,b);
	max = findMax(a,b);
	sum = calcSum(a,b);

	//answer output
	std::cout <<"Min: " << min << std::endl;
	std::cout <<"Max: " << max << std::endl;
	std::cout <<"Sum: " << sum << std::endl;

	return 0;
}

