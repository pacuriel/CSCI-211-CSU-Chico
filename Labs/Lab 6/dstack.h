#ifndef DSTACK_H
#define DSTACK_H
#include <iostream>
using namespace std;

class Dstack {
public:
    Dstack() { m_head = NULL; m_size = 0; };
    ~Dstack() { double temp; while (pop(temp)); }
    void push(double value);
    bool pop(double &value);
    int size() { return m_size; }
    bool empty() { return (m_head == NULL); }

private:
    class Node {
    public:
        double m_value;
        Node *m_next;
        Node (double value, Node *next) {
            m_value = value;
            m_next = next;
        }
    };
    Node *m_head;
    int m_size;
};

#endif
