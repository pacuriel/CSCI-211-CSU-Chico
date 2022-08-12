// DO NOT MODIFY THIS FILE!
#include <iostream>
#include <string>
using namespace std;
#include "ex4.h"

int main() {
  Bst bst;
  string token;
  // Process commands from stdin
  while (cin >> token) {
      if (token == "insert") {
        string insert_value;
        cin >> insert_value;
        bst.insert(insert_value);
      } else if (token == "remove") {
        string remove_value;
        cin >> remove_value;
        bst.remove(remove_value);
      } else if (token == "print") {
        bst.print();
      }
  }
  return 0;
}
