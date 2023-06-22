#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50

// Structure to hold CSV entry data
struct Entry {
    int entryNo;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

// Function to parse CSV file and populate entries array
int parseCSV(const char* filename, struct Entry entries[]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file: %s\n", filename);
        return 0;
    }

    int count = 0;
    char line[100];
    char* token;

    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, ",");
        entries[count].entryNo = atoi(token);

        token = strtok(NULL, ",");
        strcpy(entries[count].name, token);

        token = strtok(NULL, ",");
        strcpy(entries[count].email, token);

        count++;
    }

    fclose(file);
    return count;
}

// Function to write entries array back to CSV file
void writeCSV(const char* filename, const struct Entry entries[], int count) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open file: %s\n", filename);
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%s\n", entries[i].entryNo, entries[i].name, entries[i].email);
    }

    fclose(file);
}

// Function to delete an entry from entries array based on EntryNo
void deleteEntry(struct Entry entries[], int count, int entryNo) {
    for (int i = 0; i < count; i++) {
        if (entries[i].entryNo == entryNo) {
            for (int j = i; j < count - 1; j++) {
                entries[j] = entries[j + 1];
            }
            break;
        }
    }
}

int main() {
    const char* filename = "data.csv";
    struct Entry entries[100];  // Assuming a maximum of 100 entries

    int count = parseCSV(filename, entries);
    if (count == 0) {
        printf("No entries found in the file.\n");
        return 0;
    }

    int entryNoToDelete;
    printf("Enter the EntryNo to delete: ");
    scanf("%d", &entryNoToDelete);

    deleteEntry(entries, count, entryNoToDelete);
    count--;

    writeCSV(filename, entries, count);

    printf("Entry with EntryNo %d has been deleted from the file.\n", entryNoToDelete);

    return 0;
}