#include <iostream>
#include "ex4.h"
#include "array.h"
using namespace std;

// Modify this function such that the provided
// deallocate_array function is called, regardless of whether an exception is
// thrown by print_array() or not, and that the exception will be thrown back
// to the catch block in the main function in main.cpp.
void print_and_deallocate_array(int *array, unsigned int size) {
  print_array(array, size);
  deallocate_array(array);
}
