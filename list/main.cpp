#include <iostream>
#include "list.hpp"




int main() {

List<int> list1;
std::cout << "List size : " << list1.size()<< std::endl;
list1.insertBack(54);
list1.insertFront(67);
list1.insertFront(9);
list1.insertFront(100);
list1.insertFront(23);
std::cout << "List after insertion: ";
list1.print();
list1.erase(54);
std::cout << "List after delete: ";
list1.print();

	return 0;

};
