#include <stdio.h>

// assume dest has enough memory allocated
char *my_strcpy(char *dest, const char *src) {

  char *start_dest = dest;

  while (1) {
    *dest = *src;

    if (*src == '\0') {
      break;
    }

    src++;
    dest++;
  }
  return start_dest;
}

int main() {
  char dest[50];

  my_strcpy(dest, "Hello");
  printf("%s\n", dest);
  return 0;
}
