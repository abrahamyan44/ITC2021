#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <cassert> // for assert()
//#include <algorithm>

template <typename T>

struct Node
{	
	Node(T val);

   	T value;
	int height;
	Node<T>* leftChild;
	Node<T>* rightChild;
	Node<T>* parent;		
};

template <typename T>
using NodePtr = Node<T>*;

template <typename T>
class BinarySearchTree
{
private:
	int m_size; // Size of elements
	NodePtr<T> m_root;
protected:	
  	NodePtr<T> InsertHelper(NodePtr<T> root, T val); 		// Insert helper
  	NodePtr<T> SearchHelper(NodePtr<T> root, T val) const;  // Search helper
 	NodePtr<T> RemoveHelper(NodePtr<T> root, T val); 		// Remove helper
	T FindSuccessorHelper(NodePtr<T> root) const; 		 	// Find successor helper
	T FindPredecessorHelper(NodePtr<T> root) const;	 // Find predecessor helper
	T FindMinHelper(NodePtr<T> root) const;			 // Find min helper
	T FindMaxHelper(NodePtr<T> root) const;  		 // Find max helper
	void PrintInOrderHelper(NodePtr<T> root) const;	 // Print smallest to the greatest helper
	void PrintPreOrderHelper(NodePtr<T> root) const; // Print PreOrder
	void PrintPostOrderHelper(NodePtr<T> root) const;// Print PostOrder
	bool IsLeaf(NodePtr<T>) const;					 // Check is leaf?
	bool HasRightChild(NodePtr<T>) const;			 // Check has right child?	
	bool HasLeftChild(NodePtr<T>) const;			 // Check has left child?		
	bool HasBoth(NodePtr<T>) const;				 	 // Check has both children?	
  	
public:
  	BinarySearchTree();			  				 // Ctor
	BinarySearchTree(int* arr,const int size);	 // Ctor	

  	void Insert(T val); 		  				 // Insert the node to the BST
  	bool Search(T val) const; 		  			 // Find the given value in BST
  	void Remove(T val);        				 	 // Remove the given value in BST
	T FindSuccessor(T val) const;  				 // Find the Successor of a given key
	T FindPredecessor(T val) const;				 // Find the Predecessor of a given key
	T FindMin() const ;				 		     // Find the min
	T FindMax() const; 				 			 // Find the max
	int GetSize() const;						 // Get size		
	
	void PrintInOrder() const;   // Print all the keys of BST sorted from smallest to the greatest key
	void PrintPreOrder() const;  // Print PreOrder
	void PrintPostOrder() const ;// Print PostOder
};
#endif //BST_HPP

