#include<iostream>
#include "stack_implementation.hpp"

int main()
{
    Stack l(4, 10);
    l.Push(5);
    l.Print();
    std::cout << l.Top() << std::endl;
    std::cout << l.Empty() << std::endl;
    std::cout << l.Size() << std::endl;
      
    return 0;
}
