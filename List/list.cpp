#include "list.h"

int List::size() const
{
    int s = 0;
    if (head != nullptr) {
        Node* tmp = head;
        while (tmp) {
            ++s;
            tmp = tmp->next;
        }
    } return s;

}

void List::insert (int pos, const int& value)
{
    if (pos < 0) {
        return;
    }
    assert(0 <= pos);
    Node* tmp = head;
    for (int i = 0; i < pos - 1; ++i) {
        tmp = tmp->next;
    }
	Node* tmp1 = tmp;
    Node* node = new Node(value);
    tmp->prev->next = node;
    node->prev = tmp1->prev;
    node->next = tmp1;
    tmp1->prev = node;
}

void List::push_back(const int& value)
{
    Node* node = new Node(value);
    if (head == nullptr) {
        head = node;
        head->next = tail;
    } else {
        tail->next = node;
        node->prev = tail;
    } tail = node;
}

void List::push_front(const int& value)
{
    Node* node = new Node(value);
    if (head == nullptr) {
        head = node;
        tail = node;
        return;
    } else {
        head->prev = node;
        node->next = head;
    } head = node;
}

int List::top_back()
{
    assert(head != nullptr);
    assert(0 < size());
    return tail->data;
}

int List::top_front()
{
    assert(head != nullptr);
    assert(0 < size());
    return head->data;
}

void List::pop_back()
{
    if(head == nullptr) return;
    Node* tmp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    tail->prev = tmp->prev;
}

void List::pop_front()
{
    if(head == nullptr) return;
    Node* tmp = head;
    head = head->next;
    head->prev = nullptr;
}

void List::erase (int pos)
{
    if (pos < 0) {
        return;
        } assert(0 <= pos);
        assert(this->size() >= 0);
        Node* tmp = head;
        if (head == nullptr) return;
        if (pos == 0) {
            head = head->next;
            head->prev = nullptr;
            free(tmp);
            return;
    } for (int i = 1; i < pos - 1 && tmp != nullptr; ++i) {
                tmp = tmp->next;
        } if(tmp == nullptr || tmp->next == nullptr) {
           return;
        } Node* tmp1 = tmp->next->next;
        free(tmp->next);
        tmp->next = tmp1;
}

Iterator List::begin()
{
    return head;
}

Iterator List::end()
{
    return tail->next;
}

List::List():head(nullptr),tail(nullptr) {}

List::List(int count, int value)
{
    for (int i = 0; i < count; ++i) {
         Node* node = new Node(value);
         if (head == nullptr) {
             head = node;
             tail = node;
         } tail->next = node;
         node->prev = tail;
         tail = tail->next;
    }
}

List::List(const List& ll)
{
    head = ll.head;
}

List::~List()
{
    if (head == nullptr) {
        return;
    } Node* tmp = head;
    while (tmp->next) {
        auto tmp1 = tmp;
        tmp = tmp->next;
        delete tmp1;
    }
}

List& List::operator=(const List& ll)
{
    if (this == &ll) {
        return *this;
    } head = ll.head;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const List& ll)
{
    if(ll.head == nullptr) {
        out << "no list";
        return out;
    } Node* tmp = ll.head;
    while (tmp != nullptr) {
        out << tmp->data << " ";
        tmp = tmp->next;
    } return out;
}

          
