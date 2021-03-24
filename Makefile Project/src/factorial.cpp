
#include "factorial.hpp"
#include <cctype>

long calcFactorialRecursive(long n) //recursive
{
    if (n == 0) return 1;
    return n * calcFactorialRecursive(n-1);
}

bool checkValidation(long n)
{
    if ( !n ) return false;  // not a number
    if (n < 0) return false; // negative
    return true;
}

