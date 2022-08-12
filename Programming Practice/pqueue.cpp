//
// Created by Tony PC on 3/10/2021.
//
#include <iostream>
using namespace std;


class Pqueue {
public:
    Pqueue();
    ~Pqueue();
    void enqueue(int priority, string value);
    bool dequeue(string &value_out);
    bool isEmpty();
private:
    class Node {
    public:
        int m_priority;
        string m_value;
        Node *m_next;
        Node(int priority, string value, Node *next)
        { m_priority = priority; m_value = value; m_next = next; }
    };
    Node* m_head;
};

void Pqueue::enqueue(int priority, string value) {
    if (isEmpty() || priority < m_head->m_priority) {
        m_head = new Node(priority, value, m_head);
    }
    else {
        Node *ptr = m_head;
        while (ptr->m_next != NULL && priority >= ptr->m_next->m_priority) {
            ptr = ptr->m_next;
        }
        ptr->m_next = new Node(priority, value, ptr->m_next);
    }
}