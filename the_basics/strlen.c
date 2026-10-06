#include <stdio.h>

// Note: the char array can be read with pointers by walking pointer forward or
// by indexing i.e. a++ or a[0]
// Note: in declaration *a means this is a reference
// in expression, it dereferrences it
size_t my_strlen(const char *a) {
  // Note: the value at *a is constant, not the array itself, which is why we
  // can walk it. to make the pointer immutable and not the value:
  // char * const a
  // Or both immutable: const char * const a
  size_t counter = 0;
  while (*a != '\0') {
    counter++;
    a++;
  }
  return counter;
}

int main() {
  printf("%zu\n", my_strlen("Hello"));
  printf("%zu\n", my_strlen(""));
  printf("%zu\n", my_strlen("A longer test of a string"));
  return 0;
}
