template <class T>
struct node
{
    T data;
    node <T>* link;
    node (const T& value = T(), Node <T>* next = 0)
    {
        data = value;
        link = next;
    }
};

template <class T>
class Stack {
private:
    node <T>* m_top;
    int m_size;

public:
    Stack(); //empty stack with no elements
    Stack(const T& value, int count); //stack with 'count' elements, each is a copy of value
    Stack(const Stack <T>& other_stack); //copy constructor
    ~Stack();

    void Pop(); //removes the element on top of the stack, reducing the size by one
    void Push(const T& value); //inserts a new element at the top of the stack, above its current top element.
    
    int GetSize() const; //number of elements in the stack
    bool IsEmpty() const; //checks if the stack is empty or not
    T& GetTop(); //returns the reference to the top element in the stack
    void Print(); //prints stack's elements
};
