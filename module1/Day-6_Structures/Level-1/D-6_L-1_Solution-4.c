#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int roll_number;
    float marks;
    int age;
};

int main() {
    int n;
    struct Student *students;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    
    students = (struct Student *)malloc(n * sizeof(struct Student));

   
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);

        printf("Enter name: ");
        scanf("%s", students[i].name);

        printf("Enter age: ");
        scanf("%d", &students[i].age);
        
        printf("Enter roll number: ");
        scanf("%d", &students[i].roll_number);

        printf("Enter marks: ");
        scanf("%f", &students[i].marks);

        
    }

    printf("\nStudent details:\n");
    for (int i = 0; i < n; i++) {
        printf("\nDetails for student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Roll number: %d\n", students[i].roll_number);
        printf("Marks: %.2f\n", students[i].marks);
        
    }

    free(students);

    return 0;
}