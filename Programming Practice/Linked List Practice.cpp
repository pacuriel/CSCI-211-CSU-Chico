#include <iostream>
using namespace std;

class SortedList {
public:
    SortedList() { m_size = 0; m_head = NULL; }
    ~SortedList() { removeAll(); }
    bool isEmpty() { return (m_head == NULL); }
    int getSize() { return m_size; }
    bool insertValue(int value);
    bool removeValue(int value);
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

    SortedList obj;
    obj.insertValue(7);
    obj.insertValue(5);
    obj.insertValue(9);
    obj.insertValue(8);

    obj.print();

    obj.removeAll();
    return 0;
}
