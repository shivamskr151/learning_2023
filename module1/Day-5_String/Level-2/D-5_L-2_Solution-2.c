#include <stdio.h>
#include <string.h>

void rotateString(char *str, int number_of_characters, char *direction) {
    int len = strlen(str);
    number_of_characters = number_of_characters % len; 
    
    if (strcmp(direction, "left") == 0) {
        char temp[number_of_characters + 1];
        strncpy(temp, str, number_of_characters);
        temp[number_of_characters] = '\0';
        memmove(str, str + number_of_characters, len - number_of_characters + 1);
        strcat(str, temp);
    } 
    else if (strcmp(direction, "right") == 0) {
        char temp[number_of_characters + 1];
        strncpy(temp, str + len - number_of_characters, number_of_characters);
        temp[number_of_characters] = '\0';
        memmove(str + number_of_characters, str, len - number_of_characters + 1);
        strncpy(str, temp, number_of_characters);
    }
}

int main() {
    char str[] = "abcdxyz";
    int number_of_characters = 2;
    char direction[] = "left";

    printf("Original string: %s\n", str);

    rotateString(str, number_of_characters, direction);
    printf("Rotated string: %s\n", str);

    return 0;
}