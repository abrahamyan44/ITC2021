#include <iostream>
#include <iomanip>
#include "stack.hpp"
using namespace std;

int main()
{
    int a = 1;
	Stack<int> Stack5;
	Stack<int> Stac(5,4);

	for (int i = 0; i < 5; ++i)//add a value in a stack
	{
        Stack5.Push(a);
		a += 1;
        std::cout << "Push " << a <<std::endl;
	}
    
	Stack<int> ST(Stack5);
    cout << ST.top() << "\n";
	while (!Stack5.isEmpty())
    {
        Stack5.Pop();
	}
    
    cout << Stack5.top() << "\n";
}
