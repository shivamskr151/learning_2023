#include <stdio.h>

int binary_to_decimal(char *binary_number) {
  int decimal_number = 0;
  int i = 0;
  while (binary_number[i] != '\0') {
    int digit = binary_number[i++] - '0';
    decimal_number = decimal_number * 2 + digit;
  }
  return decimal_number;
}

int octal_to_decimal(char *octal_number) {
  int decimal_number = 0;
  int i = 0;
  while (octal_number[i] != '\0') {
    int digit = octal_number[i++] - '0';
    decimal_number = decimal_number * 8 + digit;
  }
  return decimal_number;
}

int hexadecimal_to_decimal(char *hexadecimal_number) {
  int decimal_number = 0;
  int i = 0;
  while (hexadecimal_number[i] != '\0') {
    int digit = hexadecimal_number[i++];
    if (digit >= '0' && digit <= '9') {
      digit = digit - '0';
    } else {
      digit = digit - 'A' + 10;
    }
    decimal_number = decimal_number * 16 + digit;
  }
  return decimal_number;
}

int main() {
  char binary_number[] = "11101";
  int decimal_number = binary_to_decimal(binary_number);
  printf("Binary number: %s\nDecimal number: %d\n", binary_number, decimal_number);

  char octal_number[] = "1532";
  decimal_number = octal_to_decimal(octal_number);
  printf("Octal number: %s\nDecimal number: %d\n", octal_number, decimal_number);

  char hexadecimal_number[] = "35A";
  decimal_number = hexadecimal_to_decimal(hexadecimal_number);
  printf("Hexadecimal number: %s\nDecimal number: %d\n", hexadecimal_number, decimal_number);
  return 0;
}