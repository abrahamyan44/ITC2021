#ifndef _VECTOR_HPP
#define _VECTOR_HPP

template <typename T>
class Vector
{
private:
    T* m_array;
    int m_capacity;
    int m_size; 

public:
    Vector();
    Vector(int, T);
    Vector(const Vector&);
    ~Vector();

//methods
public:
    void PushBack(const T&);
    void PopBack();
    int Size() const;
    int Capacity() const;
    bool isEmpty() const;
    void Reserve(int);
    void ShrinkToFit();
    Vector& operator=(const Vector&);
    T& operator[](int);
    void Print();
};


template class Vector<int>;
#endif //_VECTOR_HPP
