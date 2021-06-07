#include "stack.hpp"

int main() {
    Stack s(4, 3);
    cout << "s" << endl;
    s.Push(4);
    cout << "push"<< endl;
    s.Push(5);
    s.Print();

    return 0;
}
