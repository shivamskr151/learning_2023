#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeStudents(struct Student *students, int numStudents) {
    int i;
    for (i = 0; i < numStudents; i++) {
        printf("Enter the data for student %d: ", i + 1);
        scanf("%d %s %f", &students[i].rollno, students[i].name, &students[i].marks);
    }
}

void displayStudents(struct Student *students, int numStudents) {
    int i;
    for (i = 0; i < numStudents; i++) {
        printf("Student %d: Roll No: %d, Name: %s, Marks: %.2f\n",
               i + 1, students[i].rollno, students[i].name, students[i].marks);
    }
}

void sortStudents(struct Student *students, int numStudents) {
    int i, j;
    struct Student temp;

    for (i = 0; i < numStudents - 1; i++) {
        for (j = 0; j < numStudents - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
               
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int numStudents;
    struct Student *students;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    students = (struct Student *)malloc(numStudents * sizeof(struct Student));

    initializeStudents(students, numStudents);

    printf("\nBefore sorting:\n");
    displayStudents(students, numStudents);

    sortStudents(students, numStudents);

    printf("\nAfter sorting:\n");
    displayStudents(students, numStudents);

    free(students);

    return 0;
}