#include <stdio.h>
#include <stdlib.h>

typedef int Element;
#include "CirLinkedQueue.h"

// 연결된 큐의 출력 연산
void print_queue(char* msg)
{
    printf("%s= ", msg);
    if (rear != NULL) {
        for (Node *p = rear->link; p != rear; p = p->link)
            printf("%2d ", p->data);
        printf("%2d ", rear->data);
    }
    printf("\n");
}

int main()
{
    init_queue();

    // 1 ~ 6 삽입
    for (int i = 1; i < 7; i++) 
        enqueue(i);
    print_queue("enqueue 1~6:");

    // 4회 삭제
    for (int i = 0; i < 4; i++) 
        dequeue();
    print_queue("dequeue 4회:");

    // 7 ~ 9 삽입
    for (int i = 7; i < 10; i++) 
        enqueue(i);
    print_queue("enqueue 7~9:");
    
    destroy_queue();
}