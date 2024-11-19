#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 2000
typedef char Element;
#include "ArrayStack.h"

int main()
{
    char str[200];

    init_stack();
    printf("문자열 입력 : ");
    gets_s(str, sizeof(str));
    for(int i =0;str[i] != '\0' ; i ++)
        push(str[i]);

    printf("문자열 출력 : ");
    while (!is_empty())
        putchar(pop());
    printf("\n");

    return 0;
}