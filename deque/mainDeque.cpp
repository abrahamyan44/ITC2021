#include <iostream>
#include "LDeque.h"

int main() {
	LDeque<int> d;
	std::cout << d.size() << std::endl;
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);
	std::cout << d.size() << std::endl;
	std::cout << d.back();
    std::cout<<std::endl;
	return 0;


}
