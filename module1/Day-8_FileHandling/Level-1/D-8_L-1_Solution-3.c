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

void extractDataFromFile(LogEntry entries[], int* numEntries, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    char line[256];
    int count = 0;
    while (fgets(line, sizeof(line), file)) {
        char* token = strtok(line, ",");
        entries[count].entryNo = atoi(token);

        token = strtok(NULL, ",");
        strcpy(entries[count].sensorNo, token);

        token = strtok(NULL, ",");
        entries[count].temperature = atof(token);

        token = strtok(NULL, ",");
        entries[count].humidity = atoi(token);

        token = strtok(NULL, ",");
        entries[count].light = atoi(token);

        token = strtok(NULL, ",");
        strcpy(entries[count].time, token);

        count++;
    }

    *numEntries = count;
    fclose(file);
}

void displayLogEntries(const LogEntry entries[], int numEntries) {
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTime\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%d\t%s\t\t%.1f\t\t%d\t\t%d\t%s\n", entries[i].entryNo, entries[i].sensorNo,
               entries[i].temperature, entries[i].humidity, entries[i].light, entries[i].time);
    }
}

int main() {
    LogEntry entries[MAX_ENTRIES];
    int numEntries = 0;
    const char* filename = "data.csv";

    extractDataFromFile(entries, &numEntries, filename);
    displayLogEntries(entries, numEntries);

    return 0;
}