#include "node.h"

Node::Node()
	:m_prev (nullptr),
	m_next (nullptr) {}

Node::Node (const int& value)
	:m_data (value),
   	m_prev (nullptr),
   	m_next (nullptr) {}

Node::Node (const Node& node) {
	this->m_data = node.m_data;
	m_prev = node.m_prev;
	m_next = node.m_next;
}


