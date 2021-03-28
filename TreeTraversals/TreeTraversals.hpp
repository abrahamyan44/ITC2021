template <class T>
struct Node 
{
    Node <T>* left;
    Node <T>* right;
    T data;
};

template <class T>
class Tree
{
private:
    Node <T>* m_root;

public:
    Tree(); //empty tree with no nodes
    Node <T>* CreateNode(T data); //creating new node
    ~Tree(); 

    void MakeEmpty(Node <T>* leaf); //function for helping destructor
    
    void InOrderRecursively(Node <T>* root); //recursive function for inorder tree traversal
    void PreOrderRecursively(Node <T>* root); 
    void PostOrderRecursively(Node <T>* root);  

    void InOrder(Node <T>* root); //iterative function for inorder tree traversal
    void Print(Node <T>* root); //function for printing the tree level by level
};
