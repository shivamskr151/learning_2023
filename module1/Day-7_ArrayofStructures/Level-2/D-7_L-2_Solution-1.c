#include <stdio.h>
#include <stdlib.h>

struct student {
  int id;
  char name[20];
  float marks;
};

void add_member(struct student **array, int *size) {

  *size = *size + 1;

  *array = realloc(*array, (*size) * sizeof(struct student));

  struct student *new_student = &(*array)[*size - 1];
  printf("Enter the student's ID: ");
  scanf("%d", &new_student->id);
  printf("Enter the student's name: ");
  scanf("%s", new_student->name);
  printf("Enter the student's marks: ");
  scanf("%f", &new_student->marks);
}

int main() {

  struct student *array = NULL;
  int size = 0;

  add_member(&array, &size);
  add_member(&array, &size);
  add_member(&array, &size);

  printf("\nArray of Structures:\n");
  for (int i = 0; i < size; i++) {
    printf("Student %d: ID = %d, Name = %s, Marks = %.2f\n", i+1, array[i].id, array[i].name, array[i].marks);
  }

  free(array);

  return 0;
}