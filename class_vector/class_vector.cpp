#include <iostream>
#include<cassert>

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

~Vector();

void push_back (const T& val);

void pop_back ();

size_t size() const;

size_t capacity() const;

bool empty() const;

void reserve (size_t n);

void shrink_to_fit();

Vector& operator=(const vector& x);

operator[] (size_t n);

};

Vector::Vector()
{
	m_size = 1;
	m_capacity = 3;
	T* m_data = new T[1];
}

Vector:: Vector (const vector& x) {
	x.size = m.size;
	x.capasity = m.capacity;
	for(size_t i = 0; i <= m.size; i++) {
		x[i] = m.data[i];
	}
}

Vector::~Vector() {
	for(size_t i = 0; i <= m_size, i++){
		delete[] m_data[i];
	}
	m_data = nullptr;
	assert(nullptr = m_data);
}

void Vector::shrink_to_fit() 
{
	size_t new_capacity = m_size - 1;
	T* new_block = new T(new_capacity);
	for(int i = 0; i < m_size; i++) {
		new_block[i] = m_data[i]
	}
	delete[] m_data;
	m_data = nullptr;

	m_data = new_block;
	m_capacity = new_capacity;
}

void Vector::reserve(size_t n) 
{
	T* new_block = new T(n);
	assert(nullptr != new_block);
	
	for(int i = 0; i < m_size; i++) {
		new_block[i] = m_data[i];
	}

	delete[] m_data;
	m_data = nullptr;
	
	m_capacity = n;
	m_data = new_block;
}

void Vector::push_back(const T& val)
{
	if(m_size >= m_capacity) {
		Vector::reserve(m_capacity + m_capacity/2);
	}

	m_data[m_size] = val;
	m_size++;
}



void Vector::pop_back() {
	size_t i = Vector::size();
	delete m_data[i];
	m_data[i] = nullptr;
	m_size--;
}

size_t Vector::size() 
{
	size_t size = m_size - 1;
	return size;
}

size_t Vector::capacity() 
{
	size_t capacity = m_capacity;
	return capacity;
}

bool Vector::empty() 
{
	if(m_size == 0) {
		return true;
	} else {
		return false;
	}
}

Vector& Vector::operator=(const Vector& x) {
	if(this != x) {
		for(i = 0; i < m_size-1; i++) {
			m_data = x.m_data;
			m_capacity = x.m_capacity;
			m_size = x.m_size;
			return *this;
		}
}

Vector:: operator[] (size_t n)
{
	if(n >= my_size) {
		size_t size = m_size;
		assert(n < size);
	}
		return m_data[n]; 
}

void print(const Vector<T> vector) 
{
	for(size_t i = 0; i <= vector.size(); i++) {
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
