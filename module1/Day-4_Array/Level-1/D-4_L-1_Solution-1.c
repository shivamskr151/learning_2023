#include <stdio.h>

void sum_and_average(int *array, int size, int *sum, float *average) {
  *sum = 0;
  for (int i = 0; i < size; i++) {
    *sum += array[i];
  }
  *average = (float)*sum / size;
}

int main() {
  int array[] = {12, 84, 20, 36, 64, 56, 72, 10, 45, 90};
  int sum;
  float average;
  
  sum_and_average(array, sizeof(array) / sizeof(int), &sum, &average);
  
  printf("Sum: %d\n", sum);
  printf("Average: %.2f\n", average);
  
  return 0;
}