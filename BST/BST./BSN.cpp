#include "BSN.h"

BinarySearchNode::BinarySearchNode()
    :m_left (nullptr),
    m_right (nullptr) {}

BinarySearchNode::BinarySearchNode (int value)
    :m_data (value),
    m_left (nullptr),
    m_right (nullptr) {}

