#include <iostream>
#include "gcd.hpp"

ll gcd (ll a, ll b) {
	return b == 0 ? a : gcd (b, a % b);
}	

int main (int argc, char* argv[]) {
	ll a, b;
	if(argc < 2) {
		std::cin >> a >> b;
	}
	else {
		a = atoi(argv[1]);
		b = atoi(argv[2]);
	}
	std::cout << gcd (a,b) << "\n";
		
	return 0;
}
