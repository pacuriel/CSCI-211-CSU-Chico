#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

// DO NOT MODIFY THIS FILE

class List {
public:
    List() { m_head = NULL; }
    ~List() {};
    bool isEmpty() { return (m_head == NULL); }
    void print() {
        Node *node = m_head;
        while(node != NULL) {
            cout << node->m_value << " ";
            node = node->m_next;
        }
        cout << endl;
    }
    void insertSorted(int value);
private:
    class Node {
    public:
        Node(int value, Node *next) { m_value = value; m_next = next; }
        int m_value;
        Node *m_next;
    };
    Node *m_head;
};
#endif
