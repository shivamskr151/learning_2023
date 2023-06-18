int sum_of_even_indexed_elements(int *array, int size) {
  int sum = 0;
  for (int i = 0; i < size; i += 2) {
    sum += array[i];
  }
  return sum;
}

int sum_of_odd_indexed_elements(int *array, int size) {
  int sum = 0;
  for (int i = 1; i < size; i += 2) {
    sum += array[i];
  }
  return sum;
}

int main() {
  int array[] = {64, 84, 21, 36, 17, 90, 77, 10, 48, 55};
  int size = sizeof(array) / sizeof(int);
  int sum_of_even_indexed = sum_of_even_indexed_elements(array, size);
  int sum_of_odd_indexed = sum_of_odd_indexed_elements(array, size);
  int difference = sum_of_even_indexed - sum_of_odd_indexed;
  
  printf("Sum of even indexed elements: %d\n", sum_of_even_indexed);
  printf("Sum of odd indexed elements: %d\n", sum_of_odd_indexed);
  printf("Difference between even and odd indexed elements: %d\n", difference);
  
  return 0;
}