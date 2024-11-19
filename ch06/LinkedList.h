#include <stdio.h>
#include <stdlib.h>

typedef int Element; // Element를 미리 정의된 자료형으로 설정 (필요에 맞게 수정 가능)

typedef struct Node {
    Element data;
    struct Node* link;
} Node;

Node* head = NULL;

// 단순 연결 구조 노드의 동적 할당 함수
Node* alloc_node(Element e) {
    Node* p = (Node*)malloc(sizeof(Node));
    if (p == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    p->data = e;
    p->link = NULL;
    return p;
}

// 단순 연결 구조 노드의 데이터 반환 및 동적 해제 함수
Element free_node(Node* p) {
    Element e = p->data;
    free(p);
    return e;
}

void error(char* str) {
    printf("%s\n", str);
    exit(1);
}

// 리스트의 연산들
int is_empty() { return head == NULL; }
int is_full() { return 0; } // 동적 할당을 사용하는 경우 항상 false
void init_list() { head = NULL; }

// 리스트 요소 접근 함수(노드, 데이터)
Node* get_node(int pos) {
    if (pos < 0) return NULL;
    Node* p = head;
    for (int i = 0; i < pos; i++, p = p->link)
        if (p == NULL) return NULL;
    return p;
}

Element get_entry(int pos) {
    Node* p = get_node(pos);
    if (p == NULL)
        error("Invalid Position Error!");
    return p->data;
}

// 리스트의 삽입 연산
void insert(int pos, Element e) {
    Node* p = alloc_node(e);
    if (pos == 0) {
        p->link = head;
        head = p;
    } else {
        Node* before = get_node(pos - 1);
        if (before == NULL)
            error("Invalid Position Error!");
        p->link = before->link;
        before->link = p;  // -> 누락 수정
    }
}

// 리스트의 삭제 연산
Element delete(int pos) {  // 함수명 "delte" -> "delete" 수정
    if (is_empty())
        error("Underflow Error!");

    Node* p = get_node(pos);
    if (p == NULL)
        error("Invalid Position Error!");

    Node* before = get_node(pos - 1);
    if (before == NULL)
        head = head->link;
    else
        before->link = p->link;

    return free_node(p);
}

// 리스트의 모든 요소 삭제(동적 삭제)
void destroy_list() {
    while (!is_empty()) delete(0);
}

int size() {
    int count = 0;
    for (Node* p = head; p != NULL; p = p->link) count++;
    return count;
}
