#include "BST.hpp"

template <typename T>
Node<T>::Node(T val)
	:value(val)
	,height(0)
	,leftChild(nullptr)
	,rightChild(nullptr)
	,parent(nullptr)
{} 

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
	:m_size(0)
	,m_root(nullptr)
{}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(int* arr, const int size)
	:m_size(0)
	,m_root(nullptr)
{
	for (int i = 0; i < size; ++i) {
		assert(0 != arr);
		Insert(arr[i]);
	}
	assert(0 != m_size);
	assert(size == m_size);
}

template <typename T>
NodePtr<T> BinarySearchTree<T>::InsertHelper(NodePtr<T> root, T val)
{
	if (nullptr == root) {
		// if BinarySearchTree doesn't exitst
		// create new root
		root = new Node<T>(val);
		} else if (val > root->value) {
		// if the given value is greater than root's value
		// go to right subtree
		root->rightChild = InsertHelper(root->rightChild, val);
		root->rightChild->parent = root;
	} else {
		// if the given value is smaller than root's value
		// go to left subtree
		root->leftChild = InsertHelper(root->leftChild, val);
		root->leftChild->parent = root;
	}	
	return root;
}

template <typename T>
void BinarySearchTree<T>::Insert(T val)
{
	m_root = InsertHelper(m_root, val);
	++m_size;
}

template <typename T>
NodePtr<T> BinarySearchTree<T>::SearchHelper(NodePtr<T> root, T val) const
{
	// if the given val is not found in BinarySearchTree 
	if (nullptr == root) {
		return nullptr;
	} else if (val == root->value) {
		// the given val is found
		return root;
	} else if (val > root->value) {
		// greater than current value
		return SearchHelper(root->rightChild,val);
	} 
		//smaller than current value
		return SearchHelper(root->leftChild,val);
}
 
template <typename T>
bool BinarySearchTree<T>::Search(T val) const
{
	NodePtr<T> result = SearchHelper(m_root,val);
	return (nullptr != result);
}

template <typename T>
NodePtr<T> BinarySearchTree<T>::RemoveHelper(NodePtr<T> node, T val)
{
	// if the given val is not found in BinarySearchTree
	if (nullptr == node/* || (!Search(val)*/) {		
	//	std::cout << "The given val is not found in BinarySearchTree: " << std::endl;
		return nullptr;
	}	

	assert(nullptr != node);

	// node is found
	if (val == node->value) {
		// if node is a leaf
		if (IsLeaf(node)) {
			node = nullptr;  
		} else if (HasRightChild(node)) {
		// if node has right child => swap	
			node->rightChild->parent = node->parent;
			node = node->rightChild;
		} else if (HasLeftChild(node)) {
		// if node has left child => swap	
			node->leftChild->parent = node->parent;
			node = node->leftChild;
		} else {
		// the node has two children => find
		// successor or predecess and swap
			int successorVal = FindSuccessor(val);
			node->value = successorVal;
			//delete the old successor's val
			node->rightChild = RemoveHelper(node->rightChild,successorVal);
		}		
	} else if (val > node->value) {

		node->rightChild = RemoveHelper(node->rightChild, val);	
	} else {
		// if nede's value is greater than the given
		// val => search to left
		node->leftChild = RemoveHelper(node->leftChild, val);	
	}
	return node; // the updated BinarySearchTree 
}

template <typename T>
void BinarySearchTree<T>::Remove(T val)
{
	m_root = RemoveHelper(m_root, val);
	--m_size;
}

template <typename T>
T BinarySearchTree<T>::FindMinHelper(NodePtr<T> root) const
{
	if (nullptr == root) {
		std::cout << "There is no tree:" << std::endl;
		return -1;
	} else if (nullptr == root->leftChild) {
		return root->value;
	}

	return FindMinHelper(root->leftChild);
}

template <typename T>
T BinarySearchTree<T>::FindMin() const
{
	return FindMinHelper(m_root);
}

template <typename T>
T BinarySearchTree<T>::FindMaxHelper(NodePtr<T> root) const
{
	if (nullptr == root) {
		std::cout << "There is no tree: " << std::endl;
		return -1;
	} else if (nullptr == root->rightChild) {
		return root->value;
	} 
	return FindMaxHelper(root->rightChild);
}

template <typename T>
T BinarySearchTree<T>::FindMax() const
{
	return FindMaxHelper(m_root);
}

template <typename T>
T BinarySearchTree<T>::FindSuccessorHelper(NodePtr<T> node) const
{
	// the successor is the min val or right subtree
	if (nullptr != node->rightChild) {
		return FindMinHelper(node->rightChild);
	} else {
	// if no any right subtree
		NodePtr<T> parentPtr = node->parent;
		NodePtr<T> currentPtr = node;

		// if current is not root and current is 
		// its right children => continue moving up
		while (nullptr != parentPtr &&
			   currentPtr == parentPtr->rightChild) {
			currentPtr = parentPtr;
			parentPtr = currentPtr->parent;
		}	

		/*if (nullptr == parentPtr) {
			std::cout << "It is a maximum number in the \ 
						  tree and does not have a successor: " << std::endl;
			return -1;

		} else {
			return parentPtr->value;
		}*/

	return (nullptr == parentPtr) ? -1 : parentPtr->value;	
	}
}

template <typename T>
T BinarySearchTree<T>::FindSuccessor(T val) const
{
	// search val
	NodePtr<T> valuePtr = SearchHelper(m_root,val);

	return (nullptr == valuePtr) ? -1 : FindSuccessorHelper(valuePtr);
}

