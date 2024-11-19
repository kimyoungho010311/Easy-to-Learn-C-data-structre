typedef struct DNode
{
    Element data;
    struct DNode* prev; // previous node
    struct DNode* next; // next node
} DNode;

DNode org;

DNode* alloc_Dnode(Element e)
{
    DNode* p = (DNode*)malloc(sizeof(DNode));
    p->data = e;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

Element free_dnode(DNode* p)
{
    Element e = p->data;
    free(p);
    return e;
}

void error(char* str)
{
    printf("%s\n", str);
    exit(1);
}

// 리스트의 연산들
int is_empty() { return org.next == NULL; }
int is_full() { return 0; }
void init_list() { org.next = NULL; }

// 리스트 노드 및 데이터 접근
DNode* get_node(int pos)
{
    DNode* p = &org;
    for (int i = 0; i <= pos; i++) {
        p = p->next;
        if (p == NULL)
            return NULL;
    }
    return p;
}

Element get_entry(int pos)
{
    DNode* p = get_node(pos);
    if (pos < 0 || p == NULL)
        error("Invalid Position Error!");
    return p->data;
}

// 삽입 연산
void insert(int pos, Element e)
{
    DNode* before = get_node(pos - 1);
    if (before == NULL)
        error("Invalid Position Error!");

    DNode* p = alloc_Dnode(e);
    p->next = before->next;
    p->prev = before;
    before->next = p;
    if (p->next != NULL)
        p->next->prev = p;
}

// 삭제 연산
Element delete(int pos)
{
    DNode* p = get_node(pos);
    if (pos < 0 || p == NULL)
        error("Invalid Position Error!");

    p->prev->next = p->next;
    if (p->next != NULL)
        p->next->prev = p->prev;

    return free_dnode(p);
}

void destroy_list() { while (!is_empty()) delete(0); }

int size()
{
    int count = 0;
    for (DNode* p = org.next; p != NULL; p = p->next)
        count++;
    return count;
}

// TODO: asdaasdad
// FIXME: asdasd