#include <iostream>

int IfNumberIsUgly(int value) {
	while (value != 1) {
		if (value % 2 == 0) {
			value /= 2;
		} else if (value % 3 == 0) {
			value /= 3;
		} else if (value % 5 == 0) {
			value /= 5;
		} else {
			break;
		}
	}
	if (value == 1) {
		return 1;
	} else {
		return -1;
	}
}

int CountUglyNumbers(int number) {
	int count = 1;
	for (int i = 2; i <= number; ++i) {
		if (IfNumberIsUgly(i) == 1) {
			count++;
		}
	}
	return count;
}	

int main() {
	int number;
	std::cout << "Enter any number: ";
	std::cin >> number;
	std::cout << "The number of Ugly Number is: " << CountUglyNumbers(number);
	std::cout << std::endl;

	return 0;
}
