#define INTEGER int

#include <cassert>
#include "gcd.hpp"

INTEGER gcd(INTEGER a, INTEGER b) {
        while (a != b) {
                if (a > b) {
                        a = a - b;
                } else {
                        b = b - a;
                }
        }
        return a;
}

