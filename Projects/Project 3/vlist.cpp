// vlist.cpp
// Curiel, Pablo
// pacuriel
#include "vlist.h"
#include <iostream>

// Inserts video entry into a list sorted by title
bool Vlist::insert(Video *video, string title) {
    Node *ptr = m_head;
    // Checking for matching title in list and returning false
    while (ptr != NULL) {
        if (ptr->m_video->equalTitle(title)) {
            return false;
        }
        ptr = ptr->m_next;
    }

    // Inserts node at front of list
    if (isEmpty() || m_head->m_video->greaterTitle(video)) {
        m_head = new Node(video, m_head);
        m_size++;
    }
    // Inserts video object after existing node
    else {
        Node *ptr = m_head;
        // while loop checking for which title is alphabetically greater
        while (ptr->m_next != NULL && video->greaterTitle(ptr->m_next->m_video)) {
            ptr = ptr->m_next;
        }
        // New node with video object
        ptr->m_next = new Node(video, ptr->m_next);
        m_size++;
    }
    return true;
}

// Calling Video's print() method
void Vlist::callingVideoPrint() {
    Node *ptr = m_head;
    while (ptr != NULL) {
        ptr->m_video->print(); // Calling Video::print()
        ptr = ptr->m_next;
    }
}

// Method to delete all Node and Video objects
void Vlist::removeAll() {
    if (!isEmpty()) {
        Node *ptr = m_head;
        while (ptr != NULL) {
            Node *tempToDelete = ptr; // Setting temporary pointer
            ptr = ptr->m_next;
            m_head = ptr;
            delete tempToDelete; // Deleting temporary pointer
        }
    }
}

// Method to lookup video by title and print its data
bool Vlist::lookup(string lookupTitle) {
    bool result = false; // Initializing result to false

    if (!isEmpty()) {
        Node *ptr = m_head;
        // Checking for matching title in list
        while (ptr != NULL) {
            if (ptr->m_video->equalTitle(lookupTitle)) {
                ptr->m_video->print();
                result = true; // result = true if matching title
                break;
            }
            ptr = ptr->m_next;
        }
    }
    return result;
}

// Method to lookup video by title and remove it from list
bool Vlist::remove(string removeTitle) {
    bool result = false;

    if (!isEmpty()) {
        // Checking for matching video title at head of list
        if (m_head->m_video->equalTitle(removeTitle)) {
            Node *tempToDelete = m_head;
            m_head = m_head->m_next;
            delete tempToDelete;
            m_size--; // Decreasing size of list by one
            result = true;
        }
        else {
            // Checking for matching video title after head of list
            Node *ptr = m_head;
            while (ptr->m_next != NULL && !(ptr->m_next->m_video->equalTitle(removeTitle))) {
                ptr = ptr->m_next;
            }

            if (ptr->m_next != NULL && ptr->m_next->m_video->equalTitle(removeTitle)) {
                Node *tempToDelete = ptr->m_next;
                ptr->m_next = tempToDelete->m_next;
                delete tempToDelete;
                m_size--;
                result = true;
            }
        }
    }
    return result;
}