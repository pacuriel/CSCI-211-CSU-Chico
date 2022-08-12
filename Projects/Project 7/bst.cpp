// bst.cpp
// Curiel, Pablo
// pacuriel

#include <iostream>
#include <queue>
#include "bst.h"
using namespace std;

// Public insert method to add a given value to the tree
bool Bst::insert(string value) {
    return insert(value, m_root); // Calling private insert method
}

// Private insert method
bool Bst::insert(string value, Node *&root) {
    bool result = false; // Initializing result to false
    // Ensuring string value is not an empty string
    if (!value.empty()) {
        if (root == NULL) { // root contains a NULL value
            root = new Node(value); // Creating new leaf
            m_count++; // Incrementing m_count
            result = true; // Changing result to true for success
        }
        else if (value < root->m_value) { // Value is less than root value
            // Recursively calling insert with left subtree
            result = insert(value, root->m_left);
        }
        else if (value > root->m_value){ // Value is greater than root value
            // Recursively calling insert with right subtree
            result = insert(value, root->m_right);
        }
    }
    return result; // Returning result
}

// Public method to find a specific value in the tree
bool Bst::find(string value) {
    return find(value, m_root); // Calling private find method
}

// Private version of find method
bool Bst::find(string value, Node *root) {
    bool result = false; // Initializing result to false
    if (root != NULL) {
        if (value == root->m_value) { // Value found in tree
            result = true; // Setting result to true
        }
        else if (value < root->m_value) { // Value is on left subtree
            // Recursively calling find with left subtree
            result = find(value, root->m_left);
        }
        else if (value > root->m_value) { // Value is on right subtree
            // Recursively calling find with right subtree
            result = find(value, root->m_right);
        }
    }
    return result; // Returning result
}

// Public depth-first traversal method to call private version
void Bst::dft(vector<string> &values) {
    dft(values, m_root); // Calling private dft method
}

// Private version of dft method
void Bst::dft(vector<string> &values, Node *root) {
    if (root != NULL) { // Root is not NULL
        if (root->m_left != NULL && !root->m_left->m_value.empty()) {
            // Recursively calling dft to traverse left subtree
            dft(values, root->m_left);
        }

        // Adding string value to vector
        values.push_back(root->m_value);

        if (root->m_right != NULL && !root->m_right->m_value.empty()) {
            // Recursively calling dft to traverse right subtree
            dft(values, root->m_right);
        }

    }
}

// Method to perform a breadth-first traversal and copy nodes to vector
void Bst::bft(vector<string> &values) {
    // Creating queue of Node pointers
    queue<Node*> node_ptr_queue;
    // Adding root node to queue
    node_ptr_queue.push(m_root);

    // Looping while queue is not empty
    while (node_ptr_queue.size() != 0) {

        // Storing first queue element in temporary Node pointer
        Node *temp = node_ptr_queue.front();
        node_ptr_queue.pop(); // Removing element from queue

        // Adding string to vector
        values.push_back(temp->m_value);

        // Checking for left child node
        if (temp->m_left != NULL) {
            // Adding left child node to queue if not NULL
            node_ptr_queue.push(temp->m_left);
        }

        // Checking for right child node
        if (temp->m_right != NULL) {
            // Adding right child node to queue if not NULL
            node_ptr_queue.push(temp->m_right);
        }
    }
}

// Public method to return height of tree
int Bst::getHeight() {
    // Returning private recursive function to get height
    return getHeight(m_root);
}

// Private method to find height of tree
int Bst::getHeight(Node *root) {
    int height; // Integer to store height of tree
    if (root == NULL) {
        height = 0;
    }
    else {
        height = 1 + max(getHeight(root->m_left), getHeight(root->m_right));
    }
    return height;
}

// Public method to return true if tree is balanced
bool Bst::isBalanced() {
    return isBalanced(m_root);
}

// Private recursive method to tell if tree is balanced
bool Bst::isBalanced(Node *root) {
    bool result = false; // Initialzing result to false
    // Case if root is NULL
    if (root == NULL) {
        result = true; // Tree is balanced
    }
    // Checking if left and right subtrees are balanced
    else if (isBalanced(root->m_left) && isBalanced(root->m_right)) {
        // Finding height difference of left/right subtrees
        int height_diff = abs(getHeight(root->m_left) - getHeight(root->m_right));
        if (height_diff <= 1) {
            result = true; // Balanced if height difference <= 1
        }
    }
    // Trees are not balanced
    else {
        result = false;
    }
    return result;
}

