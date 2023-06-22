#include <stdio.h>
#include <stdlib.h>

struct student {
  int id;
  char name[20];
  float marks;
};

void delete_member(struct student **array, int *size) {
 
  if (*size == 0) {
    printf("Array is already empty. Nothing to delete.\n");
    return;
  }

  free(*array);

  for (int i = 1; i < *size; i++) {
    (*array)[i - 1] = (*array)[i];
  }

  *size = *size - 1;

  *array = realloc(*array, (*size) * sizeof(struct student));
}

int main() {
 
  struct student *array = NULL;
  int size = 0;

  struct student student1 = {1, "Sonu", 85.5};
  struct student student2 = {2, "Shivam", 90.0};
  struct student student3 = {3, "Sakshi", 75.25};

  array = realloc(array, (size + 1) * sizeof(struct student));
  array[size++] = student1;
  array = realloc(array, (size + 1) * sizeof(struct student));
  array[size++] = student2;
  array = realloc(array, (size + 1) * sizeof(struct student));
  array[size++] = student3;

  printf("Array of Structures (Before Deletion):\n");
  for (int i = 0; i < size; i++) {
    printf("Student %d: ID = %d, Name = %s, Marks = %.2f\n", i+1, array[i].id, array[i].name, array[i].marks);
  }

  delete_member(&array, &size);

  printf("\nArray of Structures (After Deletion):\n");
  for (int i = 0; i < size; i++) {
    printf("Student %d: ID = %d, Name = %s, Marks = %.2f\n", i+1, array[i].id, array[i].name, array[i].marks);
  }

  free(array);

  return 0;
}