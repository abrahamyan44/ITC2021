#include <iostream>
using namespace std;

template <class T>
class BinarySearchTree
{
private:
	struct Node{
		T m_data;
		T* left;
		T* right;
		
		Node() {
			m_data = 0;
			T* left =nullptr;
			T* right = nullptr;
		}
	};
	
	Node* root;

	Node* MakeEmpty(Node* node) {
		if(node == nullptr) {
			cout << "Nothing to delete." << endl;
			return 0;
		}
		if(node != nullptr) {
			MakeEmpty(node->left);
			MakeEmpty(node->right);
			delete node;
		}
		return 0;
	}
	
	Node* insert(T value, Node* node){
		if (node == nullptr) {
			node = new Node;
			node-> m_data = value;
			node->left = nullptr;
			node->right = nullptr;
		}
		if(node != nullptr){
			if(value > node->m_data) {
				node->right = insert(value, node->right);
			} else if (value < node->m_data) {
				node->left = insert(value, node->left);
			}
		}
		return node;
	}
	
	Node* min_value(Node* node) {
		if(node == nullptr) {
			cout << "Node is empty." << endl;
			return 0;
		}
		if (node->left == nullptr) {
			return node;
		} else{
			return min_value(node->left);
		}
	}

	Node* remove (T value, Node* node){
		Node* temp;
		if (node == nullptr) {
			cout << "Nothing to delete." << endl;
			return 0;
		} else if(value > node->m_data) {
			return remove(value, node->right);
		} else if(value < node->m_data) {
			return remove(value, node->left);
		} else if(node->left && node->right) {
			temp = min_value(value, node->right);
			value->m_data = temp->m_data;
			node->right = remove(node->m_data, node->right);
		} else {
			temp = node;
			if(node->right == nullptr){
				node = node->left;
			} else if (node-> left == nullptr) {
				node = node->right;
			}
			delete temp;
		}
		return node;
	}

	void inorder(Node* node){
		if(node == nullptr){
			return;
		} else {
			print(node->left);
			cout << node->m_data << "\t";
			print(node->right);
		}
		cout << endl;
	}

public:
	
	BinarySearchTree() {
		root == nullptr;
	}
	
	~BinarySearchTree() {
		root = MakeEmpty(root);
	}

	void insert(T value) {
		root = insert(value, root);
	}

	void remove(T value) {
		root = remove(value, root);
	}

	void print() {
		inorder(root);
	}
};

int main() 
{
	BinarySearchTree<int> element;
	element.insert(16);
	element.insert(24);
	element.insert(32);
	element.print();
	cout << "let's remove 24" << endl;
	element.remove(24);
	element.print();
}



