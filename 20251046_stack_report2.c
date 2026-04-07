/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *stack = (char *)malloc(100 * sizeof(char));
    int top = -1;
    char input[102];

    printf("문자열을 입력하세요: ");
    fgets(input, sizeof(input), stdin);

    for (int i = 0; input[i] != '\0' && input[i] != '\n'; i++) {
        char ch = input[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        } 
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1 || 
               (ch == ')' && stack[top] != '(') ||
               (ch == '}' && stack[top] != '{') ||
               (ch == ']' && stack[top] != '[')) {
                
                printf("유효하지 않은 괄호\n");
                free(stack); 
                return 0;
            }
            top--;
        }
    }

    if (top == -1) {
        printf("유효한 괄호\n");
    } else {
        printf("유효하지 않은 괄호\n");
    }

    free(stack);
    return 0;
}
