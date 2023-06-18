#include <stdio.h>
#include <ctype.h>

void toggle_case(char* string) {
  for (int i = 0; string[i] != '\0'; i++) {
    if (isupper(string[i])) {
      string[i] = tolower(string[i]);
    } else if (islower(string[i])) {
      string[i] = toupper(string[i]);
    }
  }
}

int main() {
  char string[] = "Hello World";
  toggle_case(string);
  printf("Output 1: %s\n", string);

  char string2[] = "Hello World";
  toggle_case(string2);
  printf("Output 2: %s\n", string2);

  char string3[] = "a+B";
  toggle_case(string3);
  printf("Output 3: %s\n", string3);

  char string4[] = "A+B";
  toggle_case(string4);
  printf("Output 4: %s\n", string4);

  char string5[] = "Shivam";
  toggle_case(string5);
  printf("Output 5: %s\n", string5);

  return 0;
}