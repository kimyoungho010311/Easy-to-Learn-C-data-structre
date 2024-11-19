#include <stdio.h>
typedef int Element;
#define MAX_SIZE 100
// 리스트의 데이터(Element와 MAX_SZIE는 미리 정의되어 있어야 함)
Element data[MAX_SIZE]; //   요소의 배열
int size = 0;           //  요소의 수

void error(char str[])
{
    printf("%s\n",str);
    exit(1);
}

//리스트의 연산들
void init_list()  { size = 0;}
int is_empty() { return size == 0;}
int is_full() { return size == MAX_SIZE;}

// 삽입 연산
void insert(int pos, Element e)
{
    if(is_full())
        error("Overflow ERROR!");

    if (pos < 0 || pos > size)
        error("Invalid Position ERROR!");
    data[pos] = e;
    size += 1;
}

//삭제연산
Element delete(int pos)
{
    if (is_empty())
        error("Underflow ERROR!");

    if(pos < 0 || pos >= size)
        error("Invalid Position Error!");

    Element e = data[pos];
    for (int i = pos; i < size - 1; i++)
        data[i] = data[i+ 1];
    size -= 1;
    return e;
}

// 참조 연산    
Element get_entry(int pos)
{
    if (is_empty())
        error("Underflow ERROR!");
    if(pos < 0 || pos >= size)
        error("Invaild Position ERROR!");
    return data[pos];
}

void append(Element e)
{
    insert(size, e);
}
Element pop()
{
    return delete(size - 1);
}

void replace(int pos, Element e)
{
    if (pos < 0 || pos >= size)
        error("Invaild Position Error!");
    data[pos] = e;
}

int fine(Element e)
{
    for (int i = 0 ; i < size; i++)
        if (data[i] == e )
            return i;
    return -1;
}