#include <iostream>
#include "queue.h"
using namespace std;

Queue::Queue() {
  m_head = NULL;
  m_tail = NULL;
  m_count = 0;

}

Queue::~Queue() {
  int value;
  while (dequeue(value));
}

bool Queue::isEmpty() {
  return (m_head == NULL && m_tail == NULL);
}

// Add node with given value to queue, return true on success.
void Queue::enqueue(int value) {
  // If empty, insert at beginning
  if (isEmpty()) {
    m_head = new Node(value, m_tail);
    m_tail = m_head;
    m_count++;
  }
  else {
    // Insert after last node.
    m_tail->m_next = new Node(value, m_tail->m_next);
    m_tail = m_tail->m_next;
    m_count++;
  }
}

// Return the value of the first node via value_out, delete that node.
// Returns true on success.
bool Queue::dequeue(int &value_out) {
  bool result = false;
  if (!isEmpty()) {
    Node *node = m_head->m_next;
    value_out = m_head->m_value;
    delete m_head;
    m_head = node;
    result = true;
    m_count--;
    if (m_head == NULL) {
        m_tail = NULL;
    }
  }
  return result;
}

int main() {
  int value = -1;
  Queue queueObj;
  queueObj.enqueue(100);
  queueObj.enqueue(200);
  queueObj.enqueue(300);
  queueObj.dequeue(value);
  queueObj.enqueue(400);
  queueObj.enqueue(500);
  queueObj.enqueue(600);
  while(queueObj.dequeue(value)) {
    cout << value << endl;
  }
  queueObj.enqueue(600);
  queueObj.enqueue(500);
  queueObj.enqueue(400);
  queueObj.enqueue(300);
  queueObj.enqueue(200);
  queueObj.enqueue(100);
  while(queueObj.dequeue(value)) {
    cout << value << endl;
  }
  return 0;
}
