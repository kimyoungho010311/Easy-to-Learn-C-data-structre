#include "CircularQueue.h"

// 덱의 데이터 : CircularQueue에 이미 정의되어 있음

// 덱의 주요 연산들
// 큐에서 이미 구현된 기능을 활용하는 연산들

void init_deque()
{
    init_queue();
}
void add_rear(Element val)
{
    enqueue(val);
}

Element delete_front()
{
    return dequeue();
}

Elemnt get_front()
{
    return peek();
}

// 큐에 없는 새로운 연산들
void add_front(Elemnt val){
    if (if_full)
        error("Overflow ERROR!");
    data[front]=val;
    front = (front - 1 +MAX_SIZE) % MAX_SIZE;
}

Element delete_rear()
{
    if (ix_empty)
        error("Underflow ERROR!");
    int prev = rear;
    rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
    return data[prev];
}
Element get_rear()
{
    if (is_empty)
        error("Underflow ERROR!");
    return data[rear];
}