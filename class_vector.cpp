#include <iostream>
#include <cassert>

using namespace std;

template <class T>
class Vector {
private:
	size_t m_size;
	size_t m_capacity;
	T* m_data;

public:
Vector();

Vector(const Vector& x);
Vector(size_t size, const T& value);

~Vector();

void push_back (const T& val);

void pop_back ();

size_t size() const;

size_t capacity() const;

bool empty() const;

void reserve (size_t n);

void shrink_to_fit();


Vector<T>& operator = (const Vector& x);

const T& operator[] (size_t n);

void print(); 
};

template <class T>
Vector<T>::Vector()
{
	m_size = 0;
	m_capacity = 0;
	m_data = nullptr;
}


template <class T>
Vector<T>:: Vector (const Vector& x)
{
	m_size = x.m_size;
	m_capacity = x.m_capacity;
	m_data = new T [m_size];
	for(size_t i = 0; i < m_size; i++) {
		 m_data[i] = x.m_data[i];
	}
}

template <class T>

Vector<T>::Vector(size_t size, const T& value)
{
	m_size = size;
	m_capacity = size;
	m_data = new T [size];
	for(size_t i = 0; i < m_size; i++) {
		m_data[i] = value;
	}
}

template <class T>
Vector<T>::~Vector() 
{
	delete[] m_data;
	m_data = nullptr;
	assert(nullptr == m_data);
}


template <class T>
void Vector<T>::shrink_to_fit() 
{
	size_t new_capacity = m_size;
	T* new_block = new T(new_capacity);
	assert(new_block != nullptr);
	for(int i = 0; i < m_size; i++) {
		new_block[i] = m_data[i];
	}
	delete[] m_data;
	m_data = nullptr;
	assert(m_data == nullptr);

	m_data = new_block;
	m_capacity = new_capacity;
}


template <class T>
void Vector<T>::reserve(size_t n) 
{
	T* new_block = new T(n);
	assert(nullptr != new_block);
	
	for(int i = 0; i < m_size; i++) {
		new_block[i] = m_data[i];
	}

	delete[] m_data;
	m_data = nullptr;
	assert(m_data == nullptr);
	
	m_capacity = n;
	m_data = new_block;
}


template <class T>
void Vector<T>::push_back(const T& val)
{
	if(m_size >= m_capacity) {
	reserve(m_capacity + m_capacity/2 );
	}
	
	m_data[m_size] = val;
	m_size++;
}

template <class T>
void Vector<T>::pop_back()
{
	cout << "Have to remove " << m_data[m_size-1] << endl; 
/*	delete m_data[m_size-1];
	m_data[m_size-1] = nullptr;
	assert(m_data[m_size - 1] == nullptr); */
	m_size --;
	m_size --;
}

template <class T>
size_t Vector<T>::size() const
{
	size_t size = m_size - 1;
	return size;
}


template <class T>
size_t Vector<T>::capacity() const 
{
	//size_t capacity = m_capacity;
	return m_capacity;
}


template <class T>
bool Vector<T>::empty() const
{
	return m_size == 0;
}


template <class T>
const T& Vector<T>:: operator[] (size_t n)
{
	if(n >= m_size) {
		size_t size = m_size;
		assert(n < size);
	}
		return m_data[n]; 
}

template <class T>

Vector<T> & Vector<T>:: operator = (const Vector& x)
{
	delete[] m_data;
	m_size = x.m_size;
	m_capacity = x.m_capacity;
	m_data = new T[m_size];
	for(size_t i = 0; i < m_size; i++) {
		m_data[i] = x.m_data[i];
	}
	return *this;
}


template <class T>
void Vector<T>:: print() 
{
	for(size_t i = 0; i <= m_size; i++) {
		cout << m_data[i] << endl;;
	} 
}

int main() 
{
	Vector<int> vector;

	vector.push_back(5);
	vector.push_back(7);
	vector.push_back(9);
	vector.print();
	
	vector.pop_back();
	vector.print();

	vector.push_back(15);
	vector.push_back(24);
	vector.print();

	vector.pop_back();
	vector.print();
	

}
