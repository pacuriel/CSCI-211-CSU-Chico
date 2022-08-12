// bst.h
// Curiel, Pablo
// pacuriel

#ifndef BST_H
#define BST_H

#include <string>
#include <vector>
using namespace std;

class Bst {
public:
  Bst() { m_root = NULL; m_count = 0; }
  ~Bst() { if (m_root != NULL) { delete m_root; } }

  // Insert value if it doesn't already exist.  Return true on success.
  bool insert(string value);

  // Return true if the given value exists in this Bst, otherwise false.
  bool find(string value);

  // Depth-first, in-order traversal, returning values via a vector.
  void dft(vector<string> &values);

  // Breadth-first traversal, returning values via a vector.
  void bft(vector<string> &values);

  // Returns true if this tree is balanced (complete), otherwise, false.
  bool isBalanced();

  // Returns the height of this Bst.  Returns 0 if empty.
  int getHeight();

  // Rebalance this Bst.
  void rebalance();

  // Returns the number of values currently stored in this Bst.
  int getCount() { return m_count; }

  // Removes a specific string value from tree
  bool remove(string value);

private:
  class Node {
  public:
    Node(string value) { m_value = value; m_left = NULL; m_right = NULL; };
    ~Node() {
        if (m_left != NULL) { delete m_left; }
        if (m_right != NULL) { delete m_right; }
    }
    string m_value;
    Node *m_left;
    Node *m_right;
  };
  // Private versions of public methods for recursive purposes
  bool insert(string value, Node *&root);
  bool find(string value, Node *root);
  void dft(vector<string> &values, Node *root);
  int getHeight(Node *root);
  bool isBalanced(Node *root);
  void rebalance(Node *root);
  void insertFromVector(vector<string> &elements, int start, int end, Node *&root);
  bool remove(string value, Node *root);
  void getRootToSwap(Node *root_to_traverse, Node *&root_to_swap);

  Node *m_root;
  int m_count;
};

#endif
