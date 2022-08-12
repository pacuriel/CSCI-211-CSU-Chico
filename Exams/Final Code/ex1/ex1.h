#ifndef EX1_H
#define EX1_H
#include <iostream>
using namespace std;

// DO NOT MODIFY THIS FILE
class List {
public:
  List() { m_head = NULL; m_count = 0; }
  ~List() {
    while (m_head != NULL) {
      Node* temp = m_head;
      m_head = m_head->m_next;
      delete temp;
    }
  }
  bool isEmpty() { return (m_head == NULL); }
  int getCount() { return m_count; }
  void insertAtFront(int value) {
    m_head = new Node(value, m_head);
    m_count++;
  }
  int* getValues();
private:
  class Node {
  public:
    Node(int value, Node *next) { m_value = value; m_next = next; }
    int m_value;
    Node *m_next;
  };
  Node *m_head;
  int m_count;
};
#endif
