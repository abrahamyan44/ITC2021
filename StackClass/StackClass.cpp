#include <iostream>
#include "StackClass.hpp"
using namespace std;

// Default constructor
template <class T>
StackClass<T>::StackClass() {
    m_top = nullptr;
    m_size = 0;
}

// Fill constructor
template <class T>
StackClass<T>::StackClass(int count, T* values) {
    m_size = 0;
    m_top = nullptr;
    for (int i = 0; i < count; ++i) {
       Push(values[i]);  
    }
}

// Copy constructor
template <class T>
StackClass<T>::StackClass(const StackClass&) {
  
}

// Destructor
template <class T>
StackClass<T>::~StackClass() {
    Node* node = m_top;
    while (node != nullptr) {
        Node* new_node = node;
        node = node->link;
        delete new_node;
    }
}

// Removes the element from the top of the stack
template <class T>
void StackClass<T>::Pop() {
    if (IsEmpty()) {
        return;
    }
    Node* node = m_top;
    m_top = m_top->link;
    delete node;
    m_size--;
}

// Inserts a new element at the top of the stack
template <class T>
void StackClass<T>::Push(T data) {
    Node* node = new Node(data);
    node->link = m_top;
    m_top = node;
    m_size++;
}

// Returns the number of elements in the stack
template <class T>
int StackClass<T>::GetSize() const {
    return m_size;
}

// Returns whether the stack is empty
template <class T>
bool StackClass<T>::IsEmpty() const {
    return m_size == 0;
}

// Returns a reference to the top element in the stack
template <class T>
T StackClass<T>::Top() {
    return IsEmpty() ? NULL : m_top->value;
}

// Print
template <class T>
void StackClass<T>::Print() {
    Node* node = m_top;
    while (node != nullptr) {
        cout << node->value << " ";
        node = node->link;
    }
    cout << endl;
}

int main() {
    int array[] = {5, 7, 54, 41, 36};
    StackClass<int> stack(5, array);
    cout << "Our stack looks like: " << endl;
    stack.Print();
    cout << "Deleting last two elements." << endl;
    stack.Pop();
    stack.Pop();
    stack.Print();
    cout << "Add one element." << endl;
    stack.Push(83);
    stack.Print();
    cout << "The size of stack is: " << stack.GetSize() << endl;

    return 0;
}
