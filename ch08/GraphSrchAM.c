#include <stdio.h>
#include <stdlib.h>
#define MAX_VSIZE 100
typedef char VElement;

int vsize = 8; // 그래프 정점의 수
VElement vdata[MAX_VSIZE] = { 'A', 'B','C','D','E','F','G','H'};
int adj[MAX_VSIZE][MAX_VSIZE] = {
    { 0, 1, 1, 0, 0, 0, 0, 0}, // A
    { 1, 0, 0, 1, 0, 0, 0, 0}, // B
    { 1, 0, 0, 1, 1, 0, 0, 0}, // C
    { 0, 1, 1, 0, 0, 1, 0, 0}, // D
    { 0, 0, 1, 0, 0, 0, 1, 1}, // E
    { 0, 0, 0, 1, 0, 0, 0, 0}, // F
    { 0, 0, 0, 0, 1, 0, 0, 1}, // G
    { 0, 0, 0, 0, 1, 0, 1, 0} // H 
};

#define PrintVtx(i) (printf("%c ", vdata[i]))
// 매크로를 정의하는 키워드로, 코드에 반복적으로 사용되는 작업을 간단히 줄인다.
// PrtinfVtx('A') -> "A"

int visited[MAX_VSIZE]; // 방문 표시 리스트
void reset_visited() // <- 정점의 방문을 초기화함 첨부터 끝까지 0 대입
{
    for (int i = 0 ; i < vsize ; i++)
        visited[i] = 0;
}

void DFS(int v)
{
    visited[v] = 1;
    PrintVtx(v); //정점 v 방문
    for (int u = 0 ; u < vsize ; u++)
        if (adj[v][u] != 0 && visited[u] == 0)
            DFS(u);
}
#define MAX_QUEUE_SIZE 100
typedef int Element;

Element queue[MAX_QUEUE_SIZE];
int front = 0, rear = 0;

void init_queue()
{
    front = rear = 0;
}

int is_empty()
{
    return front == rear;
}

int is_full()
{
    return (rear + 1) % MAX_QUEUE_SIZE == front;
}

void enqueue(Element item)
{
    if (is_full()) {
        fprintf(stderr, "Queue is full\n");
        exit(1);
    }
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    queue[rear] = item;
}

Element dequeue()
{
    if (is_empty()) {
        fprintf(stderr, "Queue is empty\n");
        exit(1);
    }
    front = (front + 1) % MAX_QUEUE_SIZE;
    return queue[front];
}


void BFS(int v)
{
    init_queue();
    PrintVtx(v);
    visited[v] = 1;
    enqueue(v);
    while (!is_empty())
    {
        v = dequeue();
        for (int u = 0; u < vsize; u++) {
            if (adj[v][u] != 0 && visited[u] == 0) {
                PrintVtx(u);  // 정점 u 방ㅁㄴ
                visited[u] = 1;
                enqueue(u);
            }
        }
    }
}

int main()
{
    int s = 0; // 시작 정점 A

    reset_visited();
    printf("\nDFS(%c출발) ==> ", vdata[s]);
    DFS(s);

    reset_visited();
    printf("\nBFS(%c출발) ==> ", vdata[s]);
    BFS(s);
    printf("\n\n");
}