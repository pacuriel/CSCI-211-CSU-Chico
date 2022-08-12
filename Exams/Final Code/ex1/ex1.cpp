#include "ex1.h"
#include <iostream>
using namespace std;

// Allocates and returns an array containing all integer values
// on this list. Allocate the array via malloc.
// If the list is empty, return NULL.
// DO NOT DEALLOCATE THE ARRAY.
int* List::getValues() {
  // IMPLEMENT THIS METHOD


  if (m_head != NULL) {
      int *array = (int*) malloc(getCount() * sizeof(int));

      Node *ptr = m_head; // Pointer to m_head

      // for loop to set allocate elements in array
      for (int i = 0; (i < getCount() && ptr != NULL); i++) {
          array[i] = ptr->m_value; // Setting array element to list value

          ptr = ptr->m_next;
      }

      delete ptr; // Deleting temporary pointer

      return array; // Returning arrays
  }

}
