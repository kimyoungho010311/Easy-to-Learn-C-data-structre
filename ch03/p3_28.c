#include <stdio.h>

// 다음을 계산하는 순환적인 프로그램을 작성해줘
// 1+1/2+1/3+...+1/n

double hermetic_sum(int n) {
    double result = 0.0;
    for (int i = 1 ; i<n ; i++){
        result += 1.0/n;
    }
    return result;
}

int main() {
    int n;
    printf("please inset N : ");
    scanf("%d", &n);

    printf("1 + 1/2 + 1/3 + ... + 1/%d = %lf\n", n , hermetic_sum(n));
}

