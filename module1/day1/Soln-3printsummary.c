#include <stdio.h>

int main() {
  
  int roll_no;
  char name[100];
  int physics, math, chemistry;
  float total, percentage;

 
  printf("Enter the roll number: ");
  scanf("%d", &roll_no);

 
  printf("Enter the full name of the student: ");
  scanf("%s", name);

  
  printf("Enter the marks of physics: ");
  scanf("%d", &physics);

  printf("Enter the marks of math: ");
  scanf("%d", &math);

  printf("Enter the marks of chemistry: ");
  scanf("%d", &chemistry);

  
  total = physics + math + chemistry;

  
  percentage = (total / 300.0) * 100.0;

  
  printf("\n");
  printf("Roll No: %d\n", roll_no);
  printf("Name: %s\n", name);
  printf("Physics: %d\n", physics);
  printf("Math: %d\n", math);
  printf("Chemistry: %d\n", chemistry);
  printf("Total: %f\n", total);
  printf("Percentage: %.2f%%\n", percentage);

  return 0;
}
