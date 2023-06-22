#include <stdio.h>
#include <stdlib.h>

struct student {
  int id;
  char name[20];
  float marks;
};

void add_member(struct student **array, int *size) {

  (*size)++;

  *array = realloc(*array, sizeof(struct student) * (*size));

  printf("Enter the student's ID: ");
  scanf("%d", &((*array)[*size - 1].id));
  printf("Enter the student's name: ");
  scanf("%s", (*array)[*size - 1].name);
  printf("Enter the student's marks: ");
  scanf("%f", &((*array)[*size - 1].marks));
}

void rotate_array(struct student **array, int size, int k) {
  
  if (size == 0 || k <= 0 || k >= size) {
    return;
  }

  struct student *temp_array = malloc(sizeof(struct student) * k);

  for (int i = 0; i < k; i++) {
    temp_array[i] = (*array)[i];
  }

  for (int i = k; i < size; i++) {
    (*array)[i - k] = (*array)[i];
  }

  for (int i = 0; i < k; i++) {
    (*array)[size - k + i] = temp_array[i];
  }

  free(temp_array);
}

int main() {
  
  struct student *array = NULL;
  int size = 0;

  add_member(&array, &size);
  add_member(&array, &size);
  add_member(&array, &size);

  printf("Array of Structures (Before Rotation):\n");
  for (int i = 0; i < size; i++) {
    printf("Student %d: ID = %d, Name = %s, Marks = %.2f\n", i + 1, array[i].id, array[i].name, array[i].marks);
  }

  int k;
  printf("Enter the rotation count: ");
  scanf("%d", &k);

  rotate_array(&array, size, k);

  printf("\nArray of Structures (After Rotation):\n");
  for (int i = 0; i < size; i++) {
    printf("Student %d: ID = %d, Name = %s, Marks = %.2f\n", i + 1, array[i].id, array[i].name, array[i].marks);
  }

  free(array);

  return 0;
}