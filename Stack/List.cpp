#include <iostream>
#include "List.hpp"

//Default constructor
template <typename T>
List<T>::List()
    :m_size(0), m_begin(0), m_end(0)
{
}

//Parameterized constructor
template <typename T>
List<T>::List(int count, T value)
    :m_size(count)
{
    node* tmp = 0;
    for(int i = 0; i < m_size; ++i)
    {
        m_end = new node;
        if(0 == m_end){
            std::cout << "Could not allocate memory.";
            return;
        }
        if(0 == i){
            m_begin = m_end;
            m_begin->prev = nullptr; 
            tmp = m_end;
        }
        else {
            tmp->next = m_end;
            m_end->prev = tmp;
            if(i == m_size){
                m_end->next = nullptr;
            }
            else{
                tmp = m_end;
            }
        }
        tmp->number = value;
    }
}

//Copy constructor
template <typename T>
List<T>::List(const List& other)
    :m_size(other.m_size)
{
    node* tmp = 0;
    node* other_iter = other.m_begin;
    for(int i = 0; i < m_size; ++i)
    {
        m_end = new node;
        m_end->number = other_iter->number;
        other_iter = other_iter->next;
        if(0 == m_end){
            std::cout << "Could not allocate memory.";
            return;
        }
        if(0 == i){
            m_begin = m_end;
            tmp = m_end;
            m_begin->prev = nullptr;
        }
        else{
            tmp->next = m_end;
            m_end->prev = tmp;
            if(i == m_size){
                m_end->next = nullptr;
            }
            else{
                tmp = m_end;
            }
        }    
    }
}

//Destructor
template <typename T>
List<T>::~List()
{
    std::cout << "Destructor.\n";
    free();
}

//Operator assignment
template <typename T>
List<T>& List<T>::operator=(const List& other)
{
    free(); //frees old List
    m_size = other.m_size;
    node* tmp = 0;
    node* other_iter = other.m_begin;
    for(int i = 0; i < m_size; ++i)
    {
        m_end = new node;
        m_end->number = other_iter->number;
        other_iter = other_iter->next;
        if(0 == m_end){
            std::cout << "Could not allocate memory.";
            exit(1);
        }
        if(0 == i){
            m_begin = m_end;
            tmp = m_end;
            m_begin->prev = nullptr;
        }
        else{
            tmp->next = m_end;
            m_end->prev = tmp;
            if(i == m_size){
                m_end->next = nullptr;
            }
            else{
                tmp = m_end;
            }
        }
    }
    return *this;
}

template <typename T>
T& List<T>::tail()
{
    if (0 == m_end)
    {
        std::cout << "List is empty.";
    }
    return m_end->number ;
}

//Empties object
template <typename T>
void List<T>::free()
{ 
    node* iter = 0;
    for(int i = 0; i < m_size; ++i)
    {
        iter = m_begin->next;
        delete m_begin;
        m_begin = iter;
    }
    m_begin = 0;
    m_end = 0;
}

//Returns size of List
template <typename T>
int List<T>::Size() const
{
    return m_size;
}

template <typename T>
void List<T>::InsertBegin(const T& value)
{
    node* tmp = new node;   //adds node at a start of List
    if(0 == tmp){
        std::cout << "Could not allocate memory.";
        return;
    }
    if (0 != m_begin)
    {
        m_begin->prev = tmp;
    }
    tmp->next = m_begin;
    m_begin = tmp;
    m_begin->number = value;
    m_begin->prev = 0;
    if (0 == m_end)
    {
        m_end = m_begin;
    }
    ++m_size;
}

template <typename T>
void List<T>::InsertEnd(const T& value)
{
    node* tmp = new node;   //adds node at the m_end of List
    if(0 == tmp){
        std::cout << "Could not allocate memory.";
        return;
    }
    if (0 != m_end)
    {
        m_end->next = tmp;
    }
    tmp->prev = m_end;
    m_end = tmp;
    m_end->number = value;
    m_end->next = 0;
    if (0 == m_begin)
    {
        m_begin = m_end;

    }
    ++m_size;
}

//Inserts node into the List
template <typename T>
void List<T>::Insert(int pos, const T& value)
{
    if (0 != m_begin) //if List is not empty
	{
        if (0 == pos)   //if needs insert in a first position
        {
            InsertBegin(value);
        }
        else if(pos == m_size)  //if needs insert in a last position
        {
            InsertEnd(value);
        }
        else if (0 < pos && pos < m_size)   //insert in the List
        {
            node* iter = m_begin;
            for (int i = 0; i < pos - 1; ++i)    //it finds node at given position
            {
                iter = iter->next;
            }
            node* tmp = new node;
            tmp->number = value;    //swaps a previous and next pointers
            iter->next->prev = tmp;
            tmp->next = iter->next;
            tmp->prev = iter;
            iter->next = tmp;
	        ++m_size;
        }
        else{
            std::cout << "Wrong position.\n";
            return;
        }
    }
    else    //if List is empty
    {
        m_begin = new node;
        m_begin->prev = 0;
        m_begin->next = 0;
        m_end = m_begin;
        m_begin->number = value;
	    ++m_size;
	}
}

template <typename T>
void List<T>::EraseBegin()  //erases first element
{
    node* tmp = m_begin;
    m_begin = m_begin->next;
    m_begin->prev = 0;
    delete tmp; 
	--m_size;
}

template <typename T>
void List<T>::EraseEnd()  //erases last element
{
    node* tmp = m_end;
    m_end = m_end->prev;
    m_end->next = 0;
    delete tmp;
	--m_size;
}

//Erases node from List
template <typename T>
void List<T>::Erase(int pos)
{
    node* tmp = 0;
    if(0 != m_begin)
    {
        if(0 == pos){
            EraseBegin();
        }
        else if(pos == m_size - 1){
            EraseEnd();
        }
        else if(0 < pos && pos < m_size - 1)
        {    
            tmp = m_begin;
            for (int i = 0; i < pos; ++i)
            {
                tmp = tmp->next;
            }
            tmp->next->prev = tmp->prev;
            tmp->prev->next = tmp->next;
            delete tmp;
	        --m_size;
        }
        else{
            std::cout << "Wrong position.\n";
            return;
        }
    }
    else{
        std::cout << "List is empty.\n";
        return;
    }
}

//Prints members of List
template <typename T>
void List<T>::Print()
{
    node* iter = m_begin;
    for(int i = 0; i < m_size; ++i)
    {
        std::cout << iter->number << " ";
        iter = iter->next;
    }
    std::cout << std::endl;
}

template class List<int>;
