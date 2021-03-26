#include <iostream>
#include "vector.h"



int main() {

	//List<int> list1;
	//std::cout << "List size : " << list1.size()<< std::endl;
	//list1.insertBack(54);
	//list1.insertFront(67);
	//list1.insertFront(9);
	//list1.insertFront(100);
	//list1.insertFront(23);
 //   std::cout << "List after insertion: ";

	////list1.print();
	//list1.erase(54);
 //   std::cout << "List after delete: ";
 //   //list1.print();

    Vector<int> v;
    Vector<char> v1;
    v.pushback(10);
    v.pushback(20);
    v.pushback(30);
    v.pushback(40);
    v.pushback(50);
    v1.pushback(71);
    v1.pushback(72);
    v1.pushback(73);
    v1.pushback(74);

    std::cout << "Vector size : " << v.getsize() << std::endl;
    std::cout << "Vector capacity : " << v.getcapacity() << std::endl;

    std::cout << "Vector elements : ";
    v.print();


    v.insert(100, 1);
    std::cout << "Vector after insertion : ";
    v.print();

    v.popback();
    v1.popback();

    std::cout << "Vector elements of type int after pop : ";
    v.print();
    std::cout << "Vector elements of type char after pop: ";
    v1.print();
	return 0;

};
