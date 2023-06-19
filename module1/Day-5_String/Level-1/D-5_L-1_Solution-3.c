#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long compute_total_seconds(const char* time_string) {
  char* token;
  char* remainder;
  unsigned long hours, minutes, seconds;

  char* time_copy = strdup(time_string);  
  token = strtok(time_copy, ":");
  hours = strtoul(token, &remainder, 10);

  token = strtok(NULL, ":");
  minutes = strtoul(token, &remainder, 10);

  token = strtok(NULL, ":");
  seconds = strtoul(token, &remainder, 10);

  free(time_copy);  

  unsigned long total_seconds = hours * 3600 + minutes * 60 + seconds;
  return total_seconds;
}

int main() {
  const char* time_string1 = "10:12:50";
  unsigned long total_seconds1 = compute_total_seconds(time_string1);
  printf("Time String: %s\n", time_string1);
  printf("Total Seconds: %lu\n", total_seconds1);

  const char* time_string2 = "13:10:40";
  unsigned long total_seconds2 = compute_total_seconds(time_string2);
  printf("Time String: %s\n", time_string2);
  printf("Total Seconds: %lu\n", total_seconds2);

  return 0;
}