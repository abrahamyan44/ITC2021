
struct Node
{
	Node(int val);
	int data;
	Node* next; // points to the next node in the list.
	Node* prev; // points to the previous node in the list.
};

typedef Node* NodePtr;


