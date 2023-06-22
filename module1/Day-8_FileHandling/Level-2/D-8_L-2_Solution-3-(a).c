#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deleteEntryFromFile(const char* filename, int entryNo) {
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
    int entryFound = 0;

    // Read the lines from the input file and write them to the temporary file
    while (fgets(line, sizeof(line), inputFile)) {
        char* token = strtok(line, ",");
        int currentEntryNo = atoi(token);

        if (currentEntryNo != entryNo) {
            fputs(line, tempFile);  // Write the line to the temporary file if it's not the one to be deleted
        } else {
            entryFound = 1;
        }
    }

    // Close the input file and the temporary file
    fclose(inputFile);
    fclose(tempFile);

    if (!entryFound) {
        printf("Entry with EntryNo %d not found.\n", entryNo);
        remove(tempFilename);  // Delete the temporary file
        return;
    }

    // Rename the temporary file to the original filename
    if (rename(tempFilename, filename) != 0) {
        printf("Failed to rename the temporary file.\n");
        return;
    }

    printf("Entry deleted successfully.\n");
}

int main() {
    const char* filename = "data.csv";
    int entryNo = 2;

    deleteEntryFromFile(filename, entryNo);

    return 0;
}