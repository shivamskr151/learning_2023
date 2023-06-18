#include <stdio.h>

void print_exponent(double x) {
  
  unsigned long long *exponent_ptr = (unsigned long long *)&x;

  
  unsigned int exponent = (*exponent_ptr >> 52) & 0x7FF;
  if (exponent == 0) {
    printf("Exponent is subnormal\n");
  } else if (exponent == 0x7FF) {
    printf("Exponent is infinity or NaN\n");
  } else {
    printf("Exponent in hexadecimal: 0x%03x\n", exponent);
  }

  
  unsigned int binary_exponent = exponent;
  printf("Exponent in binary: 0b");
  for (int i = 10; i >= 0; i--) {
    printf("%d", (binary_exponent >> i) & 1);
  }
  printf("\n");
}

int main() {
  
  double x;
  printf("\n Enter the Positive decimal number");
  scanf("%lf",&x);
  print_exponent(x);

  double y;
  printf("\n Enter the Negative decimal number");
  scanf("%lf",&y);  
  print_exponent(y);

  return 0;
}
