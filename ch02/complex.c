#include <stdio.h>

typedef struct {
    double real; // 복소수의 실수부
    double imag; // 복소수의 허수부
} Complex;

void reset_complex(Complex c) {
    c.real = c.imag = 0.0;
}

void print_complex(Complex c) {
    printf("%4.1f + %4.1fi\n", c.real, c.imag);
}

int main()
{
    Complex a = {1.0, 2.0};
    printf("초기화 이전 : ");
    print_complex(a);
    reset_complex(a);  // 초기화 --> 실패
    printf("초기화 이후 : ");
    print_complex(a);
    return 0;
}