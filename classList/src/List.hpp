#include <iostream>
#include <cassert>
#include "Node.hpp"

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


