#include <stdio.h>

struct complex {
    float real;
    float imag;
};

void read_complex(struct complex *c) {
    printf("Enter the real part of the complex number: ");
    scanf("%f", &c->real);
    printf("Enter the imaginary part of the complex number: ");
    scanf("%f", &c->imag);
}

void write_complex(struct complex c) {
    printf("The complex number is %.2f + %.2fi\n", c.real, c.imag);
}

struct complex add_complex(struct complex c1, struct complex c2) {
    struct complex sum;
    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;
    return sum;
}

struct complex multiply_complex(struct complex c1, struct complex c2) {
    struct complex product;
    product.real = c1.real * c2.real - c1.imag * c2.imag;
    product.imag = c1.real * c2.imag + c1.imag * c2.real;
    return product;
}

int main() {
    struct complex c1, c2, sum, product;
    printf("Enter the first complex number:\n");
    read_complex(&c1);

    printf("Enter the second complex number:\n");
    read_complex(&c2);

    sum = add_complex(c1, c2);

    printf("\nSum of the complex numbers:\n");
    write_complex(sum);

   
    product = multiply_complex(c1, c2);

    printf("\nProduct of the complex numbers:\n");
    write_complex(product);

    return 0;
}