// 큐의 데이터(Element는 미리 정의되어 있어야함. MAX_SIZE는 필요 없음
typedef struct Node
{
    Element data;
    struct Node *link;
} Node;

Node* rear = NULL;


Node* alloc_node(Element e)
{
    Node* p =(Node*)malloc(sizeof(Node));
    p->data = e;    // 데이터 초기화
    p->link = NULL; // 링크 초기화
    return p;
}

Element free_node(Node* p)
{
    Element e = p->data;    // 데이터 복사
    free(p);                // 동적 해제
    return e;               // 데이터 변환
}

void error(char* str)
{
    printf("%s\n", str);
    exit(1);
}

int is_empty() { return rear == NULL;}
int is_full() { return 0;}
void init_queue()   { rear = NULL;}

// 삽입 연산
void enqueue(Element e)
{
    Node* p = alloc_node(e);
    if (is_empty()) {
        rear = p;
        p->link = p;
    }
    else {
        p->link = rear->link;
        rear->link =p;
        rear = p;
    }
}

// 삭제 연산
Element dequeue()
{
    if (is_empty())
        error("Underflow Error!");

    Node* p = rear->link;
    if (rear == p)
        rear = NULL;
    else
        rear->link = p->link;
    return free_node(p);
}

// 탐색 연산
Element peek()
{
    if (is_empty())
        error("Undeflow Error!");
    return rear->link->data;
}

//모든 요소 삭제 연산
void destroy_queue()
{
    while (is_empty() == 0) dequeue();
}