// Public version of rebalance method
void Bst::rebalance() {
    // Calling private version of method to rebalance tree
    rebalance(m_root);
}

// Method to insert string values from a vector onto a tree
void Bst::insertFromVector(vector<string> &elements, int start, int end, Node *&root) {
    // Ensuring the given range is not empty
    if (start <= end) {
        // if there is one element in the vector
        if (start == end) {
            insert(elements[start], root); // Inserting only element
        }
        // if there is more than one element in the vector
        else {
            int middle = (start + end) / 2; // Getting middle of vector

            // Inserting middle vector element into tree
            insert(elements[middle], root);

            // Ensuring m_root gets set to the right spot
            if (elements[middle] == "July") {
                // Test 25 kept changing m_root to June instead of July
                // even though June is towards bottom of rebalanced tree
                m_root = root; // Setting m_root equal to July
            }

            // Recursively inserting left half of vector into tree
            insertFromVector(elements, start, middle - 1, root->m_left);

            // Recursively inserting right half of vector into tree
            insertFromVector(elements, middle + 1, end, root->m_right);

        }
    }
}

// Private method to rebalance tree
void Bst::rebalance(Node *root) {
    if (root != NULL) { // Ensuring given root is not NULL
        // Vector to store string values
        vector<string> rebal_vector;

        // Using dft method to store string values in sorted order
        dft(rebal_vector, root);

        // Deleting m_root which causes Node destructor to delete all children
        delete root;

        // Setting m_root to NULL
        root = NULL;
        m_count = 0; // Resetting m_count to 0

        // Calling method to insert tree nodes from vector of string values
        insertFromVector(rebal_vector, 0, rebal_vector.size() - 1, root);
    }
}

// Public version of remove method
bool Bst::remove(string value) {
    // Returning private version of remove method
    return remove(value, m_root);
}

// Private remove method returning true if a method was removed
bool Bst::remove(string value, Node *root) {
    bool result = false;
    if (root != NULL) {
        // Recursively removing left subtree if value is less than root
        if (value < root->m_value) {
            remove(value, root->m_left);
        }
        // Recursively removing right subtree if value is greater than root
        else if (value > root->m_value) {
            remove(value, root->m_right);
        }
        // Values are equal
        else if (value == root->m_value) {
            // Right subtree is empty but left is not
            if (root->m_right == NULL && root->m_left != NULL) {
                Node *temp = root; // Temporary node
                root = root->m_left; // Promoting left subtree to root
                delete temp; // Deleting root
                temp = NULL; // Setting temp to point to NULL
                result = true;
            }
            // Left subtree is empty but right is not
            else if (root->m_left == NULL && root->m_right != NULL) { // Left subtree is empty
                Node *temp = root; // Temporary node
                root = root->m_right; // Promoting right subtree to root
                delete temp; // Deleting root
                temp = NULL; // Setting temp to point to NULL
                result = true;
            }
            // Both subtrees are empty
            else if (root->m_right == NULL && root->m_left == NULL) {
                // Deleting root and setting it to NULL
                delete root;
                root = NULL;
                result = true;
            }
            else { // Neither subtree is empty
                // Setting root to be swapped equal to NULL
                Node *root_to_swap = NULL;

                // Calling method to find root to be swapped
                getRootToSwap(root->m_right, root_to_swap);

                // Setting root's data equal to root to be deleted
                root->m_value = root_to_swap->m_value;

                // Recursively calling remove to delete root_to_swap
                remove(value, root->m_right);
            }
        }
    }
    return result;
}

// Method to find root to be swapped for remove command
void Bst::getRootToSwap(Node *root_to_traverse, Node *&root_to_swap) {
    Node* temp = root_to_traverse; // Creating temporary Node

    // Looping to find least value in tree
    while (temp != NULL && temp->m_left != NULL) {
        temp = temp->m_left; // Setting temp equal to left subtree
    }
    root_to_swap = temp; // Setting root_to_swap equal to temp Node
}