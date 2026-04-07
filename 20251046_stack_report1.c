/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100 

int main()
{
    char *stack = (char *)malloc(MAX * sizeof(char));
    int top = -1;

    char input[MAX + 2];

    if(stack == NULL){
        printf("메모리 할당에 실패했습니다.\n");
        return -1;
    }
    
    printf("문자열을 입력하세요 : ");
    if(fgets(input, sizeof(input), stdin) != NULL){
     
        for(int i = 0;input[i] != '\0' && i < MAX;i++){
            if(input[i] == '\n') continue;
            stack[++top] = input[i];
        }
        printf("거꾸로 출력된 문자열: ");
        while (top >= 0) {
            printf("%c", stack[top--]); 
        }
        printf("\n");
    }
    free(stack);
    return 0;
}
