#include <iostream>
#include "vector.hpp"
#include <cassert>

template <typename T>
Vector<T>::Vector()
			:size(0)
			,capacity(1)
{
	vec=new T[1];
}

template <typename T>
Vector<T>::~Vector(){
	delete[]vec;
}

template <typename T>
Vector<T>::Vector(int n,T value)
			:size(0)
			,capacity(n)
{
	vec=new T[n];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& temp)
						:size(temp.getsize())
						,capacity(temp.getcapacity())
{
	vec=new T[capacity];
	for (int i=0;i<temp.getsize();++i){
		vec[i]=temp.vec[i];
	}
}

template <typename T>
void Vector<T>::pushback(T value){
	if (size==capacity){
		assert(!empty());
		reserve(2*capacity);
		vec[size]=value;
		size++;
	}
	else{
		vec[size]=value;
		size++;
	}
}

template<typename T>
int Vector<T>::getsize()const{
	return size;
}

template<typename T>
int Vector<T>::getcapacity()const{
    return capacity;
}


template<typename T>
bool Vector<T>::empty()const{
	assert(size>=0);
	if (size == 0){
		return true;
	}
	else{
		return false;
	}
}

template<typename T>
void Vector<T>::pushfront(T value){
	if ( empty() ){
		assert(size==0);
		vec[0]=value;
		size++;
	}
	else if ( size == capacity ){
		T* temp=new T[2*capacity];
		temp[0]=value;
		for ( int i=1; i<=capacity; ++i){
			temp[i]=vec[i-1];
		}
		delete[] vec;
		vec=temp;
		capacity=2*capacity;
		size++;
	}
	else{
		for ( int i=size; i>=1; --i ){
			vec[i]=vec[i-1];
		}
		vec[0]=value;
		size++;
	}
}

template<typename T>
void Vector<T>::print()const{
	cout<<"[";
	for ( int i=0; i<size; i++){
		cout<<vec[i]<<";";
	}
	cout<<"]"<<endl;
}

template<typename T>
void Vector<T>::insert(int pos,const T& value){
	assert(pos>=0 && pos<=size);
	if (pos==0){
		pushfront(value);
	}
	else
	if (pos==size){
		pushback(value);
	}
	else{
		for ( int i=size; i>=pos+1; --i ){
			vec[i]=vec[i-1];
		}
		vec[pos]=value;

	}	
	size++;
}

template<typename T>
void Vector<T>::reserve(int n){
	if(empty()){
		assert(size==0);
	}else{
		assert(n>capacity);
		T* cur=new T[n];     
		for (int i=0; i<capacity; ++i){ 
			cur[i]=vec[i];              
		}                                        
		capacity=n;            
		delete[]vec;                    
		vec=cur;                                               
	}

}

template<typename T>
void Vector<T>::pop_back(){
	vec[size-1]=0;
	size--;
}

template<typename T>
void Vector<T>::shrink_to_fit(){
	reserve(size);
}

template<typename T>
void Vector<T>::clear(){
	for (int i = 0;i < size;++i){
		vec[i]=0;
	}
	size=0;
}

template<typename T>
Vector<T>& Vector<T>::operator= (const Vector& x){
	clear();
	reserve(x.getcapacity());
	size=x.getsize();
	for (int i = 0;i < size;i++){
		vec[i]=x.vec[i];
	}

	return *this;
	
}

template<typename T>
T& Vector<T>::operator[] (int n){
	assert(n>=0 && n<size);
	return vec[n];
}

























