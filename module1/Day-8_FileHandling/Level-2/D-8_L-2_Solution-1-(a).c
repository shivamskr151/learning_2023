#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char* a, char* b) {
    char temp[256];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

int main() {
    const char* filename = "data.csv";
    const char* tempFilename = "temp.csv";

    // Open the input file
    FILE* inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        printf("Failed to open the input file.\n");
        return 1;
    }

    // Open the temporary file
    FILE* tempFile = fopen(tempFilename, "w");
    if (tempFile == NULL) {
        printf("Failed to open the temporary file.\n");
        fclose(inputFile);
        return 1;
    }

    char line[256];
    char lines[100][256];
    int count = 0;

    // Read the lines from the input file and store them in an array
    while (fgets(line, sizeof(line), inputFile)) {
        strcpy(lines[count], line);
        count++;
    }

    // Sort the lines based on the Temperature field in descending order using bubble sort
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            char* token1 = strtok(lines[j], ",");
            token1 = strtok(NULL, ",");
            float temp1 = atof(token1);

            char* token2 = strtok(lines[j + 1], ",");
            token2 = strtok(NULL, ",");
            float temp2 = atof(token2);

            if (temp1 < temp2) {
                swap(lines[j], lines[j + 1]);
            }
        }
    }

    // Write the sorted lines to the temporary file
    for (int i = 0; i < count; i++) {
        fputs(lines[i], tempFile);
    }

    // Close the input file and the temporary file
    fclose(inputFile);
    fclose(tempFile);

    // Rename the temporary file to the original filename
    if (rename(tempFilename, filename) != 0) {
        printf("Failed to rename the temporary file.\n");
        return 1;
    }

    printf("Sorting completed successfully.\n");

    return 0;
}