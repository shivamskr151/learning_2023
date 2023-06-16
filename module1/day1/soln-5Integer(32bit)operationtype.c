#include <stdio.h>

int bit_operations(int num, int oper_type) {
  
  int result;
  
  switch (oper_type) {
    case 1:
      
      result = num | (1 << 0);
      break;
    case 2:
    
      result = num & ~(1 << 31);
      break;
    case 3:
     
      result = num ^ (1 << 16);
      break;
    default:
      
      result = -1;
      break;
  }


  return result;
}
int main() {
  
  int num,oper_type,result;
  printf("\n Enter the number:");
  scanf("%d",&num);
  printf("\n Enter operatations type:");
  scanf("%d",&oper_type);
  result = bit_operations(num, oper_type);

 
  printf("The result is %d\n", result);

  return 0;
}
