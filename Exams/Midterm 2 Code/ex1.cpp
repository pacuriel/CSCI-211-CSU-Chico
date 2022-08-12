#include <cstddef>
#include "ex1.h"

// Returns the number of characters in the given C string.
// Returns 0 if str is NULL or empty.
// Hint: The recursive length of a string is
// 1 (the length of the first character of the string), plus
// the length of the sub-string starting with
// the next character of the string.
// Must be recursive to receive credit!
unsigned int str_len_r(const char* str){
  // IMPLEMENT!
  if (str == NULL || str[0] == '\0') {
      return 0;
  }
  else {
      return (1 + str_len_r(str + 1));
  }
}
