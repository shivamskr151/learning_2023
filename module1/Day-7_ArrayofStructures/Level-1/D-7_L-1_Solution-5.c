#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void searchStudentByName(struct Student *students, int numStudents, const char *name) {
    int i, found = 0;
    
    for (i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Student found:\n");
            printf("Roll No: %d, Name: %s, Marks: %.2f\n",
                   students[i].rollno, students[i].name, students[i].marks);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Student not found.\n");
    }
}

int main() {
    int numStudents, i;
    
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    
    struct Student *students = malloc(numStudents * sizeof(struct Student));
    
    for (i = 0; i < numStudents; i++) {
        printf("Enter the data for student %d: ", i + 1);
        scanf("%d %s %f", &students[i].rollno, students[i].name, &students[i].marks);
    }
    
    printf("\nDisplaying student details:\n");
    for (i = 0; i < numStudents; i++) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n",
               students[i].rollno, students[i].name, students[i].marks);
    }
    
    char searchName[20];
    printf("\nEnter the name of the student to search: ");
    scanf("%s", searchName);
    
    searchStudentByName(students, numStudents, searchName);
    
    free(students);
    
    return 0;
}