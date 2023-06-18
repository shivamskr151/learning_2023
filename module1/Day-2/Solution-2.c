#include <stdio.h>

void swap(void* a, void* b, size_t size) {
    char* ptr_a = (char*)a;
    char* ptr_b = (char*)b;

    for (size_t i = 0; i < size; i++) {
        char temp = *(ptr_a + i);
        *(ptr_a + i) = *(ptr_b + i);
        *(ptr_b + i) = temp;
    }
}

int main() {
    int num1,num2;
    double pi,e;
    printf("\n Enter the number1 value:");
    scanf("%d",&num1);
    printf("\n Enter the number2 value:");
    scanf("%d",&num2);
    printf("\n Enter the number1 in decimal value:");
    scanf("%lf",&pi);
    printf("\n Enter the number2 in decimal value:");
    scanf("%lf",&e);

    printf("Before swap: num1 = %d, num2 = %d\n", num1, num2);

    swap(&num1, &num2, sizeof(int));

    printf("After swap: num1 = %d, num2 = %d\n", num1, num2);

    printf("Before swap: pi = %f, e = %f\n", pi, e);

    swap(&pi, &e, sizeof(double));

    printf("After swap: pi = %f, e = %f\n", pi, e);

    return 0;
}
