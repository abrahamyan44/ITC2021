#include "gcd.hpp"

int GreatestCommonDivisor (int n, int m)
{
    if (n == 0) {
		return m;
	} else {
		return GreatestCommonDivisor (m % n, n);
	}
}

