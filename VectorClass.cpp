#include <iostream>
#include "VectorClass.hpp"

template <class T>
Vector <T>::Vector() : m_capacity(10), m_size(0)
{
    m_arr = new T[10];
}

template <class T>
Vector <T>::Vector(T value, int number) : m_size(number), m_capacity(10 + number)
{
    m_arr = new T[m_capacity];
    for (int i=0; i < number; i++)
    {
        m_arr[i] = value;
    }
}

template <class T>
Vector <T>::Vector(const Vector <T>& x) 
{
    m_size = x.m_size;
    m_capacity = x.m_capacity;
    m_arr = new T[m_capacity]; 
    for (int i=0; i < m_size; i++)
    {
        m_arr[i] = x.m_arr[i];
    }
}

template <class T>
Vector <T>& Vector <T>::operator=(const Vector <T>& x)
{
    if (x.m_size <= m_capacity)
    {
        for (int i=0; i < x.m_size; i++)
        {
            m_arr[i] = x.m_arr[i];
            m_size = x.m_size;
            return *this;
        }
    }
    else
    {
        T* temp = new T[x.m_size];
        for (int i=0; i < x.m_size; i++)
        {
            temp[i] = x.m_arr[i];
        }
        delete[] m_arr;
        m_size = x.m_size;
        m_capacity = x.m_size;
        m_arr = temp;
        return *this;
    }
}

template <class T>
T& Vector <T>::operator[](int index)
{
    return m_arr[index];
}

template <class T>
void Vector <T>::pushBack(T data)
{
    if (m_size == m_capacity)
    {
        T* temp = new T[10 + m_capacity]; //allocating new array
        for (int i=0; i < m_size; i++)
        {
            temp[i] = m_arr[i];
        }
        delete[] m_arr; //deleting old array
        m_capacity *= 2;
        m_arr = temp; //our new array is temp
    }
    m_arr[m_size] = data;
    m_size++;
}

template <class T>
void Vector <T>::push(T data, int index)
{
    if (index == m_capacity)
    {
        pushBack(data);
    }
    else
    {
        m_arr[index] = data;
    }
}

template <class T>
T Vector <T>::getElement(int index)
{
    if (index < m_size) //if everything is normal
    {
        return m_arr[index];
    }
}

template <class T>
void Vector <T>::popBack()
{
    m_size--;
}

template <class T>
bool Vector <T>::isEmpty() const
{
    return (m_size == 0);
}

template <class T>
int Vector <T>::getSize() const
{
    return m_size;    
}

template <class T>
int Vector<T>::getCapacity() const
{
    return m_capacity;
}

template <class T>
void Vector <T>::reserve(int new_capacity)
{
    if (new_capacity <= m_capacity)
    {
            return;
    }
    T* temp = new T[new_capacity];
    for (int i=0; i < m_size; i++)
    {
            temp[i] = m_arr[i];
    }
    delete[] m_arr;
    m_arr = temp;
    m_capacity = new_capacity;
}

template <class T>
void Vector <T>::shrinkToFit()
{
    if(m_capacity == m_size)
    {
        return;
    }
    else
    {
        T* temp = new T[m_size];
        for (int i=0; i < m_size; i++)
        {
            temp[i] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = temp;

        m_capacity = m_size;
    }
}

template <class T>
void Vector<T>::print()
{
    for (int i=0; i < m_size; i++)
    {
        std::cout << m_arr[i] << " ";
    }
    std::cout << std::endl; 
}

template <class T>
Vector <T>::~Vector()
{
    std::cout << "Object destructed!" << std::endl;
    delete[] m_arr;
}

int main()
{
    Vector <int> v1;
    v1.pushBack(1);
    v1.pushBack(2);
    v1.pushBack(3);
    v1.pushBack(4);
    Vector <int> v2(9,10);
    std::cout << "v2 vector's elements are: ";
    v2.print();
    Vector <int> v3(v2);
    v3.print();
    if (!v3.isEmpty()) 
    {
        std::cout << "The v3 vector is not empty." << std::endl;
    }
    
    v3.reserve(12);
    std::cout << "Reserved capacity is: " << v3.getCapacity() << std::endl;
    std::cout << "Reserved size is: " << v3.getSize() << std::endl;
    v3.print();

    v3.shrinkToFit();
    std::cout << "Shrinked capacity is: " << v3.getCapacity() << std::endl;
    std::cout << "Shrinked size is: " << v3.getSize() << std::endl;
    v3.print();

    Vector <int> v4 = v2;
    std::cout << "v4 vector's elements are assigned as v2's elements: " << std::endl;
    v4.print();

    for (int i=0; i < v1.getSize()/2; i++)
    {
        int temp;
        temp = v1[v1.getSize()-i-1];
        v1[v1.getSize()-i-1] = v1[i];
        v1[i] = temp;
    }
    std::cout << "Reversed v1 vector: " << std::endl;
    v1.print();
    

    std::cout << "Vector size is: " << v1.getSize() << std::endl;
    std::cout << "Vector capacity is: " << v1.getCapacity() << std::endl;
    std::cout << "Vector elements are: ";
    v1.print();

    v1.push(9,3);
    std::cout << "Vector elements after updating: ";
    v1.print();
    v1.popBack();
    std::cout << "Vector elements after updating: ";
    v1.print();    
    
    return 0;
}



