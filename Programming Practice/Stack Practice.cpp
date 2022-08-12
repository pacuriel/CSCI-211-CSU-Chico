#include <iostream>
using namespace std;

class Stack {
public:
    Stack() { m_size = 0; m_head = NULL; }
    // Will run pop(value) as long as pop is true
    ~Stack() { int value; while (pop(value)); }
    bool isEmpty() { return (m_head == NULL); }
    int getSize() { return m_size; }
    void push(int value);
    bool pop(int &value_out); //Memory address as a parameter
    bool removeAll();
    void print();
private:
    class Node {
    public:
        Node(int value, Node *next) {m_value = value; m_next = next; }
        ~Node() {}
        int m_value;
        Node *m_next;
    };
    int m_size;
    Node *m_head;
};

void Stack::push(int value) {
    // One line of code needed to insert new
    // nodes at front of list
    m_head = new Node(m_value, m_head);
    m_size++;
}

bool Stack::pop(int &value_out) {
    bool result = false;
    if (!isEmpty()) {
        Node *node = m_head;
        m_head = m_head->m_next;
        value_out = node->m_value;
        delete node;
        result = true;
        m_size--;
    }
    return result;
}

bool SortedList::removeAll() {
    bool result = false;
    if (!isEmpty()) {
        Node *node_ptr = m_head;

        while (node_ptr != NULL) {
            Node *temp = node_ptr;

            node_ptr = node_ptr->m_next;

            delete temp;

            result = true;

            m_head = node_ptr;
        }
    }
    return result;
}

bool SortedList::insertValue(int value) {
    // Insert node at front of list if is empty
    if (isEmpty() || value < m_head->m_value) {
        m_head = new Node(value, m_head);
    }
    else {
        Node *node_ptr = m_head;
        while (node_ptr->m_next != NULL && node_ptr->m_value < value) {
            node_ptr = node_ptr->m_next;
        }
        node_ptr->m_next = new Node(value, node_ptr->m_next);
    }
}
void SortedList::print() {

    Node *node_ptr = m_head;

    while (node_ptr != NULL) {
        // Print current node's value
        cout << node_ptr->m_value << endl;
        // Advancing node pointer to next node
        node_ptr = node_ptr->m_next;
    }


}

int main() {

    Stack obj;
    obj.push(7);
    obj.push(5);
    obj.push(9);
    obj.insertValue(8);

    int value;



    return 0;
}
