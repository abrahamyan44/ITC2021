#ifndef NODE_H
#define NODE_H
template <class U>
class Node
{
public:
	Node* next;
	Node* prev;
	U value;
	Node()
		:next(nullptr),
		prev(nullptr) {}
	Node(const U& value)
		:value(value),
		next(nullptr),
		prev(nullptr) {}


};
template class Node<int>;
#endif // !NODE_H