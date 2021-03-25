#include <iostream>

struct node
{
    int number;
    node* prev = 0;
    node* next = 0;
};

class list
{
private:
    int m_size;
    node* begin = 0;
    node* end = 0;

private:
    void free();

public:
    list();
    list(int count, int value);
    list(const list&);
    list& operator=(const list&);
    ~list();

public:
    int size() const;
    void insert_begin(const int& value);
    void insert_end(const int& value);
    void insert(int pos, const int& value);
    void erase_begin();
    void erase_end();
    void erase(int pos);
    void print();
};

//Default constructor
list::list()
    :m_size(0), begin(0), end(0)
{
}

//Parameterized constructor
list::list(int count, int value)
    :m_size(count)
{
    node* tmp = 0;
    for(int i = 0; i < m_size; ++i)
    {
        end = new node;
        if(0 == end){
            std::cout << "Could not allocate memory.";
            return;
        }
        if(0 == i){
            begin = end;
            begin->prev = nullptr; 
            tmp = end;
        }
        else {
            tmp->next = end;
            end->prev = tmp;
            if(i == m_size){
                end->next = nullptr;
            }
            else{
                tmp = end;
            }
        }
        tmp->number = value;
    }
}

//Copy constructor
list::list(const list& other)
    :m_size(other.m_size)
{
    node* tmp = 0;
    node* otherIter = other.begin;
    for(int i = 0; i < m_size; ++i)
    {
        end = new node;
        end->number = otherIter->number;
        otherIter = otherIter->next;
        if(0 == end){
            std::cout << "Could not allocate memory.";
            return;
        }
        if(0 == i){
            begin = end;
            tmp = end;
            begin->prev = nullptr;
        }
        else{
            tmp->next = end;
            end->prev = tmp;
            if(i == m_size){
                end->next = nullptr;
            }
            else{
                tmp = end;
            }
        }    
    }
}

//Destructor
list::~list()
{
    std::cout << "Destructor.\n";
    free();
}

//Operator assignment
list& list::operator=(const list& other)
{
    free(); //frees old list
    m_size = other.m_size;
    node* tmp = 0;
    node* otherIter = other.begin;
    for(int i = 0; i < m_size; ++i)
    {
        end = new node;
        end->number = otherIter->number;
        otherIter = otherIter->next;
        if(0 == end){
            std::cout << "Could not allocate memory.";
            exit(1);
        }
        if(0 == i){
            begin = end;
            tmp = end;
            begin->prev = nullptr;
        }
        else{
            tmp->next = end;
            end->prev = tmp;
            if(i == m_size){
                end->next = nullptr;
            }
            else{
                tmp = end;
            }
        }
    }
    return *this;
}

//Empties object
void list::free()
{ 
    node* iter = 0;
    for(int i = 0; i < m_size; ++i)
    {
        iter = begin->next;
        delete begin;
        begin = iter;
    }
    begin = 0;
    end = 0;
}

//Returns size of list
int list::size() const
{
    return m_size;
}

void list::insert_begin(const int& value)
{
    node* tmp = new node;   //adds node at a start of list
    if(0 == tmp){
        std::cout << "Could not allocate memory.";
        return;
    }
    begin->prev = tmp;
    tmp->next = begin;
    begin = tmp;
    begin->number = value;
    begin->prev = 0;
    ++m_size;
}

void list::insert_end(const int& value)
{
    node* tmp = new node;   //adds node at the end of list
    if(0 == tmp){
        std::cout << "Could not allocate memory.";
        return;
    }
    end->next = tmp;
    tmp->prev = end;
    end = tmp;
    end->number = value;
    end->next = 0;
    ++m_size;
}

//Inserts node into the list
void list::insert(int pos, const int& value)
{
    if (0 != begin) //if list is not empty
	{
        if (0 == pos)   //if needs insert in a first position
        {
            insert_begin(value);
        }
        else if(pos == m_size)  //if needs insert in a last position
        {
            insert_end(value);
        }
        else if (0 < pos && pos < m_size)   //insert in the list
        {
            node* iter = begin;
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
    else    //if list is empty
    {
        begin = new node;
        begin->prev = 0;
        begin->next = 0;
        end = begin;
        begin->number = value;
	    ++m_size;
	}
}

void list::erase_begin()  //erases first element
{
    node* tmp = begin;
    begin = begin->next;
    begin->prev = 0;
    delete tmp; 
	--m_size;
}

void list::erase_end()  //erases last element
{
    node* tmp = end;
    end = end->prev;
    end->next = 0;
    delete tmp;
	--m_size;
}

//Erases node from list
void list::erase(int pos)
{
    node* tmp = 0;
    if(0 != begin)
    {
        if(0 == pos){
            erase_begin();
        }
        else if(pos == m_size - 1){
            erase_end();
        }
        else if(0 < pos && pos < m_size - 1)
        {    
            tmp = begin;
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

//Prints members of list
void list::print()
{
    node* iter = begin;
    for(int i = 0; i < m_size; ++i)
    {
        std::cout << iter->number << " ";
        iter = iter->next;
    }
    std::cout << std::endl;
}

int main()
{
    list b;
    list a(8,4);
    std::cout << a.size() << std::endl;
    a.print();
    a.insert(2,22);
    b = a;
    a.insert(6,33);
    a.print();
    b.print();
    a.erase(5);
    a.print();
    std::cout << a.size() << std::endl;
    a.insert(0,0);
    a.insert(1,1);
    a.insert(12,2);
    a.print();
    a.erase(0);
    a.print();
    a.erase(4);
    a.print();
    a.erase(2);
    a.print();
}
