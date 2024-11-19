// 스택의 데이터(Element는 미리 정의되어 있어야 함)
int MAX_SIZE = 10;
Element* data = NULL;
int top;


int is_empty()
{
    if (top == -1) return 1;
    else return 0;
}

int is_full()
{

    return(top == (MAX_SIZE -1 ));
}
void init_stack()
{
    data = (Element*)malloc(sizeof(Element) * MAX_SIZE);
    top = -1;
}

void push(Element e)
{
    if(is_full()) {
        MAX_SIZE *= 2;  //  용량을 두배로 늘림
        data = (Element*)realloc(data, sizeof(Element) * MAX_SIZE);
        printf("realloc(%d)(\n)", MAX_SIZE);
        //error("Overflow Error!")
    }
    data[++top] = e;
}

Element pop() {
    if(is_empty)
        error("Underflow Error!");
    return data[top--];
}

Element peek(){
    if(is_empty())
        error("Underflow Error!");
    return data[top];
}