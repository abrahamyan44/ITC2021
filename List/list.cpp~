#include "list.h"

int List::size() const
{
    int s = 0;
    if (m_head != nullptr) {
        Node* tmp = m_head;
        while (tmp) {
            ++s;
            tmp = tmp->m_next;
        }
    } return s;

}

void List::insert (int pos, const int& value)
{
    if (pos < 0) {
        return;
    }
    assert (0 <= pos);
    Node* tmp = m_head;
    for (int i = 0; i < pos - 1; ++i) {
        tmp = tmp->m_next;
    } Node* tmp1 = tmp;
    Node* node = new Node (value);
    tmp->m_prev->m_next = node;
    node->m_prev = tmp1->m_prev;
    node->m_next = tmp1;
    tmp1->m_prev = node;
}

void List::push_back (const int& value)
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

void List::push_front (const int& value)
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

int List::top_back()
{
    assert (m_head != nullptr);
    assert (0 < size());
    return m_tail->m_data;
}

int List::top_front()
{
    assert (m_head != nullptr);
    assert (0 < size());
    return m_head->m_data;
}

void List::pop_back()
{
    if (m_head == nullptr) {
		return;
	} Node* tmp = m_tail;
    m_tail = m_tail->m_prev;
    m_tail->m_next = nullptr;
    m_tail->m_prev = tmp->m_prev;
}

void List::pop_front()
{
    if (m_head == nullptr) {
	   	return;
	} Node* tmp = m_head;
    m_head = m_head->m_next;
    m_head->m_prev = nullptr;
}

void List::erase (int pos)
{
    if (pos < 0) {
        return;
        } assert(0 <= pos);
        assert (this->size() >= 0);
        Node* tmp = m_head;
        if (m_head == nullptr) {
		   	return;
		} if (pos == 0) {
            m_head = m_head->m_next;
            m_head->m_prev = nullptr;
            free(tmp);
            return;
    } for (int i = 1; i < pos - 1 && tmp != nullptr; ++i) {
                tmp = tmp->m_next;
        } if(tmp == nullptr || tmp->m_next == nullptr) {
           return;
        } Node* tmp1 = tmp->m_next->m_next;
        free(tmp->m_next);
        tmp->m_next = tmp1;
}

Iterator List::begin()
{
    return m_head;
}

Iterator List::end()
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

List::List (const List& ll)
{
    m_head = ll.m_head;
}

List::~List()
{
    if (m_head == nullptr) {
        return;
    } Node* tmp = m_head;
    while (tmp->m_next) {
        auto tmp1 = tmp;
        tmp = tmp->m_next;
        delete tmp1;
    }
}

List& List::operator= (const List& ll)
{
    if (this == &ll) {
        return *this;
    } m_head = ll.m_head;
    return *this;
}

std::ostream& operator<< (std::ostream& out, const List& ll)
{
    if (ll.m_head == nullptr) {
        out << "no list";
        return out;
    } Node* tmp = ll.m_head;
    while (tmp != nullptr) {
        out << tmp->m_data << " ";
        tmp = tmp->m_next;
    } return out;
}
    
