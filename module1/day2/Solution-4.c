#include <stdio.h>

int count_bits(int array[], int size) {
  int total_bits = 0;
  for (int i = 0; i < size; i++) {
    int num = array[i];
    int count = 0;
    while (num != 0) {
      if (num & 1) {
        count++;
      }
      num >>= 1;
    }
    total_bits += count;
  }
  return total_bits;
}

int main() {
  int a[] = {0x1, 0xF4, 0x10001};
  int size = sizeof(a) / sizeof(a[0]);

  int result = count_bits(a, size);
  printf("Total bits: %d\n", result);

  return 0;
}
