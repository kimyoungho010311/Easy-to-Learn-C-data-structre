#include <stdlib.h>
#include <stdlib.h>

#define MAX_SZIE 100
typedef int Element;
#include "ArrayList.h" // 리스트 데이터와 연산

void print_list(char* msg)
{
    printf("배열구조리스트 %s[%2d]: ", msg, size);
    for (int i = 0; i<size; i++)
        printf("%2d ", data[i]);
    printf("\n");
}

int main()
{
    init_list();    //[]
    insert(0, 10);  //[10]
    insert(0,20);   //[20, 10]
    insert(1,30);   //[20, 30, 10]
    insert(size,40);//[20,30,10,40]
    insert(2, 50);  // [20,30,50,10,40]
    print_list("(삽입 X 5)");

    delete(2);      //20, 30, 10 40
    delete(size -1);// 20, 30, 10
    delete(0);      // 30, 10
    print_list("(삭제 X 3)");
}