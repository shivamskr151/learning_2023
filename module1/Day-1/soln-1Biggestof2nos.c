#include <stdio.h>

int find_biggest(int a, int b) {
   
    int biggest = (a > b) ? a : b;
     return biggest;
}

int main() {
    int a,b;
    printf("\n Enter two number:");
    scanf("%d %d",&a,&b);
    int result = find_biggest(a, b);
    printf("The biggest number is: %d\n", result);
    return 0;
}
