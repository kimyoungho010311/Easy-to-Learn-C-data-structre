#include <stdio.h>
#include <limits.h>  // INT_MAX 사용

#define INF INT_MAX
#define VSIZE 4  // 노드 수

// 그래프 정의 (가중치 행렬)
int adj[VSIZE][VSIZE] = {
    {0, 4, INF, INF},
    {INF, 0, 1, 5},
    {INF, INF, 0, 8},
    {INF, INF, INF, 0}
};
int A[VSIZE][VSIZE];  // 최단 거리 행렬

// 행렬 출력 함수
void printA() {
    for (int i = 0; i < VSIZE; i++) {
        for (int j = 0; j < VSIZE; j++) {
            if (A[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Floyd-Warshall 알고리즘
void Floyd() {
    // A 배열 초기화
    for (int i = 0; i < VSIZE; i++)
        for (int j = 0; j < VSIZE; j++)
            A[i][j] = adj[i][j];

    // 최단 경로 계산
    for (int k = 0; k < VSIZE; k++) {
        for (int i = 0; i < VSIZE; i++) {
            for (int j = 0; j < VSIZE; j++) {
                if (A[i][k] != INF && A[k][j] != INF && A[i][k] + A[k][j] < A[i][j])
                    A[i][j] = A[i][k] + A[k][j];
            }
        }
        printf("After processing node %d:\n", k);
        printA();
    }
}

int main() {
    printf("Initial matrix:\n");
    printA();

    Floyd();

    printf("Final shortest path matrix:\n");
    printA();

    return 0;
}