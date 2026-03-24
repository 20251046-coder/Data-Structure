/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *stack = (char *)malloc(100 * sizeof(char)); // 스택 동적 할당
    int top = -1;
    char input[102];

    printf("문자열을 입력하세요: ");
    fgets(input, sizeof(input), stdin);

    for (int i = 0; input[i] != '\0' && input[i] != '\n'; i++) {
        char ch = input[i];

        // 1. 여는 괄호면 스택에 넣기 (Push)
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        } 
        // 2. 닫는 괄호면 확인하기
        else if (ch == ')' || ch == '}' || ch == ']') {
            // 꺼낼 게 없거나 짝이 안 맞으면 즉시 종료
            if (top == -1 || 
               (ch == ')' && stack[top] != '(') ||
               (ch == '}' && stack[top] != '{') ||
               (ch == ']' && stack[top] != '[')) {
                
                printf("유효하지 않은 괄호\n");
                free(stack); // 종료 전 메모리 해제
                return 0;
            }
            top--; // 짝이 맞으면 스택에서 빼기 (Pop)
        }
    }

    // 3. 다 끝났을 때 스택이 텅 비어있어야 정상
    if (top == -1) {
        printf("유효한 괄호\n");
    } else {
        printf("유효하지 않은 괄호\n");
    }

    free(stack); // 정상 종료 전 메모리 해제
    return 0;
}
