#include <iostream>
 
using namespace std;
 
struct Node{
    int num;
    Node *next;
};
 
struct Node *head=nullptr;
 
void Insert(int n){
    struct Node *newNode = new Node;
    newNode -> num = n;
    newNode -> next = head;
    head = newNode;
}
 
void print() {
    if(head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    struct Node *temp = head;
    while(temp != nullptr) {
        cout << temp -> num << " ";
        temp = temp -> next;
    }
    cout << endl;
}
 
void remove() {
    if(head == nullptr){
        cout << "List is empty!" << endl;
        return;
    }
    cout << head -> num << " is removed." << endl;
    head = head -> next;
}

int main() { 
    print();
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    print();
    remove();
    print();
    return 0;
}
