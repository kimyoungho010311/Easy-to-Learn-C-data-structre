typedef int Element;
Element data[MAX_SIZE];  // 큐의 요소를 저장하는 배열
int front;  // 큐의 전단(앞) 인덱스
int rear;   // 큐의 후단(뒤) 인덱스

// 에러 처리 함수
void error(char* str)
{
    printf("%s\n",str);
    exit(1);  // 프로그램 종료
}

// 원형 큐 초기화 함수
void init_queue() 
{
    front = rear = 0;  // 전단과 후단을 0으로 초기화
}

// 큐가 비었는지 확인하는 함수
int is_empty()
{
    return front == rear;  // 전단과 후단이 같으면 큐가 비어 있음
}

// 큐가 가득 찼는지 확인하는 함수
int is_full()
{
    return front == (rear + 1) % MAX_SIZE;  // 원형 배열에서 한 칸 차이로 전단과 후단이 만나면 가득 참
}

// 큐에 요소를 추가하는 함수
void enqueue(Element e)
{
    if (is_full())  // 큐가 가득 찼는지 확인
        error("Overflow ERROR!");  // 에러 메시지 출력
    rear = (rear + 1) % MAX_SIZE;  // 후단 인덱스 갱신 (원형 구조에 맞게)
    data[rear] = e;  // 후단에 요소 추가
}

// 큐에서 요소를 제거하는 함수
Element dequeue()
{
    if (is_empty())  // 큐가 비었는지 확인
        error("Underflow ERROR!");  // 에러 메시지 출력
    front = (front + 1) % MAX_SIZE;  // 전단 인덱스 갱신 (원형 구조에 맞게)
    return data[front];  // 제거된 요소 반환
}

// 큐의 맨 앞 요소를 확인하는 함수 (제거하지 않음)
Element peek()
{
    if (is_empty())  // 큐가 비었는지 확인
        error("Underflow ERROR!");  // 에러 메시지 출력
    return data[(front + 1) % MAX_SIZE];  // 맨 앞 요소 반환
}