#include <stdio.h>

void reverse_array(int *array, int size) {
  int i = 0;
  int j = size - 1;
  while (i < j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    i++;
    j--;
  }
}

int main() {
  int array[] = {64, 84, 20, 36, 12, 90, 72, 10, 45, 56};
  int size = sizeof(array) / sizeof(int);
  printf("Original Array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  reverse_array(array, size);

  printf("Reversed Array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}