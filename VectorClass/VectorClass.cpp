#include <iostream>
#include <cassert>
#include "VectorClass.hpp"
using namespace std;

// Default constructor
template <class T> 
VectorClass<T>::VectorClass()
{
    m_array = new T[1];
    m_capacity = 1;
    m_quantity = 0;
}

// Copy constructor
template <class T>
VectorClass<T>::VectorClass(const VectorClass<T>& answer)
{
    m_quantity = answer.m_quantity;
    m_capacity = answer.m_capacity;
    T* m_array = new T[m_capacity];
    for (int i = 0; i < m_quantity; ++i) {
        m_array[i] = answer.m_array[i];
    }
}

// Fill constructor
template <class T>
VectorClass<T>::VectorClass(const int count, T* value)
{
    m_capacity = 2 * count + 1;
    m_quantity = count;
    T* m_array = new T [m_capacity];
    for (int i = 0; i < m_quantity; ++i) {
        m_array[i] = value;
    }
}

// Destructor
template <class T>
VectorClass<T>::~VectorClass()
{
    delete [] m_array;
}
 
// Function to add an element at the last
template <class T>
void VectorClass<T>::PushBack(const T& data)
{
    if (m_quantity >= m_capacity) {
        Reserve(m_capacity + m_capacity);  
    }
    m_array[m_quantity] = data;
    m_quantity++;
}
    
// Function to add element at any index
template <class T>
void VectorClass<T>::Push(int data, int index)
{ 
    if (index >= m_quantity) {
        for (int i = m_quantity; i < index; ++i) {
            PushBack(0);
        }
        PushBack(data);
        return;
    }
    PushBack(m_array[m_quantity - 1]);
    for (int i = m_quantity - 2; i >= index; --i) {
        m_array[i + 1] = m_array[i];
    }
    m_array[index] = data;
}
    
// Function to extract element at any index
template <class T>
T VectorClass<T>::GetElement(int index)
{
    if (index < m_quantity && index >= 0) {
        return m_array[index];
    }
    return 0;
}
    
// Function to delete last element
template <class T>
void VectorClass<T>::PopBack()
{
    if (m_quantity > 0) {
        m_quantity--;
    }
}
 
// Function to get size of the vector
template <class T>
int VectorClass<T>::GetSize() 
{
    return m_quantity;
}
 
// Function to get capacity of the vector
template <class T>
int VectorClass<T>::GetCapacity() 
{
    return m_capacity;
}
 
// Check if the array is empty
template <class T>
bool VectorClass<T>::IsEmpty()
{
    return m_quantity == 0;
}

// Requests that the vector capacity be at least enough to contain n elements
template <class T>
void VectorClass<T>::Reserve(int new_capacity)
{
    if (m_quantity < m_capacity) {
        return;
    }
    else {
        T* new_array = new T[new_capacity];  
        for (int i = 0; i < m_quantity; ++i) {
            new_array[i] = m_array[i];
        }
        delete[] m_array;
        m_array = new_array;
        m_capacity = new_capacity;
    }
}

// Requests the container to reduce its capacity to fit its size
template <class T>
void VectorClass<T>::ShrinkToFit()
{
    T* new_array = new T[m_quantity];
    for (int i = 0; i < m_quantity; ++i) {
        new_array[i] = m_array[i];
    }
    delete[] m_array;
    m_array = new_array;
    m_capacity = m_quantity;
}

// Assigns new contents to the container, replaces current contents and modifies size too
template <class T>
VectorClass<T>& VectorClass<T>::operator=(const VectorClass& equal)
{
    if (this == &equal) {
        return *this;
    }
    if (!IsEmpty()) {
        delete[] m_array;
    }
    m_quantity = equal.m_quantity;
    m_capacity = equal.m_capacity;
    m_array = new T[m_capacity];
    for (int i = 0; i < m_quantity; ++i) {
        m_array[i] = equal.m_array[i];
    }
    return *this;
}

// Returns a reference to the element at position n in the vector container.
template <class T>
T& VectorClass<T>::operator[](unsigned int index)
{
    if (index < m_quantity) {
       return m_array[index];
    }
}

// Function to print array's elements
template <class T>
void VectorClass<T>::Print()
{
    for (int i = 0; i < m_quantity; i++) {
        cout << m_array[i] << " ";
    }
    cout << endl;
}
 
int main()
{
    VectorClass<int> vector;
    vector.Push(10,1);
    vector.Push(20,2);
    vector.Push(30,5);
    vector.Push(40,6);
    vector.Push(50,3);
    cout << "Vector size : " << vector.GetSize() << endl;
    cout << "Vector capacity : " << vector.GetCapacity() << endl;
    cout << "Vector elements : ";
    vector.Print();  
    vector.Push(100, 20);
    cout << "\nAfter updating 1st index" << endl;
    cout << "Vector elements of type int : " << endl;
    vector.Print();
    cout << "Element at 1st index of type int: " << vector.GetElement(1) << endl;
    vector.PopBack();
    cout << "\nAfter deleting last element" << endl;
    cout << "Vector size of type int: " << vector.GetSize() << endl;
    cout << "Vector capacity of type int : " << vector.GetCapacity() << endl;
    cout << "Vector elements of type int: ";
    vector.Print();
    
    return 0;
}
