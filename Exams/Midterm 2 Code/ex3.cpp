#include <iostream>
#include "ex3.h"
using namespace std;

// Enqueue the given value with the given priority, where GREATER priority values
// have HIGHER priority (the opposite of what we did in labs, projects and lecture).
void Pqueue::enqueue(int priority, string value) {
	// IMPLEMENT
	if (isEmpty() || priority > m_head->m_priority) {
	    m_head = new Node(priority, value, m_head);
	}
	else {
	    Node *temp = m_head;
	    while (temp->m_next != NULL && priority <= temp->m_next->m_priority) {
	        temp = temp->m_next;
	    }
	    temp->m_next = new Node(priority, value, temp->m_next);
	}
}
