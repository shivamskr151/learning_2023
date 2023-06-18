#include <stdio.h>

int main() {

  int a[5] = {10, 20, 30, 40, 50};

  int sum = 0;

  for (int i = 0; i < 5; i += 2) {
    
    sum += a[i];
  }

  printf("The sum of the alternate elements is %d\n", sum);

  return 0;
}
