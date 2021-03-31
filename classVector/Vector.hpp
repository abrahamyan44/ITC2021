#pragma once

#include <iostream>
#include <cassert>

template <typename T>

class Vector
{
	template <typename T1>
	friend std::ostream& operator<<(std::ostream&,const Vector<T1>&);
	template <typename T1>
	friend std::istream& operator>>(std::istream&, Vector<T1>&);	

private:
	static int const MAX_SIZE = 100; //dynamic maximum size of Vector

	int m_max_size; //maximum size 
	int m_size;     //number of elements
	T* m_data; 	    //data

private:
	void AllocateAndInitialize(const T* = nullptr); //allocate and initialize
	void Deallocate();								//deallocate
	void CheckIndex(int);							//check index

public:
	Vector(); 				  //default ctor
	Vector(int, const T*); 	  //ctor with parameters
	Vector(const Vector<T>&); //copy ctor
	~Vector(); 				  //dtor
	Vector<T>& operator=(const Vector<T>&); //assignment operator

	int GetSize() const; 		//get size
	int GetCapacity() const;	//get capacity
	bool IsEmpty() const;		//returns whether teh Vector is empty

	T& operator[](int);
	const T& operator[](int) const;
	
	void PushBack(const T&); 	//add a new element to the end of the vector
	void PopBack();			 	//remove the last element from the vector
	void Insert(int, const T&); //add a new element at the given index of the vector
	void Remove(int); 			//remove the given element from the vector
	void ShrinkToFit();			//requests the container to reduce its capacity to fit its size
	void Reserve(int);			//requests that the vector capacity be at \
								  least enough to contain n elements
};


