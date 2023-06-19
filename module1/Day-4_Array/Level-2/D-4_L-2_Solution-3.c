#include <stdio.h>
#include <time.h>

int get_number_of_days_elapsed(struct tm start_date, struct tm end_date) {
  time_t start_time = mktime(&start_date);
  time_t end_time = mktime(&end_date);
  double difference = difftime(end_time, start_time);
  int number_of_days = difference / (24 * 60 * 60); 
  return number_of_days;
}

void analyze_days_elapsed(int number_of_days) {
  if (number_of_days > 100 && number_of_days <= 150) {
    printf("Analysis: More than 100 days and less than or equal to 150 days elapsed.\n");
  } else {
    printf("Analysis: Number of days elapsed does not fall within the specified range.\n");
  }
}

int main() {
  struct tm start_date = {0};
  start_date.tm_year = 2015 - 1900; 
  start_date.tm_mon = 3; 
  start_date.tm_mday = 10;

  struct tm end_date = {0};
  end_date.tm_year = 2016 - 1900;
  end_date.tm_mon = 3;
  end_date.tm_mday = 10;

  int number_of_days = get_number_of_days_elapsed(start_date, end_date);
  printf("Number of days elapsed: %d\n", number_of_days);

  analyze_days_elapsed(number_of_days);

  return 0;
}