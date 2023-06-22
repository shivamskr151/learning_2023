#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50

struct Student {
    char name[MAX_NAME_LENGTH];
    float marks;
};

void readStudents(struct Student* students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter the marks of student %d: ", i + 1);
        scanf("%f", &students[i].marks);
    }
}

void writeStudents(struct Student* students, int numStudents) {
    printf("Student details:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Name: %s, Marks: %.2f\n", students[i].name, students[i].marks);
    }
}

float calculateAverage(struct Student* students, int numStudents) {
    float totalMarks = 0.0;
    for (int i = 0; i < numStudents; i++) {
        totalMarks += students[i].marks;
    }
    return totalMarks / numStudents;
}

void printAboveAverage(struct Student* students, int numStudents, float average) {
    printf("Students scoring above average:\n");
    for (int i = 0; i < numStudents; i++) {
        if (students[i].marks > average) {
            printf("Name: %s, Marks: %.2f\n", students[i].name, students[i].marks);
        }
    }
}

void printBelowAverage(struct Student* students, int numStudents, float average) {
    printf("Students scoring below average:\n");
    for (int i = 0; i < numStudents; i++) {
        if (students[i].marks < average) {
            printf("Name: %s, Marks: %.2f\n", students[i].name, students[i].marks);
        }
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

   
    struct Student* students = malloc(numStudents * sizeof(struct Student));

    readStudents(students, numStudents);


    writeStudents(students, numStudents);

    float average = calculateAverage(students, numStudents);
    printf("Average marks: %.2f\n", average);

    printAboveAverage(students, numStudents, average);

    printBelowAverage(students, numStudents, average);

    free(students);

    return 0;
}