#include <iostream>
#include <cassert>

struct Node
{
	Node(int val);
	int data;
	Node* next; // points to the next node in the list.
	Node* prev; // points to the previous node in the list.
};

Node::Node(int val)
	:data(val)
	,next(nullptr)
	,prev(nullptr)
{}

typedef Node* NodePtr;

class List
{
public:
		List(); 				       // creates empty list
    	List(int count, int val);      // list with 'count' copies of elements with value 'val'
		List(const List&); 		       // copy ctor
		~List();				       // dtor
        List& operator=(const List&);  // assignment operator

        void insert_front(int val);    //insert 'val' at the front of the list
		void insert_back(int val);     //insert 'val' at the back of the list
		void insert_after(int pos,const int& val);   // inserts value after pos
		void insert_before(int pos,const int& val);  // inserts value before pos
		int top_front() const;		   // returns the data at first node
		int top_back() const; 		   // returns the data at last node
		int pop_front();			   // removes the item at front of the list and return
		int pop_back();				   // removes the item at back of the list and return
		void remove(int val); 		   // removes an item with value 'val'
		void clear();				   // removes list
		void print() const;				
		void print_reverse() const;
		bool is_empty() const; 		   // check if the list is empty
		bool find(int val) const;	   // check if a 'val' is in the list
		int get_size() const; 		   // returns the number of elements in the container
        
private:
		NodePtr m_head;
		NodePtr m_tail;
		int m_size;		
};

List::List()
    :m_size(0)
    ,m_head(nullptr)
    ,m_tail(nullptr)
{}

List::List(int count, int val)
	:m_size(0)
    ,m_head(nullptr)
    ,m_tail(nullptr)
{	
	for (int i = 1; i <= count; ++i) {
		insert_back(val);
	} 
}

List::~List()
{
	clear();
}

List::List(const List& l1)
    :m_size(0)
	,m_head(nullptr)
    ,m_tail(nullptr)
{
	NodePtr current = l1.m_head;
	
	while (current != nullptr) {
		insert_back(current->data);
		current = current->next;
	}
}
	
List& List::operator=(const List& l1)
{
	if (this != &l1) {
	m_size = 0;
    m_head = nullptr;
    m_tail = nullptr;

	NodePtr current = l1.m_head;

    while (current != nullptr) {
        insert_back(current->data);     
        current = current->next;
    }
	}
	return *this;
}

void List::insert_front(int val)
{
	NodePtr node = new Node(val);

	if (is_empty()) {
		m_head = node;
		m_tail = node;
	} else {
		node->next = m_head;
		m_head->prev = node;
		m_head = node;
	}
	++m_size;
}	

void List::insert_back(int val)
{
	NodePtr node = new Node(val);

	if (is_empty()) {
        m_head = node;
        m_tail = node;
    } else {
		m_tail->next = node;
		node->prev = m_tail;
		m_tail = node;
    }
    ++m_size;	
}

void List::insert_after(int key,const int& val)
{
	NodePtr node = new Node(val);

   	//find the position
	NodePtr current = m_head;

	while (current != nullptr && current->data != key) {
		current = current->next;
	}

	//if key is not there =>error
	if (current == nullptr) {
		std::cout<<"Key not found:" << std::endl;
	} else if (current->next == nullptr) {
		//if key is the last node => insert
		current->next = node;
		node->prev = current;
		m_tail = node;
	} else {
		NodePtr nextPtr = current->next;
		current->next = node;
		node->prev = current;
		node->next = nextPtr;
		nextPtr->prev = node;
	}
	++m_size;
}

void List::insert_before(int key,const int& val)
{
	NodePtr node = new Node(val);   
	//find the position
	NodePtr current = m_tail;

	while (current != nullptr && current->data != key) {
		current = current->prev;
	}

	//if key is not there =>error
	if (current == nullptr) {
		std::cout<<"Key not found:" << std::endl;
	} else if (current->prev == nullptr) {
		//if key is the first node => insert
		current->prev = node;
		node->next = current;
		m_head = node;
	} else {
		NodePtr prevPtr = current->prev;
		current->prev = node;
		node->next = current;
		node->prev = prevPtr;
		prevPtr->next = node;
	}
	++m_size;
}

