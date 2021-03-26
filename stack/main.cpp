#include "stack.hpp"

int main()
{

Stack<int> stack1 = Stack<int>();
stack1.push(2);
stack1.push(11);
stack1.push(42);
stack1.push(9);
stack1.push(61);
stack1.print();
std::cout << "Size : " << stack1.getsize() << std::endl;
stack1.pop();
stack1.pop();
std::cout << "Size after pop : " << stack1.getsize() << std::endl;
std::cout << stack1.empty() << std::endl;

return 0;
};