template <typename T>
T BinarySearchTree<T>::FindPredecessorHelper(NodePtr<T> node) const
{
	// the predecessor is max value or lrft subtree
	if (nullptr != node->leftChild) {
		return FindMaxHelper(node->leftChild);
	} else {
	// if no left subtree
		NodePtr<T> currentPtr = node;
		NodePtr<T> parentPtr = node->parent;

		// if current is not root and current is 
		// its left children => continue moving up
		while (nullptr != parentPtr && 
			   currentPtr == parentPtr->leftChild) {
			currentPtr = parentPtr;
			parentPtr = currentPtr->parent;
		}
		// if parent is not nullptr => 
		// value of parent is the predecessor of node
		return (nullptr == parentPtr) ? -1 : parentPtr->value;	
	}
}

template <typename T>
T BinarySearchTree<T>::FindPredecessor(T val) const/////////////////
{
	// search val
	NodePtr<T> valuePtr = SearchHelper(m_root,val);
	
	return nullptr == valuePtr ? -1 : FindPredecessorHelper(valuePtr);
}

template <typename T>
int BinarySearchTree<T>::GetSize() const
{
	return m_size;
}

template <typename T>
bool BinarySearchTree<T>::IsLeaf(NodePtr<T> node) const
{
	return (nullptr == node->leftChild &&
			nullptr == node->rightChild);
}

template <typename T>
bool BinarySearchTree<T>::HasRightChild(NodePtr<T> node) const
{
	return (nullptr != node->rightChild);
}

template <typename T>
bool BinarySearchTree<T>::HasLeftChild(NodePtr<T> node) const
{
	return (nullptr != node->leftChild);
}

template <typename T>
bool BinarySearchTree<T>::HasBoth(NodePtr<T> node) const
{
	return (nullptr != node->leftChild &&
			nullptr != node->rightChild);
}

template <typename T>
void BinarySearchTree<T>::PrintInOrderHelper(NodePtr<T> root) const
{
	if (nullptr == root) {
		return;
	}
	assert(nullptr != root);
	
	//get the smallest val which is in the left subtree
	PrintInOrderHelper(root->leftChild);

	//print the val
	std::cout << root->value << " ";

	//continue to the greatest key which is in the right subtree
	PrintInOrderHelper(root->rightChild);
}

template <typename T>
void BinarySearchTree<T>::PrintInOrder() const
{
	// traverse the BinarySearchTree from m_root
	// then print all values
	PrintInOrderHelper(m_root);

	if (nullptr == m_root) {
		std::cout << "BinarySearchTree deosn't exist: " << std::endl;
	}

	std::cout << std::endl;
}

template <typename T>
void BinarySearchTree<T>::PrintPreOrderHelper(NodePtr<T> root) const
{
	if (nullptr == root) {
		return;
	}
	assert(nullptr != root);

	// first print the val
	std::cout << root->value << " ";

	// then requre on left subtree
	PrintInOrderHelper(root->leftChild);

	// now requre on right subtree
	PrintInOrderHelper(root->rightChild);
}

template <typename T>
void BinarySearchTree<T>::PrintPreOrder() const
{
	PrintPreOrderHelper(m_root);

	if (nullptr == m_root) {
		std::cout << "BinarySearchTree deosn't exist: " << std::endl;
	}
	std::cout << std::endl;
}

template <typename T>
void BinarySearchTree<T>::PrintPostOrderHelper(NodePtr<T> root) const
{
	if (nullptr == root) {
		return;
	}
	assert(nullptr != root);
	
	// first requre on left subtree
	PrintPostOrderHelper(root->leftChild);
	
	// then requre on left subtree
	PrintPostOrderHelper(root->rightChild);

	//print the val
	std::cout << root->value << " ";

}

template <typename T>
void BinarySearchTree<T>::PrintPostOrder() const
{
	PrintPostOrderHelper(m_root);

	if (nullptr == m_root) {
		std::cout << "BinarySearchTree deosn't exist: " << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	/***********testing**********/
	
	BinarySearchTree<float> B;
	B.PrintInOrder(); //empty

	BinarySearchTree<int> B2;
	B2.Insert(23);
	B2.Insert(12);
	B2.Insert(31);
	B2.Insert(3);
	B2.Insert(15);
	B2.Insert(7);
	B2.Insert(29);
	B2.Insert(88);
	B2.Insert(53);
	B2.PrintInOrder();
		
	std::cout << "Successor of 31 is: " << B2.FindSuccessor(31) << std::endl;
	std::cout << "Successor of 15 is: " << B2.FindSuccessor(15) << std::endl;
	std::cout << "Successor of 88 is: " << B2.FindSuccessor(88) << std::endl;		
	
	std::cout << "Predeccessor of 3 is: " << B2.FindPredecessor(3) << std::endl;
	std::cout << "Predeccessor of 29 is: " << B2.FindPredecessor(29) << std::endl;
	std::cout << "Predeccessor of 12 is: " << B2.FindPredecessor(12) << std::endl;

	std::cout << "Min is: " << B2.FindMin() << std::endl;
	std::cout << "Max is: " << B2.FindMax() << std::endl;

	B2.Remove(53);	
	std::cout << "In Order: ";
	B2.PrintInOrder();
	std::cout << "Pre Order: ";
 	B2.PrintPreOrder();
	std::cout << "Post Order: ";
	B2.PrintPostOrder();

	std::cout << "*********************************************" << std::endl;

	const int n = 3;
	int a[n] = {'a','b','9'};
	BinarySearchTree<char> B3(a,n);
	B3.PrintInOrder();

	std::cout << "Size is: " << B3.GetSize() << std::endl;

	return 0;
}

