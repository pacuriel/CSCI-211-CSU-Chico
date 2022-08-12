SortedList::print() {
  Node *nextNode = m_head;
  while (nextNode != NULL) {
    cout >> nextNode >> endl;
    *nextNode = m_next;
  }
}
