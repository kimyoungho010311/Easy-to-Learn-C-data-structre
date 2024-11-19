#include <stdio.h>
#include <stdlib.h>
#define MAX_VSIZE 100  // 최대 정점의 수
typedef char VElement;   // VElement의 자료형 정의

int vsize = 5;  // 그래프의 정점 수
VElement vdata[MAX_VSIZE] = { 'U', 'V', 'W', 'X', 'Y' };
int adj[MAX_VSIZE][MAX_VSIZE] = {
    { 0, 1, 1, 0, 0},
    { 1, 0, 1, 1, 0},
    { 1, 1, 0, 0, 1},
    { 0, 1, 0, 0, 0},
    { 0, 0, 1, 0, 0},
};

int degree(int v)  // 정점 v의 차수를 구하는 함수
{
    int count = 0;
    for (int i = 0; i < vsize; i++)
        if (adj[v][i] == 1) count++;
    return count;
}

void main()
{
    printf("그래프의 인접행열 표현 \n");
    for (int i = 0; i < vsize; i++) {
        printf("정점 %c(치수=%d): ", vdata[i], degree(i));
        for (int j = 0 ; j < vsize ; j++)
            printf("%2d", adj[i][j]);
        printf("\n");
    }
}