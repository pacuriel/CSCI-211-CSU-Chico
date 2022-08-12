// DO NOT MODIFY THIS FILE
#include <iostream>
#include <sstream>
using namespace std;

#include "ex2.h"

void output_test_case(int *values_array, unsigned int values_count, int factor) {
  if (values_array == NULL) {
    cout << "NULL";
  } else if (values_count <= 0) {
    cout << "[]";
  } else {
    cout << "[";
    for (unsigned int values_idx = 0; values_idx < values_count; values_idx++) {
      cout << values_array[values_idx];
      if (values_idx < values_count-1)
        cout << ",";
    }
    cout << "]";
  }
}

void run_test(int *values_array, unsigned int values_count, int factor) {
  cout << "Sum of products for " << factor << "*";
  output_test_case(values_array, values_count, factor);
  cout << " is " << sum_of_products_r(values_array, values_count, factor) << endl;
}

int main() {
  // Read and execute remaining test cases from stdin
  string line;
  while (getline(cin, line)) {
    stringstream ss(line);
    unsigned int values_count;
    int factor;
    ss >> values_count;
    int *values_array = NULL;
    if (values_count > 0) {
      values_array = (int*) malloc(values_count * sizeof(int));
      for (unsigned int values_idx = 0; values_idx < values_count; values_idx++)
          ss >> values_array[values_idx];
    }
    ss >> factor;
    run_test(values_array, values_count, factor);
    free(values_array);
  }
  return 0;
}
