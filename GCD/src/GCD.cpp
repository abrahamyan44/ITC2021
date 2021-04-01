#include <iostream>
#include "GCD.hpp"

int GCD(int a, int b)
{
    if(a < 0 || b < 0)
    {
        a = abs(a);
        b = abs(b);
    }
    if(a == b)
        return a;
    while(a != b)
    {
        if(a < b)
            b -= a;
        else
            a -= b;
    }
    return a;
}
