// 스택의 데이터 (Element는 미리 정의되어 있어야 하고, MAX_SIZE는 필요 없음)
typedef int Element;

typedef struct Node {   //자기참조구조체
    Element data;       // 데이터 필드(스택 요소)
    struct Node* link;  // 링크 필드

} Node;
Node* top = NULL;

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

//스택의 연산들
int is_empty() { return top == NULL;}
int is_full() { return 0;}
void int_stack()    { top = NULL;}
// 삽입 연산
void push(Element e)
{
    Node* p = alloc_node(e);
    p->link = top;
    top = p;
}

// 삭제 연산
Element pop()
{
    if (is_empty())
        error("Underflow Error!");
    Node* p = top;
    top = p->link;
    return free_node(p);
}

// 참조 연산
Element peek()
{
    if(is_empty())
        error("Underflow Error!");
    return top->data;
}

// 스택의 모든 노드 삭제( 동적 해제)
void destroy_srack()
{
    while (is_empty() == 0) pop();
}

int size()
{
    int count = 0;
    for (Node* p = top; p != NULL; p = p->link)
        count ++;
    return count;
}