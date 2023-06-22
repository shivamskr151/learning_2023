#include <stdio.h>
#include <stdlib.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeStudents(struct Student *students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        students[i].rollno = 0;
        students[i].name[0] = '\0';
        students[i].marks = 0.0;
    }
}

void printStudents(struct Student *students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d: Roll No: %d, Name: %s, Marks: %.2f\n",
               i + 1, students[i].rollno, students[i].name, students[i].marks);
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    getchar();

    struct Student *students = malloc(numStudents * sizeof(struct Student));

    initializeStudents(students, numStudents);
    printStudents(students, numStudents);

    free(students);

    return 0;
}