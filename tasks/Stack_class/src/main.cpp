#include <iostream>
#include "stack.cpp"


int main(){
	Stack<int> a;
	a.print();
	std::cout<<std::endl;
	a.push(56);
	a.push(5215);
	a.push(1777);
	std::cout<<"stack a after push elements"<<"\n";
	a.print();
	std::cout<<std::endl;
	a.pop();
	std::cout<<"stack a after call pop() function"<<"\n";
	a.print();
	std::cout<<"----------------------"<<std::endl;
	Stack<int> b(a);
	std::cout<<"stack b"<<"\n";
	b.print();
	std::cout<<std::endl;	
	std::cout<<"a.top()"<<"\n";
	std::cout<<a.top();
	std::cout<<std::endl;
}
