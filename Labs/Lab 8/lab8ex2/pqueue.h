#ifndef PQUEUE_H
#define PQUEUE_H
#include <iostream>
#include "cust.h"
using namespace std;

// Class Pqueue
class Pqueue {
public:
    // Class constructor initializing m_head and m_count
    Pqueue() { m_head = NULL; m_count = 0; }
    // Class destructor to delete all nodes
    ~Pqueue();
    // Method to check if list is empty
    bool empty() { return (m_head == NULL); }
    // Method to return length of list
    int length() { return m_count;}
    // Method to return priority of first element
    int first_priority();
    // Method to add new list element sorted by priority
    void enqueue(Cust *cust_obj, int priority);
    // Method to remove the first element on the list
    Cust* dequeue();

private:
    class Node {
    public:
        Cust *m_cust_obj;
        int m_priority;
        Node *m_next;
        Node(Cust *cust_obj, int priority, Node *next) {
            m_priority = priority;
            m_cust_obj = cust_obj;
            m_next = next;
        }
    };
    Node *m_head;
    int m_count;
};

#endif
