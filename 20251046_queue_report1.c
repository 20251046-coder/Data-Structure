/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

#define SIZE 30 

typedef struct {
    int data[SIZE];
    int front;
    int rear;
} LinearQueue;

void initQueue(LinearQueue *q) {
    q->front = 0;
    q->rear = -1;
}

bool isEmpty(LinearQueue *q) {
    return q->rear < q->front;
}

bool isFull(LinearQueue *q) {
    return q->rear == SIZE - 1;
}

bool enqueue(LinearQueue *q, int value) {
    if (isFull(q)) {
        printf("오류: 큐가 가득 찼습니다.\n");
        return false;
    }
    q->rear++;
    q->data[q->rear] = value;
    printf("데이터 %d 삽입 완료.\n", value);
    return true;
}

int dequeue(LinearQueue *q) {
    if (isEmpty(q)) {
        printf("오류: 큐가 비어 있습니다.\n");
        return -1;
    }
    
    int value = q->data[q->front];
    q->front++;

    if (isEmpty(q)) {
        printf("큐가 비었습니다. 인덱스를 초기화합니다.\n");
        initQueue(q);
    }
    
    return value;
}

void displayQueue(LinearQueue *q) {
    if (isEmpty(q)) {
        printf("큐가 현재 비어 있습니다.\n");
        return;
    }
    printf("현재 큐 상태: [ ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("]\n");
}

int main() {
    LinearQueue q;
    initQueue(&q);
    int choice, value;

    while (1) {
        printf("\n--- 큐 관리 프로그램 ---\n");
        printf("1. 삽입 (Enqueue)\n");
        printf("2. 삭제 (Dequeue)\n");
        printf("3. 큐 데이터 출력\n");
        printf("4. 종료\n");
        printf("메뉴 선택: ");
        
        if (scanf("%d", &choice) != 1) break; 

        switch (choice) {
            case 1:
                printf("삽입할 데이터 입력: ");
                scanf("%d", &value);
                enqueue(&q, value); 
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("삭제된 데이터: %d\n", value);
                }
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 선택입니다. 다시 입력하세요.\n");
        }
    }

    return 0;
}
