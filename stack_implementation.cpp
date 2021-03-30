#include<iostream>

class Stack
{
private: 
    struct node {
        int data;
        node* next;
    };
    node* head;
    node* tail;

public: 
    Stack();
    Stack(int n, int val);
    void Push(const int&);
    int Size();
    void Print();
    void Pop();
    bool Empty();
    int Top();
    ~Stack();
};

//constructor
Stack::Stack()
{
    head = NULL;
    tail = NULL;
}

//constructor which creates stack with given number of elements and with given value
Stack::Stack(int n, int value)
{
    node* tmp = new node;
    tmp->data = value;
    tmp->next = NULL;
    head = tmp;
    tail = tmp;

    for (int i = 0; i < n - 1; i++) {
          Push(value);
    }
}

//Inserts element at the top of the stack 
void Stack::Push(const int& n)
{
    node* tmp = new node;
    tmp->data = n;
    tmp->next = NULL;

    if(head == NULL)
    {
        head = tmp;
        tail = tmp;
    } else {
        tail->next = tmp;
        tail = tmp;
    }
}

// Prints elements of the Stack
void Stack::Print()
{
    node* tmp;
    tmp = head;
    while(tmp != NULL)
    {
        std::cout << tmp->data << std::endl;
        tmp = tmp->next;
    }
}

//returns size of the stack
int Stack::Size()
{
    int count = 0;
    node* tmp;
    tmp = head;
    while(tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

//removes last element of the stack
void Stack::Pop()
{
     if(head == NULL){
         std::cout << "The stack is already empty ";
     } else if(head->next == NULL) {
       head = NULL;
     } else {
          node* tmp;
          tmp = head;
          while(tmp->next->next != NULL)
          {
              tmp = tmp->next;
          }
          delete tmp->next;

          tmp->next = NULL;
     }
}

//returns whether the stack is empty
bool Stack::Empty()
{
    return (head == NULL) ? true : false;
} 

//returns top element of the stack
int Stack::Top()
{
    if(head == NULL) {
        std::cout << "The stack is empty... " << std::endl;
    } else if(head->next == NULL) {
        return head->data;
    } else {
        node* tmp;
        tmp = head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        return tmp->data;
    }
}

//destructor
Stack::~Stack()
{
    node* tmp = head;
    node* nextNode;

    while (tmp != NULL) {
        nextNode = tmp->next;
        delete tmp;
        tmp = nextNode;
    }

}

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
