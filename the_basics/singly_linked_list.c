#include <stdio.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

// C passess everyting by value, giving *head gives a copy of the reference
// meaning that if you change it to point to something else, it stays local.
// Therefore, using **, you give a pointer to a pointer, allowing you to change
// the second pointer and have the calling function have the updated value.
void list_push_front(Node **head, int value) {};

void list_push_back(Node **head, int value) {};

Node *list_search(Node *head, int value) {};
void list_delete(Node **head, int value) {};
void list_print(Node *head) {};
void list_free(Node **head) {};
