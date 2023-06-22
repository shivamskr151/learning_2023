#include <stdio.h>
#include <stdlib.h>

struct student {
  int id;
  char name[20];
  float marks;
};

void swap_members(struct student *array, int index1, int index2) {
  struct student temp = array[index1];
  array[index1] = array[index2];
  array[index2] = temp;
}

int main() {

  struct student array[5] = {
    {1, "Suman", 85.5},
    {2, "Sakshi", 90.0},
    {3, "Diwakar", 75.25},
    {4, "Shivam", 92.75},
    {5, "Koral", 78.5}
  };
  int size = 5;

  printf("Array of Structures (Before Swapping):\n");
  for (int i = 0; i < size; i++) {
    printf("Student %d: ID = %d, Name = %s, Marks = %.2f\n", i+1, array[i].id, array[i].name, array[i].marks);
  }

  int index1, index2;
  printf("\nEnter the indexes of the members to swap (0-%d): ", size - 1);
  scanf("%d %d", &index1, &index2);

  if (index1 >= 0 && index1 < size && index2 >= 0 && index2 < size) {
    
    swap_members(array, index1, index2);

    printf("\nArray of Structures (After Swapping):\n");
    for (int i = 0; i < size; i++) {
      printf("Student %d: ID = %d, Name = %s, Marks = %.2f\n", i+1, array[i].id, array[i].name, array[i].marks);
    }
  } 
  else 
  {
    printf("\nInvalid indexes. Swap operation aborted.\n");
  }

  return 0;
}