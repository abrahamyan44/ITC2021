#include <iostream>
#include <exception>

using size_type = size_t;

template <class T>
class vector {
	public:
		vector();
		vector(size_type n);
		vector(size_type size, T value);
		vector(const vector& vec);
		~vector();
	public:
		void push_back (const T& val);
		void pop_back();
		size_type size() const;
		size_type capacity() const;
		bool empty() const;
		void reserve (size_type n);
		void shrink_to_fit();
		vector& operator= (const vector& x);
		T& operator[] (size_type n);

	private:
		size_type m_size;
		size_type m_capacity;
		T* m_array;
};

template <class T>
void vector<T>::push_back (const T& val) 
{
	if(m_size < m_capacity) {
		m_array[m_size] = val;
		++m_size;
	} else {
		size_type old_capacity = m_capacity;
		m_capacity = 1.5 * old_capacity;
		T* n_array;
		n_array = new T[m_capacity];
	   	for(size_type i = 0; i < m_size; ++i) {
		   	n_array[i] = m_array[i];
		} n_array[m_size] = val;
		++m_size;
		delete [] m_array;
		m_array = n_array;
	}
}

template <class T>
void vector<T>::pop_back()
{
	if (m_size == 0) {
		throw std::invalid_argument("vector is empty");
	} m_array[m_size-1] = 0;
	--m_size;
}

template <class T>
size_type vector<T>::size() const 
{
	return m_size;
}

template <class T>
size_type vector<T>::capacity() const
{
    return m_capacity;
}

template <class T>
bool vector<T>::empty() const
{
	return m_size == 0;
}

template <class T>
void vector<T>::reserve (size_type n) 
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
void vector<T>::shrink_to_fit()
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
vector<T>::vector()
	:m_size(0),
	m_capacity(0),
	m_array(nullptr) {}

template <class T>
vector<T>::vector(const vector& vec):
	m_size(vec.m_size),
	m_capacity(vec.m_capacity)
{
	m_array = new T[m_capacity];
	for(size_type i = 0; i < m_size; ++i) {
		m_array[i] = vec.m_array[i];
	}
}

template <class T>
vector<T>::vector(size_type n):
    m_size(0),
    m_capacity(n)
{
    m_array = new T[m_capacity];
}

template <class T>
vector<T>::vector(size_type n, T value):
	m_size(n),
	m_capacity(1.5 * n)
{
	m_array = new T[m_capacity];
	for(size_type i = 0; i < m_size; ++i) {
        m_array[i] = value;
    }
}

template <class T>
vector<T>::~vector()
{
    delete [] m_array;
	m_array = nullptr;
}

template <class T>
vector<T>& vector<T>::operator=(const vector<T>& x) 
{
	if (this == &x)
    return *this;
	m_size = x.m_size;
    m_capacity = x.m_capacity;
	m_array = new T[m_capacity];
    for(size_type i = 0; i < m_size; ++i) {
        m_array[i] = x.m_array[i];
    } return *this;
}

template <class T>
T& vector<T>::operator[] (size_type n)
{
	if(n < 0 || n >= m_size) {
		throw std::out_of_range("out of range");
	} else return m_array[n];
}

