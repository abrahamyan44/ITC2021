#include <iostream>
#include <exception>

using size_type = size_t;

template <class T>
class Vector
{
private:
    size_type m_size;
    size_type m_capacity;
    T* m_array;
public:
    Vector();
    Vector (size_type n);
    Vector (size_type size, T value);
    Vector (const Vector& vec);
    ~Vector();
    void PushBack (const T& val);
    void PopBack();
    size_type Size() const;
    size_type Capacity() const;
    bool Empty() const;
    void Reserve (size_type n);
    void ShrinkToFit();
    Vector& operator= (const Vector& x);
    T& operator[] (size_type n);
};

template <class T>
void Vector<T>::PushBack (const T& val) 
{
    if(m_size < m_capacity) {
        m_array[m_size] = val;
        ++m_size;
    } else {
        size_type old_capacity = m_capacity;
        m_capacity = 1.5 * old_capacity;
        T* n_array;
        n_array = new T[m_capacity];
        for (size_type i = 0; i < m_size; ++i) {
             n_array[i] = m_array[i];
        } n_array[m_size] = val;
        ++m_size;
        delete [] m_array;
        m_array = n_array;
	}
}

template <class T>
void Vector<T>::PopBack()
{
    if (m_size == 0) {
        throw std::invalid_argument("Vector is empty");
    } m_array[m_size-1] = 0;
    --m_size;
}

template <class T>
size_type Vector<T>::Size() const 
{
    return m_size;
}

template <class T>
size_type Vector<T>::Capacity() const
{
    return m_capacity;
}

template <class T>
bool Vector<T>::Empty() const
{
    return m_size == 0;
}

template <class T>
void Vector<T>::Reserve (size_type n) 
{
	if (m_size == 0) {
	    m_array = new T[n];
	    return;
	} m_capacity = n;
	T* array = m_array;
	m_array = new T[m_capacity];
	if (n < m_size) {
	    std::cout << "The last elements will be lost." << std::endl;
	    m_size = m_capacity;
        for (size_type i = 0; i < m_size; ++i) {
            m_array[i] = array[i];
        } delete [] array;
        return;	
	} else {
	    for (size_type i = 0; i < m_size; ++i) {
             m_array[i] = array[i];
        } delete [] array;
    }
}

template <class T>
void Vector<T>::ShrinkToFit()
{
   	m_capacity = m_size;
   	T* array = m_array; 
	m_array = new T[m_capacity];
	for (size_type i = 0; i < m_size; ++i) {
	    m_array[i] = array[i];
	} delete [] array;
	array = nullptr;
}

template <class T>
Vector<T>::Vector()
	:m_size(0),
	m_capacity(0),
	m_array(nullptr) {}

template <class T>
Vector<T>::Vector (const Vector& vec):
	m_size(vec.m_size),
	m_capacity(vec.m_capacity)
{
	m_array = new T[m_capacity];
	for (size_type i = 0; i < m_size; ++i) {
	    m_array[i] = vec.m_array[i];
	}
}

template <class T>
Vector<T>::Vector (size_type n):
    m_size(0),
    m_capacity(n)
{
    m_array = new T[m_capacity];
}

template <class T>
Vector<T>::Vector (size_type n, T value):
	m_size(n),
	m_capacity(1.5 * n)
{
	m_array = new T[m_capacity];
	for (size_type i = 0; i < m_size; ++i) {
        m_array[i] = value;
    }
}

template <class T>
Vector<T>::~Vector()
{
    delete [] m_array;
    m_array = nullptr;
}

template <class T>
T& Vector<T>::operator[] (size_type n)
{
    if (n < 0 || n >= m_size) {
        throw std::out_of_range("out of range");
    } else {
        return m_array[n];
    }
}

template <class T>
Vector<T>& Vector<T>::operator= (const Vector<T>& x) 
{
    if (this == &x) {
        return *this;
    } m_size = x.m_size;
    m_capacity = x.m_capacity;
    m_array = new T[m_capacity];
    for (size_type i = 0; i < m_size; ++i) {
        m_array[i] = x.m_array[i];
    } return *this;
}

