// pqueue.cpp
// Curiel, Pablo
// pacuriel
#include "pqueue.h"

// Class destructor to delete all nodes
Pqueue::~Pqueue() {
    while (!empty()) {
        dequeue();
    }
}

// Method to return priority of first element
int Pqueue::first_priority() {
    int first;
    if (empty()) {
        first = -1;
    }
    else {
        first = m_head->m_priority_time;
    }
    return first; // Returning priority of first element
}

// Method to add new list element sorted by priority
void Pqueue::enqueue(Cust *cust_obj, int priority) {
    if (empty() || priority < m_head->m_priority_time) {
        m_head = new Node(cust_obj, priority, m_head);
        m_count++;
    }
    else {
        Node *node_ptr = m_head;
        while (node_ptr->m_next != NULL && priority >= node_ptr->m_next->m_priority_time) {
            node_ptr = node_ptr->m_next;
        }
        node_ptr->m_next = new Node(cust_obj, priority, node_ptr->m_next);
        node_ptr->m_next->m_priority_time = priority;
        m_count++;
    }
}

// Method to remove the first element on the list
Cust* Pqueue::dequeue() {
    Cust *cust_to_return;
    // Removing from front of list (FIFO)
    if (!empty()) {
        cust_to_return = m_head->m_cust_obj;
        Node *temp = m_head;
        m_head = m_head->m_next;
        delete temp;
        m_count--;
    }
    return cust_to_return; // Returing removed Cust object pointer
}