#include <stdio.h>

// Copies byte for byte where size_t n is the size in bytes
void *my_memcpy(void *dest, const void *src, size_t n) {

  // Tell the compiler to read 1 byte when looping over it.
  // If you were to print it, then it will only print the first byte
  // This is because we cast it to char
  char *d = dest;
  const char *s = src;

  for (size_t i = 0; i < n; i++) {
    d[i] = s[i];
  }

  return dest;
}

int main() {
  char *str = "Hello";
  // char *dst; --> would point to a random address that might be garbage
  // char dst[10]; initializes it on the stack with empty 10 spaces
  // char *dst = mallow[10] --> creates it on the HEAP --> requires free(dst)
  // after use
  char dst[10];

  // N: 6 include null terminator
  my_memcpy(dst, str, 6);

  printf("%s", dst);
  return 0;
}
