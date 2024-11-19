#include <stdio.h>
#include <stdlib.h>

void rand_array(int* A, int n)
{
    for (int i = 0; i < n ; i++)
        A[i] = rand() % 100;
}  // 배열 A의 요소를 0 ~ 99 의 무작위 값으로 초기화하는 함수. 배열의 주소 A와 크기 n을 전달받아야함

void print_array(int*A, int n)
{
    printf("배열의 요소 : ");
    for (int i = 0; i<n;i++)
        printf("%3d", A[i]);
    printf("\n");
}
double average_array(int* A, int n)
{
    int sum = 0;
    for (int i=0; i < n ;i++)
        sum += A[i];
    return ((double)sum / n);
}

int main()
{
    int size;
    printf("배열의 크기 : ");
    scanf("%d", &size);

    int* data = (int*)malloc(sizeof(int)* size);
    rand_array(data,size);
    print_array(data, size);
    double avg = average_array(data, size);
    printf("배열의 평균 : %lf\n", avg);
    free(data);
}
