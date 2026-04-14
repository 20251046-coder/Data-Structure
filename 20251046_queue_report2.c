/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 10

typedef struct {
    char documentName[50];
    int numPages;
} PrintJob;

typedef struct {
    PrintJob joblist[SIZE];
    int front;
    int rear;
} CircularPrintQueue;

void initQueue(CircularPrintQueue *q) {
    q->front = 0;
    q->rear = 0;
}

bool isEmpty(CircularPrintQueue *q) {
    return q->front == q->rear;
}

bool isFull(CircularPrintQueue *q) {
    return (q->rear +1) % SIZE == q->front;
}

bool enqueue(CircularPrintQueue *q, char *name, int pages) {
    if (pages > 50) {
        printf("[거부] '%s' 추가 실패: 50장을 초과하는 문서는 인쇄할 수 없습니다.\n", name);
        return false;
    }
    
    if (isFull(q)) {
        printf("[오류] 대기열이 가득 찼습니다.\n");
        return false;
    }
    
    strcpy(q->joblist[q->rear].documentName, name);
    q->joblist[q->rear].numPages = pages;
    
    q->rear = (q->rear + 1) % SIZE;
    printf(">> '%s' (%d장) 추가 완료.\n", name, pages);
    return true;
}

PrintJob dequeue(CircularPrintQueue *q) {
    if (isEmpty(q)) {
        printf("[오류] 대기열이 비어 있습니다.\n");
        PrintJob empty = {"", 0};
        return empty;
    }
    
    PrintJob job = q->joblist[q->front];
    q->front = (q->front + 1) % SIZE;
    return job;
}

void cancelJob(CircularPrintQueue *q, char *name) {
    if (isEmpty(q)) {
        printf("대기열이 비어있어 취소할 수 없습니다.\n");
        return;
    }
    
    int i = q->front;
    int targetIdx = -1;
    
    while (i != q->rear) {
        if (strcmp(q->joblist[i].documentName, name) == 0) {
            targetIdx = i;
            break;
        }
        i = (i + 1) % SIZE;
    }
    
    if (targetIdx == -1) {
        printf(">> 해당 문서('%s')가 대기열에 없습니다다.\n", name);
        return;
    }
    
    printf(">> '%s' 작업을 취소합니다.\n", name);
    
    int current = targetIdx;
    int next = (targetIdx + 1) % SIZE;
    
    while (next != q->rear) {
        q->joblist[current] = q->joblist[next];
        current = next;
        next = (next + 1) % SIZE;
    }
    
    q->rear = (q->rear -1 + SIZE) % SIZE;
}

void clearQueue(CircularPrintQueue *q) {
    q->front = 0;
    q->rear = 0;
    printf(">>대기열 초기화가 완료되었습니다.\n");
}

void printQueue(CircularPrintQueue *q) {
    if (isEmpty(q)) {
        printf("\n---- 대기열 현황: 비어있음----\n");
        return;
    }
    printf("\n----현재 프린터 대기열 목록----\n");
    int i = q->front;
    while (i != q->rear) {
        printf("- %s (%d페이지)\n", q->joblist[i].documentName, q->joblist[i].numPages);
    }
    printf("-----------------------------\n");
}

int main() {
    CircularPrintQueue q;
    initQueue(&q);
    
    int choice;
    char name[50];
    int pages;
    
    while (true) {
        printf("\n1.추가 2.처리 3.조회 4.취소 5.비우기 6.종료\n선택: ");
        if (scanf("%d", &choice) != 1) break;
        
        switch (choice) {
            case 1:
                printf("문서명: ");
                scanf("%s", name);
                printf("페이지수: ");
                scanf("%d", &pages);
                enqueue(&q, name, pages);
                break;
            case 2: {
                PrintJob job = dequeue(&q);
                if (strlen(job.documentName) > 0)
                    printf("\n[인쇄 완료] '%s' (%d페이지)\n", job.documentName, job.numPages);
                break;
            }
            case 3:
                printQueue(&q);
                break;
            case 4:
                printf("취소할 문서명: ");
                scanf("%s", name);
                cancelJob(&q, name);
                break;
            case 5:
                clearQueue(&q);
                break;
            case 6:
                return 0;
        }
    }
}
