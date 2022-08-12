// vlist.h
// Curiel, Pablo
// pacuriel
#ifndef VLIST_H
#define VLIST_H
#include <iostream>
#include "video.h"
using namespace std;

// Vlist class
class Vlist {
public:
    Vlist() { m_head = NULL; m_size = 0; }
    ~Vlist() { removeAll(); } // Class destructor
    bool insert(Video *video, string title); // Inserts video objects alphabetically
    bool isEmpty() { return (m_head == NULL); }
    void callingVideoPrint();
    void removeAll();
    int length() { return m_size; }
    bool lookup(string lookupTitle);
    bool remove(string removeTitle);

private:
    // Creating Node class for linked list
    class Node {
    public:
        Node(Video *video, Node *next) { m_video = video; m_next = next; }
        Video *m_video;
        Node *m_next;
    };
    Node *m_head;
    int m_size;
};
#endif
