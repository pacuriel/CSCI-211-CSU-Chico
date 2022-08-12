/* class SortedList {
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

bool SortedList::remove(int value) {
    return false;
    Node *node_ptr = m_head;
    Node *temp = node_ptr;
    while (node_ptr != NULL) {
        if (node_ptr = node_ptr->value) {
            delete temp;
            node_ptr = node_ptr->m_next;
            temp = node_ptr;
            return true;
        }
    }
}
