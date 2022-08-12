// DO NOT MODIFY THIS FILE!
using namespace std;

// Binary Search Tree
class Bst {
public:
  Bst() { m_root = NULL; m_size = 0; }
  ~Bst() { if (m_root != NULL) delete m_root; }
  void insert(string value) { insert(value, m_root); m_size++; }
  bool find(string value) { return find(value, m_root); }
  void print() { print(m_root); }
  bool remove(string value) { return remove(value, m_root); }
  int size() { return m_size; }

private:
  class Node {
  public:
    Node(string value) { m_value = value; m_left = NULL; m_right = NULL; }
    ~Node() { if (m_left != NULL) delete m_left; if (m_right != NULL) delete m_right; }
    string m_value;
    Node *m_left, *m_right;
  };

  void insert(string value, Node *&root) {
    if (root == NULL) {
      root = new Node(value);
    } else if (value < root->m_value) {
      insert(value, root->m_left);
    } else {
      insert(value, root->m_right);
    }
  }

  bool find(string value, Node *root) {
    bool result = false;
    if (root != NULL) {
      if (root->m_value == value) {
        result = true;
      } else if (value < root->m_value) {
        result = find(value, root->m_left);
      } else {
        result = find(value, root->m_right);
      }
    }
    return result;
  }

  void print(Node *root) {
    if (root != NULL) {
      print(root->m_left);
      cout << root->m_value << endl;
      print(root->m_right);
    }
  }

  // IMPLEMENT THESE TWO METHODS IN ex4.cpp
  void getMaxValueNode(Node *root, Node *&max_node_out);
  bool remove(string value, Node *&root);

  Node *m_root;
  int m_size;
};
