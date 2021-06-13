#include <iostream>
#include <vector>

class Node{

public:
	int data;
	class Node* left, *right;
	Node(int data){
		this->data = data;
		left = right = nullptr;
	}
};


void PrintPreorder(class Node* node){
    if (node == nullptr){
        return;
    }
    std::cout << node->data << " ";
    PrintPreorder(node->left);
    PrintPreorder(node->right);

}

void PrintPostorder(class Node* node){
	if(node == nullptr){
		return;
	}

		PrintPostorder(node->left);
		PrintPostorder(node->right);
		std::cout << node->data<<" ";
}

void PrintInOrder(class Node* node){
	if(node == nullptr){
		return;
	}
	PrintInOrder(node->left);
	std::cout << node->data << " ";
	PrintInOrder(node->right);
}

class Node* InputElements(std::vector<int>& v){
	class Node *root = new Node (v[0]);
	root->left = new Node(v[1]);
	root->right = new Node(v[2]);
	root->left->left = new Node(v[3]);
	root->left->right = new Node(v[4]);
	return root;
}

void SelectTraversalOfBinaryTree(std::vector<int>& v){
	int n;
	std::cout<<"Select traversal function\n";
	std::cout<<" 1.PrintPreorder \n 2.PrintPostorder \n 3.PrintInOrder\n";
	std::cin>>n;
	switch(n){
		case 1:
			PrintPreorder(InputElements(v));
			break;
		case 2:
			PrintPostorder(InputElements(v));
			break;
		case 3:
			PrintInOrder(InputElements(v));
			break;
	}
}

void TreeStructure(std::vector<int>& v){
	std::cout << "binary tree structure!!!" << std::endl;
    std::cout << "    "; std::cout<<v[0]; std::cout << "    " << std::endl;
    std::cout << std::endl;
    std::cout <<"  "; std::cout <<v [1]; std::cout << "    "; std::cout << v[2] << std::endl;
    std::cout << std::endl;
    std::cout << v[3];std::cout << "   "; std::cout << v[4] << std::endl;
}


int main(){
	std::vector<int> v;
	int n ;
	std::cout << "Input 5 elements of binary tree\n";
	    for(int i = 0 ; i < 5; ++i){
        std::cin>>n;
        v.push_back(n);
    }
	TreeStructure(v);
	SelectTraversalOfBinaryTree(v);
	return 0;
}
