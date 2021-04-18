#include <iostream>
#include <cassert>
#include "Vector.hpp"

//Constructs an empty container, with no elements.
template <typename T>
Vector<T>::Vector()
    :m_array(nullptr)
    ,m_capacity(2)
    ,m_size(0)
{}

//Constructs a container with n elements.
//Each element is a copy of val.
template <typename T>
Vector<T>::Vector (int size, T number)
    :m_capacity(1.5 * size)
    ,m_size(size)
{
    m_array = new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        m_array[i] = number;
    }
}

//Constructs a container with a copy of 
//each of the elements, in the same order.
template <typename T>
Vector<T>::Vector (const Vector& other)
    :m_capacity(other.m_capacity)
    ,m_size(other.m_size)
{
    m_array = new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
       m_array[i] = other.m_array[i];
    }
}

//Destroys the container object.
template <typename T>
Vector<T>::~Vector()
{
    delete m_array;
    std::cout << "In destructor\n";
}

//Adds a new element at the end of the vector,
//after its current last element.
template <typename T>
void Vector<T>::PushBack(const T& value)
{
    if (m_size <= m_capacity && 0 != m_array) {
        m_array[m_size++] = value;
    } else {
        Reserve(1.5 * m_capacity);
        m_array[m_size++] = value;
    }
}

//Removes the last element in the vector, 
//effectively reducing the container size by one.
template <typename T>
void Vector<T>::PopBack()
{
    --m_size;
    if (m_capacity - m_size > 5) {
        ShrinkToFit();
    }
}

//Returns the number of elements in the vector.
template <typename T>
int Vector<T>::Size() const
{
    return m_size;
}

//Returns the size of the storage space 
//currently allocated for the vector.
template <typename T>
int Vector<T>::Capacity() const
{
    return m_capacity;
}

//Returns whether the vector is empty.
template <typename T>
bool Vector<T>::isEmpty() const
{
    if (0 > m_size && 0 ==m_array) {
        return true;
    } else {
        return false;
    }
}

//Requests that the vector capacity be at 
//least enough to contain n elements.
template <typename T>
void Vector<T>::Reserve(int new_capacity)
{
    m_capacity = new_capacity;
    T* temp_array = new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        temp_array[i] = m_array[i];
    }
    delete[] m_array;
    m_array = temp_array;
}

//Requests the container to reduce 
//its capacity to fit its size.
template <typename T>
void Vector<T>::ShrinkToFit()
{
    m_capacity = m_size;
    T* temp_array = new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        temp_array[i] = m_array[i];
    }
    delete[] m_array;
    m_array = temp_array;
}

//Assigns new contents to the container, replacing its 
//current contents, and modifying its size accordingly.
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other)
{
    if (&other == this) {
        return *this;
    }
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    delete[] m_array;
    m_array = new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        m_array[i] = other.m_array[i]; 
    }
    return *this;
}

//Returns a reference to the element at 
//position n in the vector container.
template <typename T>
T& Vector<T>::operator[](int index)
{
    assert(0 <= index && index < m_size);
    return m_array[index];
    //if (index < m_size) {
    //   return m_array[index];
    //} else {
    //    std::cout << "Passed wrong index.\n";
    //    return nullptr;
    //}
}

//Prints array
template <typename T>
void Vector<T>::Print()
{
    if (isEmpty()) {
        std::cout << "Vector is empty.\n";
        return;
    }
    for (int i = 0; i < m_size; ++i) {
        std::cout << m_array[i] << " ";
    }
    std::cout << std::endl;
}
