#include "stack.hpp"

template <class T>
Stack<T>::Stack()
		:size(0)
{
		data = new T[MAX_SIZE];
}

template<class T>
Stack<T>::~Stack()
{
		size = 0;
		delete[] data;
}

template <class T>
Stack<T>::Stack(const int& size,const T& value)
{
		this->size = size;
		for (int i = 0; i < this->size;i++)
		{
				data[i] = value;
		}
}

template<class T>
Stack<T>::Stack(const Stack<T>& stack)
{
		this->size = stack.size;
		for(int i = 0; i < this->size; i++)
		{
				this->data[i] = stack.data[i];
		}
}

template <class T>
int Stack<T>::getsize()const
{
		return this->size;
}

template <class T>
bool Stack<T>::empty()const
{
		return size == 0;
}

template <class T>
T& Stack<T>::top()
{
		if (empty())
		{
				std::cerr << "Stack is empty!" << std::endl;
		}
		return data[size];
}

template <class T>
void Stack<T>::push(const T& value)
{
		if(size > MAX_SIZE)
		{
				std::cerr << "Stack overflow!" << std::endl; 
		}
		data[size++] = value;
}

template <class T>
void Stack<T>::pop()
{
		if(this->size == 0)
		{
				std::cout << "Stack is empty!" << std::endl;
		}
	    this->size--;
}

template <class T>
void Stack<T>::print()
{
		for (int i = 0; i < this->size; i++)
		{
			std::cout << this->data[i] << " ";
		}
		std::cout << std::endl;

}


