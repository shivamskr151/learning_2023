#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SensorData {
    char sensorID[3];
    float temperature;
    int humidity;
    int lightIntensity;
};

void parseData(const char* data, struct SensorData* sensorInfo, int* numSensors) {
    const char* delimiter = "-T:";
    char* token;
    char* dataCopy = strdup(data); 

    *numSensors = 0;
    token = strtok(dataCopy, "\n");
    while (token != NULL) {
        sscanf(token, "S%2[^-]%*cT:%f-H:%d-L:%d",
               sensorInfo[*numSensors].sensorID,
               &sensorInfo[*numSensors].temperature,
               &sensorInfo[*numSensors].humidity,
               &sensorInfo[*numSensors].lightIntensity);

        (*numSensors)++;
        token = strtok(NULL, "\n");
    }

    free(dataCopy); 
}

void printSensorInfo(const struct SensorData* sensorInfo, int numSensors) {
    printf("Sensor Info:\n");
    printf("------------------\n");
    for (int i = 0; i < numSensors; i++) {
        printf("Sensor ID: %s\n", sensorInfo[i].sensorID);
        printf("Temperature: %.1f C\n", sensorInfo[i].temperature);
        printf("Humidity: %d\n", sensorInfo[i].humidity);
        printf("Light Intensity: %d%%\n", sensorInfo[i].lightIntensity);
        printf("------------------\n");
    }
}

int main() {
    const char* data = "S1-T:36.5-H:100-L:50\nS2-T:37.5-H:80-L:70";
    struct SensorData sensorInfo[10]; 
    int numSensors;

    parseData(data, sensorInfo, &numSensors);
    printSensorInfo(sensorInfo, numSensors);

    return 0;
}