template <class T>
struct Node
{
    Node <T>* left;
    Node <T>* right;
    T data;
};

template <class T>
class BST
{
private:
    Node <T>* m_root;
public:
    BST(); //empty tree
    ~BST();
 
    Node <T>* CreateBST(T* arr, int start, int end); //create BST from sorted array
    void SortedArray(T* arr, int size); //function for helping to make a BST from sorted array
    void MakeEmpty(Node <T>* leaf); //function for helping destructor
    bool IsEmpty(); //checks if tree exists or not
    void Insert(T value); //function that adds a new node with a given value to a tree
    Node <T>* GetRoot(); //function for getting the root
    void PrintInOrder(Node <T>* root); //tree inorder traversal for printing the tree 
    Node <T>* GetMinimumNode(Node <T>* node); //getting the node with minimum value
    Node <T>* Remove(Node <T>* root, int value); //function that removes a node from a tree
};
