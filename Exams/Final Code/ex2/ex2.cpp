#include "stddef.h"
using namespace std;

// Return the sum of each array element multiplied by the given factor.
// Return 0 if the array is NULL or values_count is 0.
// This function must be implemented recursively to receive credit.
int sum_of_products_r(int *values, unsigned int values_count, int factor) {
  // IMPLEMENT THIS METHOD
  int sum = 0;

  if (values == NULL || values_count <= 0) {
      sum = 0;
  }
  else {
      sum = (values[0]*factor) + sum_of_products_r(values + 1, values_count - 1, factor);
  }
  return sum; // Returning sum

}
