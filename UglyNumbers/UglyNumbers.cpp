#include <iostream>
#include "UglyNumbers.hpp"

int DivideTillEnd(int number1, int number2) {
    while (number1 % number2 == 0) {
        number1 /= number2;
    }
    return number1;
}

bool IsUglyNumber(int number) {
    number = DivideTillEnd(number, 2);  
    number = DivideTillEnd(number, 3);
    number = DivideTillEnd(number, 5);
    return (number == 1) ? true : false;
}

int GetNthUglyNumber(int number) {
    int count = 1;
    int i = 1;
    while (number > count) {
        i++;
        if (IsUglyNumber(i)) {
            count++;
        }
    }
    return i;
}

int main() {
    int number;
    std::cin >> number;
    std::cout << number << "th ugly number is " << GetNthUglyNumber(number) << std::endl;
    return 0;
}
