#include <iostream>

class Vector {

	int* arr; // pointer to the first element of the Vector
	int m_size; //size of the Vector
        int capasity;      

	void create_vector(const int& size);

public:
	void print();
	int size();
	void insert(int pos, const int& val);
	void erase(int pos);
	Vector(int size);
	~Vector();
	Vector(const Vector& v);
	Vector& operator=(const Vector& v);

};

void Vector::print()
{
	if(m_size == 0)
	{
		std::cout << "The vector is empty ";
	}
	for(int i = 0; i < m_size ; i++) {
		std::cout << arr[i] << " ";  
	}
	std::cout << std::endl;
}

int Vector::size()
{
	return m_size;
}

void Vector::create_vector(const int& cap)
{
	capasity = cap;
	arr = new int[capasity];
	for(int i = 0; i < capasity; ++i) {
		arr[i] = 0;
	}
}

void Vector::insert(int pos, const int& val)
{
	if(pos < 0) {
		return;
	} else if(pos > m_size) {
		pos = m_size;
	}
	if(m_size == capasity) {
		Vector x = *this;
		create_vector(capasity + 10);
		*this = x;
	}
	for(int i = m_size; i > pos; --i) {
		arr[i] = arr[i - 1]; 
	}	
	++m_size;
	arr[pos] = val;
}	

void Vector::erase(int pos)
{
	if(pos < 0 || m_size <= 0) {
		return;
	} else if(pos > m_size - 1) {
		pos = m_size - 1;
	}
	if(m_size > 0) {
		for(int i = pos; i < m_size - 1; i++) {
			arr[i] = arr[i + 1];
		}
		arr[m_size - 1] = 0;
	}
	--m_size;
}

Vector::Vector(int size)
{
	m_size = 0;
	capasity = 0;
    	std::cout << "Constructor n = " << size << std::endl;
	if (size < 0) {
		std::cout << "wrong length" << std::endl;
	};
	
	create_vector(size + 10);
	m_size = size;
}

Vector::~Vector() //destructor
{ 
    if(m_size > 0) {	
        delete[] arr;
    }
}

Vector::Vector(const Vector& v) {

        create_vector(v.capasity);	
	m_size = v.m_size;

    for(int i = 0; i < v.capasity; i++) {
	arr[i] = v.arr[i];
    }
	std::cout << "Copy Constructor" << std::endl;
}

Vector& Vector::operator=(const Vector& v) {
	if (this != &v) {	
		if(capasity < v.capasity) {
			create_vector(v.capasity);
	}

	m_size = v.m_size;

	for(int i = 0; i < v.capasity; i++) {
		if(i < m_size) {
			arr[i] = v.arr[i];
		} else { 
			arr[i] = 0;
		}
	}
	}
	return *this;
}

int main()
{
	std::cout << "Enter size of vector ";
	int n;
	std::cin >> n;
	if (n <= 0) {
        std::cout << "Wrong input" << std::endl;
    	return 1;
    	}
	{
	Vector v(n);
	v.print();
	for(int i = 5; i < 20; ++i) {
		v.insert(i, i);
	}
	
	Vector g(v);
	g.print();
	g.erase(100);
   	g.print();
	v.print();
	}
return 0;
}
