#include <stdio.h>

// Function to convert decimal to binary
void decimal_to_binary(int num) {
  if (num > 0) {
    decimal_to_binary(num / 2);
    printf("%d", num % 2);
  }
}

// Function to convert decimal to octal
void decimal_to_octal(int num) {
  if (num > 0) {
    decimal_to_octal(num / 8);
    printf("%d", num % 8);
  }
}

// Function to convert decimal to hexadecimal
void decimal_to_hexadecimal(int num) {
  if (num > 0) {
    decimal_to_hexadecimal(num / 16);
    int remainder = num % 16;
    if (remainder < 10) {
      printf("%d", remainder);
    } else {
      printf("%c", 'A' + remainder - 10);
    }
  }
}

int main() {
  int num = 29;

  printf("Decimal: %d\n", num);

  printf("Binary: ");
  decimal_to_binary(num);
  printf("\n");

  printf("Octal: ");
  decimal_to_octal(num);
  printf("\n");

  printf("Hexadecimal: ");
  decimal_to_hexadecimal(num);
  printf("\n");

  return 0;
}