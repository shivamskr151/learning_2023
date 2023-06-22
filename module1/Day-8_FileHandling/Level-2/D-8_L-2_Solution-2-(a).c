#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void updateEntryInFile(const char* filename, int entryNo, const char* updatedLine) {
    const char* tempFilename = "temp.csv";

    // Open the input file
    FILE* inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        printf("Failed to open the input file.\n");
        return;
    }

    // Open the temporary file
    FILE* tempFile = fopen(tempFilename, "w");
    if (tempFile == NULL) {
        printf("Failed to open the temporary file.\n");
        fclose(inputFile);
        return;
    }

    char line[256];
    int count = 0;
    int entryFound = 0;

    // Read the lines from the input file and write them to the temporary file
    while (fgets(line, sizeof(line), inputFile)) {
        char* token = strtok(line, ",");
        int currentEntryNo = atoi(token);

        if (currentEntryNo == entryNo) {
            fputs(updatedLine, tempFile);  // Write the updated line to the temporary file
            entryFound = 1;
        } else {
            fputs(line, tempFile);  // Write the original line to the temporary file
        }

        count++;
    }

    // Close the input file and the temporary file
    fclose(inputFile);
    fclose(tempFile);

    if (!entryFound) {
        printf("Entry with EntryNo %d not found.\n", entryNo);
        return;
    }

    // Rename the temporary file to the original filename
    if (rename(tempFilename, filename) != 0) {
        printf("Failed to rename the temporary file.\n");
        return;
    }

    printf("Entry updated successfully.\n");
}

int main() {
    const char* filename = "data.csv";
    int entryNo = 2;
    const char* updatedLine = "2,S3,35,100,50,10:30:55\n";

    updateEntryInFile(filename, entryNo, updatedLine);

    return 0;
}