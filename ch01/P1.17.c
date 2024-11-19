#include <stdio.h>
#include <time.h>

int SumAlgorithmA (int n){
    return n*(n+1)/2;
}

int SumAlgorithmB (int n){
    int sum;
    for (int i = 0; i<= n ; i++)
        sum+=i;
    return sum;
}
//1을 n번 더함.
int SumAlgorithmsC (int n){
    int sum;
    for (int i = 0; i<=n; i++)
        sum += 1;
    return sum;
}

int main(){
    clock_t start, finish;
    double AlgorithmADuration, AlgorithmBDuration, AlgorithmCDuration;
    int n ;
    
    printf("Enter  a number! : ");
    scanf("%d", &n);

    start = clock();
    printf("Sum using Algorithm A : %d\n", SumAlgorithmA(n));
    finish = clock();
    AlgorithmADuration = (double)(finish - start ) / CLOCKS_PER_SEC;

    start = clock();
    printf("Sum using Algorithm B ; %d\n", SumAlgorithmB(n));
    finish = clock();
    AlgorithmBDuration = (double)(finish - start) / CLOCKS_PER_SEC;

    start = clock();
    printf("Sum using Algorithm C : %d\n", SumAlgorithmsC(n));
    finish = clock();
    AlgorithmCDuration = (double)(finish - start) / CLOCKS_PER_SEC;

    printf("알고리즘 A의 소요 시간 : %f\n", AlgorithmADuration);
    printf("알고리즘 B의 소요 시간 : %f\n", AlgorithmBDuration);
    printf("알고리즘 C의 소요 시간 : %f\n", AlgorithmCDuration);

}