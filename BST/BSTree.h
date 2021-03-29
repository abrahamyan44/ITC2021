class BSNode
{
    public:
        int m_data;
        BSNode* m_left;
        BSNode* m_right;

    public:

        BSNode();
        BSNode(int value);

};

class BSTree
{
    private:
        BSNode* m_root;
        void DestructorHelper (BSNode* root);

    public:

        BSNode* insert (BSNode* root, int value);
        void PreOrder (BSNode* root);
        void InOrder (BSNode* root);
        void PostOrder (BSNode* root);

        BSTree();
        ~BSTree();

};

