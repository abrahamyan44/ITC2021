#include "list.h"

int List::Size() const
{
    int size = 0;
    if (m_head != nullptr) {
        Node* current = m_head;
        while (current) {
            ++size;
            current = current->m_next;
        }
    } return size;
}

void List::Insert (int position, const int& value)
{
    if (position < 0) {
        return;
    }
    assert(0 <= position);
    Node* current = m_head;
    for (int i = 0; i < position - 1; ++i) {
        current = current->m_next;
    } Node* current1 = current;
    Node* node = new Node (value);
    current->m_prev->m_next = node;
    node->m_prev = current1->m_prev;
    node->m_next = current1;
    current1->m_prev = node;
}

void List::PushBack (const int& value)
{
    Node* node = new Node (value);
    if (m_head == nullptr) {
        m_head = node;
        m_head->m_next = m_tail;
    } else {
        m_tail->m_next = node;
        node->m_prev = m_tail;
    } m_tail = node;
}

void List::PushFront (const int& value)
{
    Node* node = new Node (value);
    if (m_head == nullptr) {
        m_head = node;
        m_tail = node;
        return;
    } else {
        m_head->m_prev = node;
        node->m_next = m_head;
    } m_head = node;
}

int List::TopBack()
{
    assert (m_head != nullptr);
    assert (0 < Size());
    return m_tail->m_data;
}

int List::TopFront()
{
    assert (m_head != nullptr);
    assert (0 < Size());
    return m_head->m_data;
}

void List::PopBack()
{
    if (m_head == nullptr) {
        return;
    } Node* current = m_tail;
    m_tail = m_tail->m_prev;
    m_tail->m_next = nullptr;
    m_tail->m_prev = current->m_prev;
}

void List::PopFront()
{
    if (m_head == nullptr) {
        return;
    } Node* current = m_head;
    m_head = m_head->m_next;
    m_head->m_prev = nullptr;
}

void List::Erase (int position)
{
    if (position < 0) {
        return;
    } assert(0 <= position);
    assert (this->Size() >= 0);
    Node* current = m_head;
    if (m_head == nullptr) {
	    return;
    } if (position == 0) {
        m_head = m_head->m_next;
        m_head->m_prev = nullptr;
        free(current);
        return;
    } for (int i = 1; i < position - 1 && current != nullptr; ++i) {
        current = current->m_next;
    } if(current == nullptr || current->m_next == nullptr) {
        return;
    } Node* current1 = current->m_next->m_next;
    free(current->m_next);
    current->m_next = current1;
}

Iterator List::Begin()
{
    return m_head;
}

Iterator List::End()
{
    return m_tail->m_next;
}

List::List()
	:m_head(nullptr),
	m_tail(nullptr) {}

List::List (int count, int value)
{
    for (int i = 0; i < count; ++i) {
         Node* node = new Node(value);
         if (m_head == nullptr) {
             m_head = node;
             m_tail = node;
         } m_tail->m_next = node;
         node->m_prev = m_tail;
         m_tail = m_tail->m_next;
    }
}

List::List (const List& other)
{
    m_head = other.m_head;
}

List::~List()
{
    if (m_head == nullptr) {
        return;
    } Node* current = m_head;
    while (current->m_next) {
        auto current1 = current;
        current = current->m_next;
        delete current1;
    }
}

List& List::operator= (const List& other)
{
    if (this == &other) {
        return *this;
    } m_head = other.m_head;
    return *this;
}

std::ostream& operator<< (std::ostream& out, const List& other)
{
    if (other.m_head == nullptr) {
        out << "no list";
        return out;
    } Node* current = other.m_head;
    while (current != nullptr) {
        out << current->m_data << " ";
        current = current->m_next;
    } return out;
}
    
