#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[50];
    int age;
};

struct Person* modifyPerson(struct Person* person) {

    printf("Enter the new name: ");
    scanf("%s", person->name);
    
    printf("Enter the new age: ");
    scanf("%d", &person->age);

    return person;
}

int main() {
    struct Person p;

    struct Person* modifiedPerson = modifyPerson(&p);

    printf("\nModified Person:\n");
    printf("Name: %s\n", modifiedPerson->name);
    printf("Age: %d\n", modifiedPerson->age);

    return 0;
}