#include <stdio.h>
#include <stdlib.h>

typedef int Element;
#include "DynArrayStack.h"

int main()
{
    MAX_SIZE = 8;   // 최초의 스택 크기를 8로 설정
    init_stack();   // 스택 초기화. 동적 할당 포함

    printf("[insert]\n");
    for (int i = 0 ; i< 50 ; i++)
    {
        printf(" %d", i);
        push(i);
    }

    printf("\noutput\n");
    while (!is_empty())
        printf(" %d", pop());
    printf("\n");
    free(data);
}
