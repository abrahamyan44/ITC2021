#include <iostream>
#include<cassert>

using namespace std;

template <class T>
class Vector {
privet:
	size_type m_size;
	size_type m_capacity;
	T* m_data;

public:
Vector();

Vector(const Vector& x);

~Vector();

void push_back (const T& val);

void pop_back ();

size_type size() const;

size_type capacity() const;

bool empty() const;

void reserve (size_type n);

void shrink_to_fit();

vector& operator= (const vector& x);

reference operator[] (size_type n);

};

Vector::Vector()
{
	m_size = 1;
	m_capacity = 3;
	m_data = nullptr;
}

Vector:: Vector (const vector& x) {
	x.size = m.size;
	x.capasity = m.capacity;
	for(size_type i = 0; i <= m.size; i++) {
		x[i] = m.data[i];
	}
}

Vector::~Vector() {
	for(size_type i = 0; i <= m_size, i++){
		delete[] m_data[i];
	}
	m_data = nullptr;
	assert(nullptr = m_data);
}

Vector::shrink_to_fit() 
{
	size_type new_capacity = m_size - 1;
	T* new_block = new T(new_capacity);
	for(int i = 0; i < m_size; i++) {
		new_block[i] = m_data[i]
	}
	delete[] m_data;
	m_data = nullptr;

	m_data = new_block;
	m_capacity = new_capacity;
}

Vector::reserve(size_type n) 
{
	T* new_block = new T(n);
	assert(nullptr != new_block);
	
	for(int i = 0; i < m_size; i++) {
		new_block[i] = m_data[i];
	}

	delete[] m_data;
	m_data = nullptr'
	
	m_capacity = n;
	m_data = new_block;
}

Vector::push_back(const T& val)
{
	if(m_size >= m_capacity) {
	Vector::reserve(m_capacity + m_capacity/3);
	}

	m_data[m_size] = val;
	m_size++;
}

Vector::size() 
{
	size_type size = m_size - 1;
	return size;
}

Vector::capacity() 
{
	size_type capacity = m_capacity;
	return capacity;
}

Vector::empty() 
{
	if(m_size == 0) {
		return true;
	} else {
		return false;
	}
}

vector:: operator[] (size_type n)
{
	if(n >= my_size) {
		size_type size = m_size;
		assert(n < size);
	}
		return m_data[n]; 
}

void print(const Vector<T> vector) 
{
	for(size_type i = 0; i <= vector.size(); i++) {
		cout << vector[i] << endl;;
	} 
}

int main() 
{
	Vector<int> vector;

	vector.push_back(5);
	vector.push_back(7);
	vector.push_back(9);
}
