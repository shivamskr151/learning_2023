#include <stdio.h>
#include <stdlib.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeStudents(struct Student *students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Enter the data for student %d: ", i + 1);
        scanf("%d %s %f", &students[i].rollno, students[i].name, &students[i].marks);
    }
}

void displayStudents(struct Student *students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d: Roll No: %d, Name: %s, Marks: %.2f\n",
               i + 1, students[i].rollno, students[i].name, students[i].marks);
    }
}

int main() {
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    struct Student *students = malloc(numStudents * sizeof(struct Student));

    initializeStudents(students, numStudents);

    displayStudents(students, numStudents);

    free(students);

    return 0;
}