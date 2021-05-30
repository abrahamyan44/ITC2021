#include <iostream>

template <class T>
class Vector 
{
private:
    T* m_arr;  //pointer which stores the address of our vector
    int m_capacity;  //capacity of the vector
    int m_size;  //the current size of the vector

public:
    Vector();  //initalizing capacity for 1 element and allocating dynamic storage
    Vector(T value, int number); //constructs a container with number elements
    Vector(const Vector <T>& x); //copy constructor
    Vector <T>& operator=(const Vector <T>& x); //assignment operator
    T& operator[](int index); //access to elements
    void pushBack(T data);  //for adding elements at the last
    void push(T data, int index);  //for adding elements at any index
    T getElement(int index);  //for getting the element at any index
    void popBack();  //for deleting the last element
    bool isEmpty() const; //returns whether the vector is empty or not 
    int getSize() const;  //for getting the size of the vector
    int getCapacity() const;  //for getting the capacity of the vector
    void reserve(int new_capacity); //requests the vector to contain at least n elements 
    void shrinkToFit(); //requests the vector to reduce its capacity to fit its size
    void print();  //for printing the elements of the vector
    ~Vector(); //destructor
};
