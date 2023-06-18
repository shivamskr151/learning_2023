#include <stdio.h>

int convert_string_to_integer(const char* string) {
  int integer = 0;
  for (int i = 0; string[i] != '\0'; i++) {
    int value = string[i] - '0';
    integer = integer * 10 + value;
  }
  return integer;
}

int main() {
  const char* string = "5278";
  int integer = convert_string_to_integer(string);
  printf("Input String: %s\n", string);
  printf("Output Integer: %d\n", integer);

  return 0;
}