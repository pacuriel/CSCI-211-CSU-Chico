/*
 class SortedList {
public:
  SortedList() {m_head = NULL;}
  ~SortedList() {};
  bool isEmpty();
  int getSize();
  void insert(int value);
  bool remove(int value);
  bool removeAll();
  void print();
private:
  class Node {
  public:
    Node(int value, Node *next) {m_value = value; m_next = next;}
    int m_value;
    Node *m_next;
  };
   int m_size;
  Node *m_head;
};
 */

bool SortedList::removeAll() {
    Node *node_ptr = m_head;
    while (node_ptr != NULL) {

        delete node_ptr->m_head;

        node_ptr = node_ptr->m_next;
    }
}
