#include "list.h"
#include <iostream>
using namespace std;

// Inserts a new node with the given value, in sorted order.
// IMPLEMENT THIS METHOD
void List::insertSorted(int value) {

    if (isEmpty() || value < m_head->m_value) {
        m_head = new Node(value, m_head);
    }
    else {
        Node *ptr = m_head;

        while (ptr->m_next->m_value < value && ptr->m_next != NULL) {
            ptr = ptr->m_next;
        }

        ptr->m_next = new Node(value, ptr->m_next);
    }
}

if (isEmpty() || value < m_head->m_value) {
m_head = new Node(value, m_head);
} else {
Node *node = m_head;
while (node->m_next != NULL && node->m_next->m_value < value)
node = node->m_next;
node->m_next = new Node(value, node->m_next);
}
}
