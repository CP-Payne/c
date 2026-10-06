#include <stdio.h>

int my_strcmp(const char *a, const char *b) {

  while (1) {
    if (*a == *b) {
      if (*a == '\0') {
        break;
      }
      a++;
      b++;
    } else if (*a < *b) {
      return -1;
    } else {
      return 1;
    }
  }

  return 0;
}

int main() {

  char *a = "Hello";
  char *b = "hello";

  printf("%d", my_strcmp(a, b));

  return 0;
}
