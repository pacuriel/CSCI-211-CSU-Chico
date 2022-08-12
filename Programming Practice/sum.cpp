int sum_r(int *a1, unsigned int size) {
  // If size is 0, return 0
  // otherwise, if size is 1, return the first element of array a1
  // otherwise, return the sum of the first element of the array a1 added to the sum of the remaining elements in the array a1.
    if (size == 0) {
        return 0;
    }
    else {
        return (size == 1 ? a1[0] : a1[0] += sum_r(a1 + 1, size - 1));
    }
}
