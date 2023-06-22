#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_DATA_ROWS 100

// Structure to represent a row of data
struct DataRow {
    float temperature;
    // Add other relevant fields here
};

// Function to compare two rows based on the Temperature field
int compareTemperature(const void *row1, const void *row2) {
    const struct DataRow *dataRow1 = (const struct DataRow *)row1;
    const struct DataRow *dataRow2 = (const struct DataRow *)row2;
    
    if (dataRow1->temperature > dataRow2->temperature)
        return -1; // Swap positions
    else if (dataRow1->temperature < dataRow2->temperature)
        return 1; // Keep positions unchanged
    else
        return 0; // Keep positions unchanged
}

int main() {
    FILE *fp;
    struct DataRow dataRows[MAX_DATA_ROWS];
    int count = 0;
    char line[MAX_LINE_LENGTH];
    
    // Open the file in read mode
    fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }
    
    // Read the lines from the file and store them in the array of structures
    while (fgets(line, sizeof(line), fp)) {
        struct DataRow *currentRow = &dataRows[count];
        sscanf(line, "%f", &currentRow->temperature);
        // Read and store other relevant fields from the line
        
        count++;
    }
    
    // Sort the array of structures based on the Temperature field
    qsort(dataRows, count, sizeof(struct DataRow), compareTemperature);
    
    // Open the file in write mode to overwrite the sorted data
    fp = fopen("data.csv", "w");
    if (fp == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }
    
    // Write the sorted data back to the file
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%.2f\n", dataRows[i].temperature);
        // Write other relevant fields to the file
    }
    
    // Close the file
    fclose(fp);
    
    printf("Sorting completed successfully.\n");
    
    return 0;
}