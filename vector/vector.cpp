#include "vector.h"
template <class T>

Vector<T>::Vector()
{
	arr = new T[1];
	size = 0;
	capacity = 1;
}
template<class T>
Vector<T>::Vector(const int& size, const T& value)
{
    this->size = size;
    for(int i = 0; i < this->size;i++)
    {
		arr[i] = value;
    }
}

template <class T>
Vector<T>::~Vector()
{
	delete[] this->arr;
	this->size = 0;
	this->capacity = 0;
}

template <class T>
int Vector<T>::getsize()const
{
	return this->size;
}

template <class T>
int Vector<T>::getcapacity()const
{
	return this->capacity;
}

template <class T>
void Vector<T>::print()
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << this->arr[i] << " ";
	}
	std::cout << std::endl;
}
template<class T>
Vector<T>::Vector(Vector<T>& vector1)
{
	for (int i = 0; i < this->size; i++)
	{
		vector1.pushback(this->arr[i]);
	}
}

template <class T>
T Vector<T>::operator[](const int& index)
{
	if (index < this->size)
	{
		return this->arr[index];
	}
	std::cout << "Index out of range!" << std::endl;
	return 0;
}

template<class T>
bool Vector<T>::empty()
{
	return this->size == 0;
}
template <class T>
void Vector<T>::operator=( Vector<T>& vector1)
{
	this->size = vector1.size;
	this->capacity = vector1.capacity;
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = vector1.arr[i];
	}
}

template <class T>
void Vector<T>::pushback(const T& value)
{
	if (this->size == this->capacity)
	{
		T* temp = new T[this->capacity * 2];
		for (int i = 0; i < this->size; i++)
		{
			temp[i] = arr[i];
		}
		delete[] this->arr;
		this->capacity *= 2;
		this->arr = temp;
	}
	this->arr[this->size] = value;
	this->size++;
}

template <class T>
void Vector<T>::insert(const T& value, const int& pos)
{
	if (pos == this->capacity)
	{
		pushback(value);
	}
	else
		this->arr[pos] = value;
}

template <class T>
void Vector<T>::popback()
{
	this->size--;
}


