#include "Stack.hpp"

template <typename T>
Stack<T>::Stack()
	: m_max_size(s_max_size)
	, m_top(-1)
	, m_data(nullptr) 
{
	AllocateAndInitialize();
}

template <typename T>
Stack<T>::Stack(const T* data, int size)
	: m_max_size((size > s_max_size) ? size : s_max_size)
	, m_top(-1)
	, m_data(nullptr) 
{
	AllocateAndInitialize(data);
}

template <typename T>
Stack<T>::Stack(const Stack<T>& S)
	: m_max_size(S.m_max_size)
	, m_top(S.m_top)
	, m_data(nullptr) 
{
	AllocateAndInitialize(S.m_data);
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& S) 
{
	if (this != &S) {
		Deallocate();
		m_max_size = S.m_max_size;
		m_top = S.m_top;
		AllocateAndInitialize(S.m_data);
	}
	return *this;
}

template <typename T>
Stack<T>::~Stack() 
{
	Deallocate();
}

template <typename T>
T& Stack<T>::Top() 
{
	if (IsEmpty()) {
		std::cerr << "Stack is empty." << std::endl;
	}
	assert(nullptr != m_data);
	return m_data[m_top];
}

template <typename T>
const T& Stack<T>::Top() const 
{
	if (IsEmpty()) {
		std::cerr << "Stack is empty." << std::endl;
	}
	assert(nullptr != m_data);
	return m_data[m_top];
}

template <typename T>
void Stack<T>::Push(const T& element) 
{
	assert(nullptr != m_data);

	if (IsFool()) {
		m_max_size *= 2;

		T* tmp = new T[m_max_size]{};

		for (int i = 0; i <= m_top; ++i) {
			tmp[i] = m_data[i];
		}
		Deallocate();
		
		assert(nullptr == m_data);
		
		m_data = tmp;
	}
	m_data[++m_top] = element;
}

template <typename T>
void Stack<T>::Pop() 
{
	if (m_top == -1) {
		std::cerr << "Stack is empty." << std::endl;
		return;
	}
	assert(-1 != m_top);
	--m_top;
}

template <typename T>
int Stack<T>::GetSize() const
{
	return 1 + m_top;
}

template <typename T>
bool Stack<T>::IsEmpty() const
{
	return (m_top == -1);
}

template <typename T>
bool Stack<T>::IsFool() const
{
	return (m_top == s_max_size - 1);
}


template <typename T>
void Stack<T>::AllocateAndInitialize(const T* data) 
{
	m_data = new T[m_max_size]{};

	if (nullptr != data) {
		for (int i = 0; i <= m_top; ++i) {
			m_data[i] = data[i];
		}
	}
}

template <typename T>
void Stack<T>::Deallocate()
{
	delete[] m_data;
	m_data = 0;
}

/*template <typename T>
void Stack<T>::CheckEmpty() const 
{
	if (IsEmpty()) 
	{
		std::cerr << "The stack is empty." << std::endl;
		return;
	//	throw std::exception("The stack is empty.");
	}
}*/

int main()
{
	/*************testing*************/
	Stack<int> S;
	S.Push(5);
	std::cout << S.Top() << " ";
	S.Push(51);
	S.Push(55);
	S.Push(15);
	S.Push(85);
	S.Push(65);
	S.Push(15);
	S.Push(95);
	S.Push(55);
	S.Pop();
	std::cout << S.Top() << " ";	
	std::cout << S.GetSize() << " ";
	std::cout << std::endl;

	std::cout << "*********************************************" << std::endl;

	Stack<std::string> S1;
	std::cout << S1.Top() << ' ';
	S1.Pop();
	S1.Push("a");
	std::cout << S1.Top() << ' ';
	std::cout << std::endl;

}
