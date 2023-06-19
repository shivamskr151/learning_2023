#include <stdio.h>
int linear_search(int array[], int size, int key) {
  int i;
  for (i = 0; i < size; i++) {
    if (array[i] == key) {
      return 1; 
    }
  }
  return 0; 
}
int main() {
  int array[] = {30, 40, 10, 60, 50, 20, 70, 90, 80, 25};
  int size = sizeof(array) / sizeof(array[0]);
  int key = 25;
  int found = linear_search(array, size, key);
  if (found) {
    printf("Element found!\n");
  } else {
    printf("Element not found!\n");
  }
  return 0;
}