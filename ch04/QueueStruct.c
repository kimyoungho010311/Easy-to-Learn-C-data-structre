#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 8
typedef int Element;

typedef struct {
    Element data[MAX_SIZE];
    int front;
    int rear;
} Queue;

// 오류 처리 함수
void error(char* message) {
    printf("%s\n", message);
    exit(1);
}

// 큐 초기화 함수
void init_queue(Queue* q) {
    q->front = q->rear = 0;
}

// 큐가 비었는지 확인하는 함수
int is_empty(Queue* q) {
    return (q->front == q->rear);
}

// 큐가 가득 찼는지 확인하는 함수
int is_full(Queue* q) {
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

// 큐에 요소를 추가하는 함수
void enqueue(Queue* q, Element e) {
    if (is_full(q)) {
        error("Queue Overflow");
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = e;
}

// 큐에서 요소를 제거하는 함수
Element dequeue(Queue* q) {
    if (is_empty(q)) {
        error("Queue Underflow");
    }
    q->front = (q->front + 1) % MAX_SIZE;
    return q->data[q->front];
}

// 큐를 출력하는 함수
void print_queue(Queue* q, char msg[]) {
    printf("%s front=%d, rear=%d --> ", msg, q->front, q->rear);
    int size = (q->rear - q->front + MAX_SIZE) % MAX_SIZE;

    for (int i = q->front + 1; i <= q->front + size; i++)
        printf("%2d ", q->data[i % MAX_SIZE]);
    printf("\n");
}

int main() {
    Queue q;
    init_queue(&q);

    for (int i = 1; i < 7; i++) {
        enqueue(&q, i);
    }
    print_queue(&q, "enqueue 1~6:");

    for (int i = 0; i < 4; i++) {
        dequeue(&q);
    }
    print_queue(&q, "dequeue 4회:");

    for (int i = 7; i < 10; i++) {
        enqueue(&q, i);
    }
    print_queue(&q, "enqueue 7~9:");

    return 0;
}