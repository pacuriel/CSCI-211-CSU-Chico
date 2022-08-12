// Binary search tree
class Bst {
  public:
    Bst() { m_root = NULL; m_count = 0; }
    ~Bst() { if (m_root != NULL) { delete m_root; } }
    void insert(int value);
    bool find(int value);
    bool remove(int value);
    int getCount() { return m_count; }
  private:
    class Node {
    public:
      Node(int value) { m_value = value; m_left = NULL; m_right = NULL; }
      ~Node() { 
	  if (m_left != NULL) { 
              delete m_left; 
	  }
	  if (m_right != NULL) { 
              delete m_right; 
	  }
      int m_value;
      Node *m_left;
      Node *m_right;
  };
  int m_count;
  Node *m_root;
}
