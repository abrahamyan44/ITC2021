#pragma once

template <class T>
class BinSTree {

    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(const T& data)
            :data(data), left(nullptr), right(nullptr) {}
    };

    Node* m_root;

    void Print(const std::string type, Node*& node);
    void InsertRecursive(Node*& node, const T& data);
    void TreeCopyRecursive(Node*& other_node, Node*& my_node);
    void TreeDeleteRecursive(Node*& node);
    Node* FindDeletableNodesParentRecursive(Node*& node, const T& data);
    void GetDeletableAndParentNodes(Node*& parent_node, Node*& deletable_node, const T& data);
    T FindSubstituteNodeDataRecursive(Node*& parent_node, Node*& substitute_node);
    void GetAndReplaceSubstituteNode(Node*& parent_node, Node*& deletable_node);
    void ReplaceSubstituteAndDeletableNodes(Node*& parent_node, Node*& deletable_node, Node*& substitute_node);


public:
    BinSTree();
    BinSTree(T* arr, int size);
    BinSTree(BinSTree& other);
    ~BinSTree();
    void Insert(const T& data);
    void Remove(const T& data);
    void PrintInorder();
    void PrintPreorder();
    void PrintPostorder();
    BinSTree& operator=(BinSTree& other);
};