#include "stack.hpp"
using namespace std;

Stack::Stack()
{
    m_head = nullptr;
    m_tail = nullptr;
//    m_tail -> next = nullptr;
}

Stack::Stack(int size, int value)
{
//     node* temp = new node;
//     temp->data = value;
//     temp->next = nullptr;
//     m_head = temp;
//     m_tail = temp;
//     for (int i = 0; i < size - 1; i++) {
//         Push(value);
//     }

	for(int i = 0; i < size; ++i) {
		node* temp;
		temp->data = value;
		temp->next = nullptr;
		m_head = temp;
		m_tail = temp;
        }
	if (m_head == nullptr) {
		node* temp;
                temp->data = value;
                temp->next = nullptr;
                m_head = temp;
                m_tail = temp;
	} else {
	       node* temp = m_head;
               while (temp != nullptr) {
                     temp = temp->next;
               }
	       temp->data = value;
	       temp->next = nullptr;

	}
}

Stack::~Stack()
{
	cout << "Stack destructer" << endl;
	node* temp = new node;
    while (temp != nullptr) {
       cout << "destructer while" << endl;
	    temp = m_head;
        m_head = temp->next;
        delete temp;
    }
}

int Stack::Size() const
{
    int count = 0;
    node* temp = new node;
    temp = m_head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void Stack::Print() const
{
    node* temp = m_head;
    while (temp != nullptr) {
	
        std::cout << temp->data  << std::endl;
        temp = temp->next;
    }
}

void Stack::PrintStack()
{
	node* node;
	cout << "Stack::printstack" << endl;
    	while (node != NULL) {
cout << "Stack print while" << endl;
        std::cout << " " << node->data << std::endl;
        node = node->next;
    }
}

void Stack::Pop()
{
   cout << "Pop" << endl;
       	node* temp = new node;
    temp = m_head;
    if (m_head == nullptr) {
        std::cout << "Stack is empty" << std::endl;
    }
    else if (m_head->next == nullptr) {
        delete m_head;
	m_head = nullptr;
    }
    else {
        while (temp->next->next != nullptr) {
            temp = temp->next;
	    delete temp;
	    temp = nullptr;
        }
    }
    delete temp->next;
    temp->next = nullptr;
}

void Stack::Push(const int& value)
{
   cout << "Stack::push" << endl;
       	node* temp = new node;
    temp->data = value;
    temp->next = nullptr;
    if (m_head == nullptr) {
        m_head = temp;
        m_tail = temp;
    }
    else {
        m_tail->next = temp;
        temp = m_tail;
    }
}

bool Stack::Empty() const
{
cout << "Stack::Empty" << endl;
    	return m_head == nullptr;
}

int Stack::Top()
{
    if(m_head == nullptr) {
        std::cout << "The stack is empty" << std::endl;
    } else if(m_head->next == nullptr) {
        return m_head->data;
    } else {
        nodePtr temp;
        temp = m_head;
 cout << "Stack:Top" << endl;
     	node* temp = new node;
    temp = m_head;/*
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->data;*/
    }
}
    return temp->data;
}
