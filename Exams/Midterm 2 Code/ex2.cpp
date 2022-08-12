#include <iostream>
#include "ex2.h"
using namespace std;

// Writes each integer value in the given array to
// stdout, on a new line, in order, from the first
// element to the last element in the array.
// Does nothing if the array is NULL or if size is 0.
// Must be recursive to receive credit.
void print_array_r(const int *a1, unsigned int size) {
  // IMPLEMENT!
  if (size == 1) {
      cout << a1[0] << endl;
  }
  else if (size >= 1) {
      cout << a1[0] << endl;
      print_array_r(a1 + 1, size - 1);
  }
}
