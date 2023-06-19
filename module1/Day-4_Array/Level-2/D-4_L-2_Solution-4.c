#include <stdio.h>

void bubble_sort(int array[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

void print_array(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() {
  int array[] = {30, 40, 10, 60, 50, 20};
  int size = sizeof(array) / sizeof(array[0]);

  printf("Array before sorting: ");
  print_array(array, size);

  bubble_sort(array, size);

  printf("Array after sorting using Bubble Sort: ");
  print_array(array, size);

  return 0;
}