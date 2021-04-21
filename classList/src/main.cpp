#include "List.hpp"

int main()
{
	/* testing */
	
	List list(5,1); // call user ctor
    list.insert_front(1);
    list.insert_back(4);
	std::cout << "Print list:        ";
    list.print();
    std::cout << "Size of list:      " << list.get_size() << std::endl;
	
	List list2(list); // call copy ctor
	std::cout << "Print copy:        ";
	list2.print();
	
	List list3;
	list3 = list2; // call assignment op
	std::cout << "Print = :          ";
	list3.print();
	
	std::cout << "Invalid insert:    ";
    list.insert_after(2, 33); // invalid
	list.clear();
	std::cout << "Print empty list:  ";
	list.print();
	return 0;
}
