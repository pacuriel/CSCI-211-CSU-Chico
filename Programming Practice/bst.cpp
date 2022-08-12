int Bst::getHeight(Node *root) {
  // If the given sub-tree is empty, return 0.
  if (root->isEmpty()) {
      return 0;
  }
  // else return 1 + the max height of the left and right subtrees.
  else {
      return (1 + max(getHeight(root->m_left), getHeight(root->m_right)));
  }
}

bool Bst::isBalanced(Node *root) {
  // if given subtree is empty, return true (an empty subtree is considered balanced).
  if (root->isEmpty()) {
      return true;
  }
  // else return true if the height difference between the left and right subtrees is <=1 AND
  else if (abs(getHeight(root->m_left) - getHeight(root->m_right)) <= 1) {
      // both the right and left subtrees are balanced.
      if (isBalanced(root->m_left) && isBalanced(root->m_right)) {
          return true;
      }
  }
  else {
      return false;
  }
}
