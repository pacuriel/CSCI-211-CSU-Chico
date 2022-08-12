#include <iostream>
using namespace std;
#include "ex4.h"

// IMPLEMENT THESE TWO METHODS

// Sets max_node_out to point to the node with the maximum value in the
// given sub-tree.
void Bst::getMaxValueNode(Node *root, Node *&max_node_out) {
    Node *temp = root;

    while (temp->m_right != NULL) {
        max_node_out = temp->m_right;
        temp = temp->m_right;
    }

    delete temp;
}

// Removes the node with the given value, if any.
// Returns true if a node was removed.
// Warning: Carefully consider the Node destructor behavior when
// deleting nodes.
bool Bst::remove(string value, Node *&root) {
  bool result = false;
  // If subtree not empty
  //   If value less than root's value, recursively remove from left sub-tree
  //   else if value greater than root's value, recursively remove from right sub-tree
  //   else (value must be equal to root's value)
  //     if right subtree is empty, delete root, promote left sub-tree to take its place
  //     else if left subtree is empty, delete root, promote right sub-tree to take its place
  //     else
  //        Swap root's value with max value on left sub-tree (using getMaxValueNode method).
  //        Remove value from left sub-tree
  if (root != NULL) {
      if (value < root->m_value) { // Value less than root value
          // Remove from left subtree
          remove(value, root->m_left);
      }
      else if(value > root->m_value) { // Value gretaer than root value
          // Remove from right subtree
          remove(value, root->m_right);
      }
      else { // Values are equal
          if (root->m_right == NULL) {
              Node *temp = root; // Temp pointer to root
              root = root->m_left; // Setting root to left subtree
              delete temp;
              result = true;
          }
          else if (root->m_left == NULL) {
              Node *temp = root; // Temp pointer to root
              root = root->m_right; // Setting root to right subtree
              delete temp;
              result = true;
          }
          else { // Neither subtree is empty
              Node *max_node_on_left = root;

              // Calling get max function on left subtree
              getMaxValueNode(root->m_left, max_node_on_left);

              swap(root, max_node_on_left); // Swapping nodes

              remove(value, root->m_left); // Removing value from left subtree

              result = true;
          }
      }
  }

  return result;
}
