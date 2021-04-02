#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Vector{
	int size;
	int capacity;
	T* vec;

public:
		Vector();
		Vector(int,T);
		Vector(const Vector<T>&);
		~Vector();

public:
		int getsize() const;
		int getcapacity()const;
		bool empty() const;
		void pushback(T v);
		void pushfront(T v);
		void pop_back();
		void pop_front();
		void print() const;
		void insert(int pos,const T& value);
		void reserve(int n);
		Vector<T>& operator= (const Vector<T>&);
		void shrink_to_fit();
		void clear();
		T& operator[] (int n);
};
