#include "gcd.hpp"

int gcd (int n, int m)
{
    if (n == 0) {
		return m;
	} else {
		return gcd (m % n, n);
	}
}

