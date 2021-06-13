#include <iostream>
#include <cassert>

template <class T>
class Stack{
public:
    class Node {
        public:
        int value;
        Node* next;
        Node* prev;
        Node(int v = 0){
            value = v;
            next = nullptr;
            prev = nullptr;
		}
    };
    Node* m_first;
    Node* m_last;
    int m_size;
    Stack();
	Stack(int n , const T& val);
    ~Stack();
    void pop();
    void push(T);
    T top();
    bool empty() const;
    void clear();
	int size();
    void print();
};

template <class T>
Stack<T>::Stack(){
   m_size = 0;
   m_first = nullptr;
   m_last = nullptr;
}

template <class T>
int Stack<T>::size(){
	return m_size;
}

template <class T>
Stack<T>::Stack(int n , const T&  val){
	m_first = new Node(val);
	Node* p =m_first;
	for (int i=0; i < n-1; i++) {
		Node* current = new Node(val);
		p->next = current;
		current->prev=p;
		p = p->next;
    }
	m_last = p;
	m_size = n;
}


template <class T>
Stack<T>::~Stack(){
    clear();
}

template <class T>
void Stack<T>::pop(){
	if(empty()){
		return;
	}
    Node *temp = m_last;
    m_last = m_last->prev;
    delete temp;
	m_last->next = nullptr;
	m_size--;
}

template <class T>
void Stack<T>::push(T v){
    Node* p = new Node(v);
    if (empty()) {
        m_first = m_last = p;
        return;
    }
    m_last->next = p;
    p->prev = m_last;
    m_last = p;
	m_size++;
}

template <class T>
T Stack<T>::top(){
    return m_last->value;
}

template <class T>
bool Stack<T>::empty() const{
    if (m_first == nullptr) {
        assert(m_last == nullptr);
        return true;
    }
    return false;
}

template <class T>
void Stack<T>::clear(){
    if (empty()) {
        return;
    }
    Node* p = m_first;
    while (p) {
        Node* t = p;
        p = p->next;
        delete t;
    }
}


template <class T>
void Stack<T>::print(){
    for (const Node* p = m_first; p != nullptr; p = p->next) {
        std::cout << p->value << ' ';
    }
    std::cout<< '\n';
}


int main(){
    Stack<int> l1;
	l1.push(3);
	l1.push(4);
	l1.push(5);
	l1.print();
	l1.pop();
    l1.print();
	Stack<int> l2(3,5);
	l2.print();
	std::cout<<l2.size()<<std::endl;
    return 0;
}
