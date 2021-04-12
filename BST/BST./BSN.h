#ifndef BSN_H
#define BSN_H

class BinarySearchNode
{
public:
	int m_data;
	BinarySearchNode* m_left;
	BinarySearchNode* m_right;
public:
	BinarySearchNode();
	BinarySearchNode(int value);
};

#endif

