#include <stdio.h>
#include <stdlib.h>

typedef int Element;
#include "LinkedStack.h"

void print_stack(Node* p)
{
    for ( ; p != NULL ; p = p->link){
        printf("%3d", p->data);
    }
}

void print_recur(Node* p)
{
    if (p != NULL) {
        print_recur(p->link);
        printf("%3d", p->data);
    }
}

int main()
{
    int A[7] = {0,1,1,2,3,5,8};

    int_stack();
    printf("스택 테스트\n 입력 데이터 : ");
    for (int i = 0 ; i < 7 ; i++){
        printf("3%d", A[i]);
        push(A[i]);
    }


    printf("\n 출력 데이터: ");
    while (!is_empty())
    {
        printf("%3d", pop());
    }
    printf("\n");

    destroy_srack();
}