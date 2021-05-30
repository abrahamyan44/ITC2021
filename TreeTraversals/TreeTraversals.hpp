template <class T>
struct node 
{
    node <T>* left;
    node <T>* right;
    T data;
};

template <class T>
class Tree
{
private:
    node <T>* m_root;

public:
    Tree(); //empty tree with no nodes
    node <T>* CreateNode(T data); //creating new node
    ~Tree(); 

    void MakeEmpty(node <T>* leaf); //function for helping destructor
    
    void InOrderRecursively(node <T>* root); //recursive function for inorder tree traversal
    void PreOrderRecursively(node <T>* root); 
    void PostOrderRecursively(node <T>* root);  

    void InOrder(node <T>* root); //iterative function for inorder tree traversal
    void Print(node <T>* root); //function for printing the tree level by level
};
