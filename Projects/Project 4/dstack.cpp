// dstack.cpp
// Curiel, Pablo
// pacuriel
#include "dstack.h"
#include <iostream>

// Method to push new nodes to top of stack
void Dstack::push(double value) {
    m_head = new Node(value, m_head);
    m_size++;
}

// Method to pop nodes from top of stack
bool Dstack::pop(double &value) {
    bool result = false; // Initializing result to false
    // Deleting nodes from the top of the stack
    if (!empty()) {
        value = m_head->m_value;
        Node *ptr = m_head;
        m_head = m_head->m_next;
        delete ptr;
        m_size--;
        result = true;
    }
    return result;
}