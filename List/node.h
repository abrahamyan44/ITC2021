#ifndef NODE_H
#define NODE_H

class Node
{
public:
    int m_data;
    Node* m_prev;
    Node* m_next;
    Node();
	Node (const int& value);
	Node (const Node& node);
};

#endif

