#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
};

int getNumberOfDays(struct Date startDate, struct Date endDate) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int totalDays = 0;

    for (int year = startDate.year; year < endDate.year; year++) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            totalDays += 366;
        else
            totalDays += 365;
    }

    for (int month = 1; month < startDate.month; month++)
        totalDays -= daysInMonth[month - 1];

    totalDays -= startDate.day - 1;

    for (int month = 1; month < endDate.month; month++)
        totalDays += daysInMonth[month - 1];

    totalDays += endDate.day;

    if ((startDate.year % 4 == 0 && startDate.year % 100 != 0) || (startDate.year % 400 == 0))
        if (startDate.month <= 2 && (endDate.month > 2 || (endDate.month == 2 && endDate.day == 29)))
            totalDays++;

    return totalDays;
}

int main() {
    struct Date startDate;
    struct Date endDate;

    char start_date_str[] = "10/04/2015";
    sscanf(start_date_str, "%d/%d/%d", &startDate.day, &startDate.month, &startDate.year);

    char end_date_str[] = "10/04/2016";
    sscanf(end_date_str, "%d/%d/%d", &endDate.day, &endDate.month, &endDate.year);

    int number_of_days = getNumberOfDays(startDate, endDate);
    printf("Number of days elapsed: %d\n", number_of_days);

    return 0;
}