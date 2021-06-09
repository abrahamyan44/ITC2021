#include "stack.hpp"

int main() {
    Stack s(2, 4);
    std::cout << "The stack is " << std::endl;
    s.Print();
    std::cout << "The stack after push method " << std::endl;
    s.Push(6);
    s.Print();
    std::cout << "the top element is: " <<  s.Top() << std::endl;

    return 0;
}
