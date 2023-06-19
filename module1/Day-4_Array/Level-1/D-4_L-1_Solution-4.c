#include <stdio.h>

int sum_of_even_elements(int *array, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    if (array[i] % 2 == 0) {
      sum += array[i];
    }
  }
  return sum;
}

int sum_of_odd_elements(int *array, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    if (array[i] % 2 != 0) {
      sum += array[i];
    }
  }
  return sum;
}

int main() {
  int array[] = {64, 84, 21, 36, 17, 90, 77, 10, 48, 55};
  int size = sizeof(array) / sizeof(int);
  int sum_of_even = sum_of_even_elements(array, size);
  int sum_of_odd = sum_of_odd_elements(array, size);
  int difference = sum_of_even - sum_of_odd;
  
  printf("Sum of even elements: %d\n", sum_of_even);
  printf("Sum of odd elements: %d\n", sum_of_odd);
  printf("Difference between even and odd elements: %d\n", difference);
  
  return 0;
}