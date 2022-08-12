#ifndef POINT_STACK_H
#include <iostream>
using namespace std;

class PointStack {
public :
    PointStack();
    void push(int row, int col);
    bool pop(int &row, int &col);
    bool isEmpty();
private :
    class Node {
    public:
        int m_row, m_col;
        Node *m_next;
        Node(int row, int col, Node *next) {
            m_row = row; m_col = col; m_next = next;
        }
    };
    Node* m_head;
};
#endif