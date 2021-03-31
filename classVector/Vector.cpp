#include "Vector.hpp"

template <typename T1>
std::ostream& operator<<(std::ostream& out,const Vector<T1>& V)
{
	if (!V.IsEmpty()) {
		for(int i = 0; i < V.m_size; ++i) {
			out << V.m_data[i] << ' ';
		}
	}
	out << std::endl;
	return out;
}

template <typename T1>
std::istream& operator>>(std::istream& in, Vector<T1>& V)
{
	for(int i = 0; i < V.m_size; ++i) {
		in >> V[i];
	}
	return in;
}

template <typename T>
Vector<T>::Vector()
	:m_max_size(MAX_SIZE)
	,m_size(0)
	,m_data(nullptr)
{
	AllocateAndInitialize();
}

template <typename T>
Vector<T>::Vector(int size, const T* data)
	:m_max_size((size > MAX_SIZE) ? size : MAX_SIZE)
	,m_size(size)
	,m_data(nullptr)
{
	AllocateAndInitialize(data);
}

template <typename T>
Vector<T>::Vector(const Vector<T>& V)
	:m_max_size(V.m_max_size)
	,m_size(V.m_size)
	,m_data(nullptr) 
{
	AllocateAndInitialize(V.m_data);
}

template <typename T>
Vector<T>::~Vector()
{
	Deallocate();
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& V)
{
	if (this != &V) {
		Deallocate();
		m_max_size = V.m_max_size;
		m_size = V.m_size;
		AllocateAndInitialize(V.m_data);
	}
	return *this;
}

template <typename T>
T& Vector<T>::operator[](int index)
{
	CheckIndex(index);
	return m_data[index];
}

template <typename T>
const T& Vector<T>::operator[](int index) const
{
	CheckIndex(index);
	return m_data[index];
}

template <typename T>
void Vector<T>::PushBack(const T& element)
{
	if (m_size == m_max_size) {
		m_max_size *= 2;

		T* tmp = new T[m_max_size];
		
		for (int i = 0; i < m_size; ++i) {
			tmp[i] = m_data[i];
		}

		Deallocate();
		m_data = tmp;
	}
	m_data[m_size++] = element;
}

template <typename T>
void Vector<T>::PopBack()
{
	if (! IsEmpty()) {
		--m_size;
		return;
	}
	std::cout << "Vector is empty:" << std::endl;
	//throw VectorIsEmptyException();
	return;
}

template <typename T>
void Vector<T>::Insert(int index, const T& element)
{
	if (index < 0) {
		std::cout << "Index is less than 0" << std::endl;
		return;
	}

	if (index >= m_size) {
		PushBack(element);
	} else {
		if (m_size == m_max_size) {
			m_max_size *= 2;	
		}

		T* tmp = new T[m_max_size];

		for (int i = 0; i < index; ++i) {
			tmp[i] = m_data[i];
		}

		tmp[index] = element;

		for (int i = index + 1; i <= m_size; ++i) {
			tmp[i] = m_data[i - 1];
		}

		Deallocate();
		m_data = tmp;
		++m_size;
	}
}

template <typename T>
void Vector<T>::Remove(int index)
{
	if (index < 0) {
		std::cout << "Index is less than 0" << std::endl;
		return;
	}

	if (index >= m_size) {
		PopBack();
	} else {
		T* tmp = new T[m_max_size];

		for (int i = 0; i < index; ++i) {
			tmp[i] = m_data[i];
		}

		for (int i = index; i < m_size - 1; ++i) {
			tmp[i] = m_data[i + 1];
		}
		Deallocate();
		m_data = tmp;
		--m_size;
	}	
}

template <typename T>
void Vector<T>::ShrinkToFit()
{
	if (0 == m_size) {
		m_max_size = m_size;
		T* m_data = new T[m_max_size];
		return;
	}

	m_max_size = m_size;
	T* tmp = new T[m_max_size];

	for (int i = 0; i < m_size; ++i) {
		tmp[i] = m_data[i];
	}
	Deallocate();
	m_data = tmp;
}	

template <typename T>
void Vector<T>::Reserve(int nmaxsize)
{
	if (nmaxsize <= m_size) {
		return;
	}

	if (0 == m_size) {
		m_max_size = nmaxsize;
		T* m_data = new T[m_max_size];
		return;
	}

	m_max_size = nmaxsize;
	T* tmp = new T[nmaxsize];

	for (int i = 0; i < m_size; ++i) {
		tmp[i] = m_data[i];
	}
	Deallocate();
	m_data = tmp;
}	
	
template <typename T>
int Vector<T>::GetSize() const
{
	return m_size;
}

template <typename T>
int Vector<T>::GetCapacity() const
{
	return m_max_size;
}

template <typename T>
bool Vector<T>::IsEmpty() const
{
	return m_size == 0;
}

template <typename T>
void Vector<T>::AllocateAndInitialize(const T* data)
{
	m_data = new T[m_max_size] {};

	if (nullptr != data) {
		assert(nullptr != data);

		for (int i = 0; i < m_size; ++i) {
			m_data[i] = data[i];
		}
		assert(nullptr != data);
	}
}

template <typename T>
void Vector<T>::Deallocate()
{
	delete[] m_data;
	m_data = nullptr;
}

template <typename T>
void Vector<T>::CheckIndex(int index)
{
	assert(index > 0 || index < m_size);

	if (index < 0 || index >= m_size) {
		std::cout << "Index is out of bounds" << std::endl;
		return;
		}
	//ok
}

int main()
{
	/***************testing**************/
	Vector<int> V;

	V.PushBack(1);
	V.PushBack(2);
	V.PushBack(3);
	V.PushBack(4);
	V.PushBack(5);
	V.PushBack(6);
	V.PushBack(7);
	V.PopBack();

	std::cout << V << std::endl;

	std::cout << "Size is: " << V.GetSize() << std::endl;
	std::cout << "Capacity is: " << V.GetCapacity() << std::endl;
	std::cout << "Is empty? " << V.IsEmpty() << std::endl;
	V.Insert(2,100);
	V.Remove(4);

	std::cout << V << std::endl;
	std::cout << "************************************************" << std::endl;
	
	const int n = 200;
	int arr[n] = {0};

	Vector<int> V2(n,arr);
	for (int i = 0; i < V2.GetSize(); ++i) {
      		V2[i] = i;
    }

	std::cout << "Size is: " << V2.GetSize() << std::endl;
	std::cout << "Capacity is: " << V2.GetCapacity() << std::endl;
	std::cout <<"***************************************************"<<std::endl;

	Vector<int> V3;

	V3.PushBack(1);
	V3.PushBack(2);
	V3.PushBack(4);

	std::cout << "Size is: " << V3.GetSize() << std::endl;
	std::cout << "Capacity is: " << V3.GetCapacity() << std::endl;
	
	V3.Reserve(4);
	std::cout << "Size after reserve: " << V3.GetSize() << std::endl;
	std::cout << "Capacity after reserve: " << V3.GetCapacity() << std::endl;
	
	V3.ShrinkToFit();
	std::cout << "Size after shrink: " << V3.GetSize() << std::endl;
	std::cout << "Capacity after shrink: " << V3.GetCapacity() << std::endl;
	
	return 0;
}
