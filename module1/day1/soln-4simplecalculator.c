#include <stdio.h>

int main() {
  
  int operand1, operand2;
  char operator;

  
  printf("Enter the first number: ");
  scanf("%d", &operand1);

  
  printf("Enter the operator: ");
  scanf(" %c", &operator);

 
  printf("Enter the second number: ");
  scanf("%d", &operand2);

  
  switch (operator) {
    case '+':
      printf("%d + %d = %d\n", operand1, operand2, operand1 + operand2);
      break;
    case '-':
      printf("%d - %d = %d\n", operand1, operand2, operand1 - operand2);
      break;
    case '*':
      printf("%d * %d = %d\n", operand1, operand2, operand1 * operand2);
      break;
    case '/':
      printf("%d / %d = %d\n", operand1, operand2, operand1 / operand2);
      break;
    default:
      printf("Invalid operator\n");
  }

  return 0;
}
