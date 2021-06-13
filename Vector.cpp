#include <iostream>

template <class T>
class  Vector
{
public:
    Vector();
    Vector(unsigned int size);
    Vector(unsigned int size, const T& initial);
    Vector(const Vector<T>& v);
    ~Vector();

    unsigned int capacity() const;
    unsigned int size() const;
    bool empty() const;

    void pushBack(const T& value);
    void popBack();

    void reserve(unsigned int capacity);
    void shrinkToFit(unsigned int size);

    T& operator[](unsigned int index);
    Vector<T>& operator=(const Vector<T>&);
    void clear();
private:
    unsigned int m_size;
    unsigned int m_capacity;
    T* m_buffer;
};


template<class T>
Vector<T>::Vector(){
    m_capacity = 0;
    m_size = 0;
    m_buffer = 0;
}

template<class T>
Vector<T>::Vector(const Vector<T>& v){
    m_size = v.m_size;
    m_capacity = v.m_capacity;
    m_buffer = new T[m_size];
    for (unsigned int i = 0; i < m_size; ++i)
        m_buffer[i] = v.m_buffer[i];
}

template<class T>
Vector<T>::Vector(unsigned int size){
    m_capacity = size;
    m_size = size;
    m_buffer = new T[size];
}

template<class T>
Vector<T>::Vector(unsigned int size, const T& initial)
{
    m_size = size;
    m_capacity = size;
    m_buffer = new T[size];
    for ( int i = 0; i < size; ++i)//
        m_buffer[i] = initial;
}

template<class T>
Vector<T>& Vector<T>::operator = (const Vector<T>& v){
    delete[] m_buffer;
    m_size = v.m_size;
    m_capacity = v.m_capacity;
    m_buffer = new T[m_size];
    for ( int i = 0; i < m_size; ++i)//
        m_buffer[i] = v.m_buffer[i];
    return *this;
}


template<class T>
void Vector<T>::pushBack(const T& v)
{
    if (m_size >= m_capacity){
        reserve(m_capacity+10);
	}
    m_buffer[m_size++] = v;
}

template<class T>
void Vector<T>::popBack(){
    m_size--;
}

template<class T>
void Vector<T>::reserve(unsigned int capacity){
    if (m_buffer == 0)
    {
        m_size = 0;
        m_capacity = 0;
    }
    T* newbuffer = new T[capacity];
    unsigned int l_Size = capacity < m_size ? capacity : m_size;
    for (int i = 0; i < l_Size; i++)
        newbuffer[i] = m_buffer[i];
    m_capacity = capacity;
    delete[] m_buffer;
    m_buffer = newbuffer;
}

template<class T>
unsigned int Vector<T>::size()const{
    return m_size;
}

template<class T>
bool Vector<T>::empty() const{
    return m_size == 0;
}

template<class T>
void Vector<T>::shrinkToFit(unsigned int size){
    reserve(size);
    m_size = size;
}

template<class T>
T& Vector<T>::operator [] (unsigned int index){
    return m_buffer[index];
}

template<class T>
unsigned int Vector<T>::capacity () const{
    return m_capacity;
}

template<class T>
Vector<T>::~Vector(){
    delete[] m_buffer;
}

template <class T>
void Vector<T>::clear(){
    m_capacity = 0;
    m_size = 0;
    m_buffer = 0;
}

int main() {
    Vector<int> v;
    v.pushBack(4);
	v.pushBack(5);
	v.pushBack(9);
    v.popBack();
	Vector<int> v1(v);
	v[0]=6;
	for(int i = 0;i < v.size(); ++i){
		std::cout << v[i]<<" ";
	}
	std::cout << std::endl;
    std::cout << v.size() << std::endl;
    return 0;
}
