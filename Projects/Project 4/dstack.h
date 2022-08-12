// dstack.hs
// Curiel, Pablo
// pacuriel
#ifndef DSTACK_H
#define DSTACK_H
#include <iostream>

class Dstack {
public:
    Dstack() { m_head = NULL; m_size = 0; }; // Dstack constructor
    ~Dstack() { double temp; while (pop(temp)); } // Dstack destructor to free memory
    void push(double value);
    bool pop(double &value);
    int size() { return m_size; } // Returns size of stack
    bool empty() { return (m_head == NULL); } // Returns true if stack is empty
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
