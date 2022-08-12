#include "ex1.h"
#include <iostream>
#include "memory.h"
using namespace std;

// DO NOT MODIFY THIS FILE
int main() {
  List list;
  int value;
  while (cin >> value) {
    list.insertAtFront(value);
  }
  int *my_array = list.getValues();
  if (my_array != NULL) {
    for (int i=0; i < list.getCount(); i++)
      cout << my_array[i] << " ";
    cout << endl;
    free(my_array);
  }
  return 0;
}
