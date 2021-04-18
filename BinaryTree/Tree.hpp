#ifndef _TREE_HPP
#define _TREE_HPP

template <typename T>
struct Node
{
public:
    //members
    T m_data;
    Node* m_left;
    Node* m_right;

    //constructors and destructor
    Node ()
        :m_data(0), m_left(nullptr), m_right(nullptr)
    {}
    Node (T value)
        :m_data(value), m_left(nullptr), m_right(nullptr)
    {}
    ~Node ()
    {
        delete m_left;
        delete m_right;
    }
};

template <typename T>
class Tree
{
private:
    //member
    Node<T>* root;
    
    void ConvertArrayToBinarySearchTree (Node<T>*& node, int* array, int start, int end);
    //Insert function
    void InsertFromGivenNode (Node<T>*& node, int value);

    //Print function
    void PrintPreOrderRecursively (Node<T>*);
    void PrintInOrderRecursively (Node<T>*);
    void PrintPostOrderRecursively (Node<T>*);

public:
    Tree ();
    Tree (int* array, int size);
    ~Tree ();
    
    //Insert function
    void Insert (int value);

    //Print function
    void PrintPreOrder ();
    void PrintInOrder ();
    void PrintPostOrder ();
};

template class Tree<int>;
#endif //_TREE_HPP

