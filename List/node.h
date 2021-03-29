#ifndef NODE_H
#define NODE_H

class Node
{
    public:
        int data;
        Node* prev;
        Node* next;

        Node();
        Node (const int& value);
        Node (const Node& node);
};

#endif