int List::top_front() const
{
	if (is_empty()) {
		std::cout << "List is empty" << std::endl;
		return 0;
	} else {
		return m_head->data;
	}
}

int List::top_back() const
{   
    if (is_empty()) {
        std::cout << "List is empty" << std::endl;
		return 0;
    } else {
        return m_tail->data;
    }   
}

int List::pop_front()
{
	int item;
	if (is_empty()) {
        std::cout << "List is empty" << std::endl;
		return 0;
    } else {
		NodePtr nextPtr = m_head->next;
		if (nextPtr->next != nullptr) {
			nextPtr->prev = nullptr;
		}
		item = m_head->data;
		delete m_head;    //remove head
		m_head = nextPtr; //make nextptr head
	}
	--m_size;
	return item;
}

int List::pop_back()
{
    int item;
    if (is_empty()) {
        std::cout << "List is empty" << std::endl;
        return 0;
    } else {
        NodePtr prevPtr = m_tail->prev;
        if (prevPtr->prev != nullptr) {
            prevPtr->next = nullptr;
        }
        item = m_tail->data;
		m_tail->prev = nullptr;
        delete m_tail;    //remove head
        m_tail = prevPtr; //make nextptr head
    }
	--m_size;
    return item;
}

void List::remove(int key)
{
    if (is_empty()) {
        std::cout << "List is empty" << std::endl;
        return;
    }

	if (!find(key)) {
		std::cout << "Invalid value" << std::endl;
        return;
	}
	
	//get to the position of key
    NodePtr current = m_head;
	while (current != nullptr && current->data != key) {
        current = current->next;
    }

	if (current->prev == nullptr) {
        //if key is the first node
		pop_front();
    } else if (current->next == nullptr) {
		// if key is the last node
		pop_back();
    } else { 
		//anywhere in between first and last
		NodePtr nextPtr = current->next;
        NodePtr prevPtr = current->prev;
        nextPtr->prev = prevPtr;
        prevPtr->next = nextPtr;

        current->next = nullptr;
        current->prev = nullptr;
        delete current;
        current = nullptr;
	}
	--m_size;
}

void List::clear()
{
	NodePtr current = m_head;
    while (current != nullptr) {
		NodePtr nextPtr = current->next;	
	   	delete current;
		current = nextPtr;			
    }
	m_head = 0;
	m_size = 0;
}

void List::print() const
{
	if (is_empty()) {
		std::cout << "List is empty:" << std::endl;
		return;
	}

	NodePtr current = m_head;

    while (current != nullptr) {
    	std::cout << current->data <<" ";
        current = current->next;
    }
	std::cout << std::endl;
}

void List::print_reverse() const 
{
	if (is_empty()) {
        std::cout << "List is empty:" << std::endl;
        return;
    }

    NodePtr current = m_tail;

    while (current != nullptr) {
        std::cout << current->data <<" ";
        current = current->prev;
    }
    std::cout << std::endl;
}

bool List::is_empty() const
{
	return m_head == nullptr;
}

int List:: get_size() const
{
	return m_size;
}

bool List::find(int val) const
{
	if (is_empty()) {
    	return false;
    }

    NodePtr current = m_head;
    while (current != nullptr && current->data != val) {
    	current = current->next;
    }

    if (current == nullptr) {
    	return false;
    }

        return true;
}


int main()
{
	/* testing */
	
	List list(5,1); // call user ctor
    list.insert_front(1);
    list.insert_back(4);
	std::cout << "Print list:        ";
    list.print();
    std::cout << "Size of list:      " << list.get_size() << std::endl;
	
	List list2(list); // call copy ctor
	std::cout << "Print copy:        ";
	list2.print();
	
	List list3;
	list3 = list2; // call assignment op
	std::cout << "Print = :          ";
	list3.print();
	
	std::cout << "Invalid insert:    ";
    list.insert_after(2, 33); // invalid
	list.clear();
	std::cout << "Print empty list:  ";
	list.print();
	return 0;
}
