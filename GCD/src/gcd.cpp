#include "gcd.hpp"

int GreatestCommonDivisor (int number1, int number2)
{
    if (number1 == 0) {
        return number2;
    } else {
	    return GreatestCommonDivisor (number2 % number1, number1);
    }
}

