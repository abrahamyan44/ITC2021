#include "bst.hpp"


BST::BST(const int* data, const int size)
{
		root = nullptr;
		for (int i = 0; i < size; i++)
		{
				insert(data[i]);
		}
}

void BST::insert(int value)
{
		root = insert_node(value, root);
}

Node* BST::insert_node(int value, Node* node)
{
		if (node == nullptr)
		{
				node = new Node;
				node->value = value;
				node->left = node->right = nullptr;
		}
		else if(value < node->value)
		{
				node->left = insert_node(value, node->left);
		}
		else
		{
				node->right = insert_node(value, node->right);
		}
		return node;
}

void BST::preOrder(Node*node)
{
		if (node == nullptr)
				return;
		std::cout << node->value << " ";
		//if (node->left == nullptr || node->right == nullptr)
		//	return;
		preOrder(node->left);
		preOrder(node->right); 
}
void BST::print_preOrder()
{
		std::cout << "PreOrdered traversal" << std::endl;
		preOrder(root);
		std::cout << std::endl;
}

void BST::inOrder(Node*node)
{
		if (node == nullptr)
				return;
		inOrder(node->left);
		std::cout << node->value << " ";
		inOrder(node->right);
}
void BST::print_inOrder()
{
		std::cout << "InOrdered traversal" << std::endl;
		inOrder(root);
		std::cout << std::endl;
}

void BST::postOrder(Node*node)
{
		if (node == nullptr)
				return;
		postOrder(node->left);
		postOrder(node->right);
		std::cout << node->value << " ";

}
void BST::print_postOrder()
{
		std::cout << "PostOrdered traversal" << std::endl;
		postOrder(root);
		std::cout << std::endl;
}
