#ifndef _TREE_HPP
#define _TREE_HPP


template <typename T>
struct Node
{
    T m_data;
    Node* m_left;
    Node* m_right;

    Node()
        :m_data(0), m_left(0), m_right(0)
    {}

    Node(T value)
        :m_data(value), m_left(0), m_right(0)
    { 
    }
};

template <typename T>
class Tree
{
private:
    Node<T>* root;
    void ConvertArrayToBST(Node<T>* node, int* array, int start, int end);
    //Insert function
    void InsertHelper(Node<T>* node, int value);

    //Print function
    void PreorderHelper(Node<T>*);
    void InorderHelper(Node<T>*);
    void PostorderHelper(Node<T>*);

public:
    Tree();
    Tree(int* array, int size);
    ~Tree();
    
    //Insert function
    void Insert(int value);

    //Print function
    void Preorder();
    void Inorder();
    void Postorder();
};

#endif //_TREE_HPP

