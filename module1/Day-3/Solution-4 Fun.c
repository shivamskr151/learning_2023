#include <stdio.h>

int findLargestNumber(int num) {
    int largest = 0;
    int divisor = 1000;

    while (divisor >= 1) {
        int digit = (num / divisor) * divisor + (num % (divisor / 10));

        if (digit > largest) {
            largest = digit;
        }

        divisor /= 10;
    }

    return largest;
}

int main() {
    int number;
    printf("Enter a 4-digit number: ");
    scanf("%d", &number);

    int largestNumber = findLargestNumber(number);
    printf("Largest number after deleting a digit: %d\n", largestNumber);

    return 0;
}