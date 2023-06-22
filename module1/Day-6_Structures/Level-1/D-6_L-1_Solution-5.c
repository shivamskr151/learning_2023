#include <stdio.h>
#include <string.h>

struct student {
    char name[50];
    int roll_number;
    float marks;
};

void swap_fields(struct student *s1, struct student *s2) {
    struct student temp;

    strcpy(temp.name, s1->name);
    strcpy(s1->name, s2->name);
    strcpy(s2->name, temp.name);

    int roll_number_temp = s1->roll_number;
    s1->roll_number = s2->roll_number;
    s2->roll_number = roll_number_temp;

    float marks_temp = s1->marks;
    s1->marks = s2->marks;
    s2->marks = marks_temp;
}

int main() {
    struct student s1, s2;

   
    printf("Enter the name of student 1: ");
    scanf("%s", s1.name);
    printf("Enter the roll number of student 1: ");
    scanf("%d", &s1.roll_number);
    printf("Enter the marks of student 1: ");
    scanf("%f", &s1.marks);

    
    printf("Enter the name of student 2: ");
    scanf("%s", s2.name);
    printf("Enter the roll number of student 2: ");
    scanf("%d", &s2.roll_number);
    printf("Enter the marks of student 2: ");
    scanf("%f", &s2.marks);


    printf("\nInitial data:\n");
    printf("Student 1: %s, %d, %.2f\n", s1.name, s1.roll_number, s1.marks);
    printf("Student 2: %s, %d, %.2f\n", s2.name, s2.roll_number, s2.marks);


    swap_fields(&s1, &s2);

    printf("\nAfter swapping:\n");
    printf("Student 1: %s, %d, %.2f\n", s1.name, s1.roll_number, s1.marks);
    printf("Student 2: %s, %d, %.2f\n", s2.name, s2.roll_number, s2.marks);

    return 0;
}