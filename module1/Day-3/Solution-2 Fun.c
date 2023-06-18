#include <stdio.h>

void print_bits(unsigned int num) {
    int i;

    for (i = 31; i >= 0; i--) {
        unsigned int mask = 1 << i; // Create a mask for the current bit
        unsigned int bit = (num & mask) >> i; // Extract the current bit

        printf("%u", bit);
    }

    printf("\n");
}

int main() {
    unsigned int num;

    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);

    printf("Bits representation: ");
    print_bits(num);
    return 0;
}