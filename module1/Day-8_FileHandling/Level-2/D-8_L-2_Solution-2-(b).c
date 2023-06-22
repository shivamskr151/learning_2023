#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char time[10];
} LogEntry;

void updateEntryInFile(const char* filename, const LogEntry entries[], int numEntries) {
    // Open the file for reading and writing
    FILE* file = fopen(filename, "r+");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    char line[256];
    int entryFound = 0;
    long currentPos = ftell(file);

    // Iterate through the file, searching for the entryNo
    while (fgets(line, sizeof(line), file)) {
        int currentEntryNo;
        sscanf(line, "%d,", &currentEntryNo);

        if (currentEntryNo == entries->entryNo) {
            entryFound = 1;
            fseek(file, currentPos, SEEK_SET);
            fprintf(file, "%d,%s,%.1f,%d,%d,%s\n", entries->entryNo, entries->sensorNo, entries->temperature,
                    entries->humidity, entries->light, entries->time);
            break;
        }

        currentPos = ftell(file);
    }

    if (!entryFound) {
        printf("Entry with EntryNo %d not found.\n", entries->entryNo);
    } else {
        printf("Entry updated successfully.\n");
    }

    fclose(file);
}

int main() {
    const char* filename = "data.csv";

    // Read the updated entry from user input or any other source
    LogEntry updatedEntry;
    updatedEntry.entryNo = 2;
    strcpy(updatedEntry.sensorNo, "S3");
    updatedEntry.temperature = 35;
    updatedEntry.humidity = 100;
    updatedEntry.light = 50;
    strcpy(updatedEntry.time, "10:30:55");

    updateEntryInFile(filename, &updatedEntry, 1);

    return 0;
}