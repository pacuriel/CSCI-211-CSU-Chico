#include "dstack.h"
#include <iostream>
using namespace std;

void Dstack::push(double value) {
    m_head = new Node(value, m_head);
    m_size++;
}

bool Dstack::pop(double &value) {

    bool result = false;

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