#include "list.h"
#include <iostream>
using namespace std;

// DO NOT MODIFY THIS FILE

int main() {
    List list;
    int value;
    while (cin >> value) {
        list.insertSorted(value);
    }
    list.print();
    return 0;
}
