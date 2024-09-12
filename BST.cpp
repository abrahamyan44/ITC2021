#include<iostream>

class BST {

   struct Node {
        int m_data;
        Node* left;
        Node* right;
		Node(){
			m_data = 0;
			left = right = nullptr;
		}
		Node(int d){
			m_data = d;
			left = right = nullptr;
		}
	};

Node* root;

public:
	BST();
	BST(int d);
	BST(int* arr, int size);
	Node* Insert(int x, Node* t);
	Node* findMin(Node* t);
	Node* findMax(Node* t);
	Node* Remove(int x, Node* t);
	void inorder(Node* t);
	void Insert(int x);
	void Remove(int x);
	int* Sort(int*& a, int size);
	void Print(); 
};

	BST::BST(){
		BST::root = nullptr;
	}
	

   BST::BST(int d) {
       root = new Node(d);
	   root->m_data = d;
	   root->left = root->right = nullptr;
    }


    BST::BST(int* arr, int size){
        Sort(arr,size);
        int index = (size - 1)/2;
        root = new Node(arr[index]);
        for(int i = 0; i < size; ++i){
            Insert(arr[i]);
        }
    }   

    int* BST::Sort(int*& a, int size){
        for (int i = 0; i < size - 1; ++i){
            for(int j = 0; j < size - 1; ++j){
                if(a[j] > a[j+1]){
                    int temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }
        return a;
    }


   	BST::Node* BST::Insert(int x, Node* t){
        if(t == nullptr){
            t = new Node;
            t->m_data = x;
            t->left = t->right = nullptr;
        }
        else if(x < t->m_data){
            t->left = Insert(x, t->left);
		}
        else if(x > t->m_data){
            t->right = Insert(x, t->right);
		}
        return t;
    }

    BST::Node* BST::findMin(Node* t){
        if(t == nullptr){
            return nullptr;
		}
        else if(t->left == nullptr){
            return t;
		}
        else{
            return findMin(t->left);
		}
    }

    BST::Node* BST::findMax(Node* t) {
        if(t == nullptr){
            return nullptr;
		}
        else if(t->right == nullptr){
            return t;
		}
        else{
            return findMax(t->right);
		}
    }

    BST::Node* BST::Remove(int x, Node* t) {
        Node* temp;
        if(t == nullptr){
            return nullptr;
		}
        else if(x < t->m_data){
            t->left = Remove(x, t->left);
		}
        else if(x > t->m_data){
            t->right = Remove(x, t->right);
		}
        else if(t->left && t->right){
            temp = findMin(t->right);
            t->m_data = temp->m_data;
            t->right = Remove(t->m_data, t->right);
        }
        else{
            temp = t;
            if(t->left == nullptr){
                t = t->right;
			}
            else if(t->right == nullptr){
                t = t->left;
			}
            delete temp;
        }

        return t;
    }

    void BST::inorder(Node* t) {
        if(t == nullptr){
            return;
		}
        inorder(t->left);
        std::cout << t->m_data << " ";
        inorder(t->right);
    }

       
    void BST::Insert(int x) {
        root = Insert(x, root);
    }

    void BST::Remove(int x) {
        root = Remove(x, root);
    }

    void BST::Print() {
        inorder(root);
        std::cout << std::endl;
    }
int main() {
    BST t;
    t.Insert(20);
    t.Insert(35);
    t.Insert(15);
    t.Insert(10);
    t.Insert(30);
    t.Print();
    t.Remove(10);
    t.Print();
    t.Remove(25);
    t.Print();
    t.Remove(30);
    t.Print();
	int a [] = {34,12,56,10,23};
    BST t1(a,5);
    t1.Print();
    return 0; 
}
