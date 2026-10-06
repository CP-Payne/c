#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *data;
  size_t size;
  size_t capacity;
} IntArray;

IntArray arr_init(void) {
  IntArray ia;
  ia.capacity = 4;
  ia.size = 0;
  ia.data = malloc(ia.capacity * sizeof(int));
  // if it fails, such as system out of memory, then first push (arr_push) will
  // segfault
  if (ia.data == NULL) {
    fprintf(stderr, "arr_init: malloc failed\n");
    exit(1);
  }
  return ia;
}

void arr_push(IntArray *arr, int value) {
  // Option 1
  // (*arr).data[(*arr).size] = value;
  // Note this derefferences then gets the value, without brackets, compiler
  // read as:
  // *(arr.data)
  // Tries the get the data first then dereference

  // Option 2
  // IntArray tmp = *arr;
  // tmp.data[tmp.size] = value;
  // Option 3
  /* arr->data[arr->size] = value; */
  /* (*arr).size++; */

  if (arr->size >= arr->capacity) {
    arr->capacity = arr->capacity * 2;

    // if realloc and save to same variable and fails (NULL)
    // then you basically overwritten the only pointer to your data
    int *new_data = realloc(arr->data, arr->capacity * sizeof(int));
    if (new_data == NULL) {
      fprintf(stderr, "arr_push: realloc failed\n");
      exit(1);
    }
    arr->data = new_data;
  }

  arr->data[arr->size] = value;

  (*arr).size++;
}

void arr_free(IntArray *arr) { free(arr->data); }
void arr_print(IntArray *arr) {
  printf("[");
  for (size_t x = 0; x < arr->size; x++) {
    if (x == arr->size - 1) {

      printf("%d%s\n", arr->data[x], "]");
      //   alternative
      // printf("%d%s", *(arr->data + (x * sizeof(int))), "]\n");
      // The above will not work because the pointer size scales automatically
      // so it should be:
      // *(arr->data + x)
      // a[i] is shorthand for *(a + i)
      break;
    }
    printf("%d%s", arr->data[x], ",");
  }
}

int main() {
  IntArray arr = arr_init();
  arr_push(&arr, 1);
  arr_push(&arr, 2);
  arr_push(&arr, 3);
  arr_push(&arr, 4);
  arr_push(&arr, 5);
  arr_push(&arr, 6);
  arr_print(&arr);
  arr_free(&arr);

  return 0;
}
