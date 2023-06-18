#include <stdio.h>

int count_bits(int *array, int size) {
  int total_bits = 0;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < 32; j++) {
      if ((array[i] & (1 << j)) != 0) {
        total_bits++;
      }
    }
  }
  return total_bits;
}

int main() {
  int a[] = {0x1, 0xF4, 0x10001};
  int size = sizeof(a) / sizeof(a[0]);
  int total_bits = count_bits(a, size);
  printf("The total number of bits set is %d\n", total_bits);
  return 0;
}
