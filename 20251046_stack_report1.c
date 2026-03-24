/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100 //스택 최대 크기 정의

int main()
{
    //1. 스택으로 사용할 문자 배열을 동적으로 할당
    char *stack = (char *)malloc(MAX * sizeof(char));
    int top = -1;
    
    //입력을 받을 배열 (최대 100자 + 개해문자 + 널문자 여유 공간)
    char input[MAX + 2];
    
    //메모리 할당 실패 시 안전하게 종료
    if(stack == NULL){
        printf("메모리 할당에 실패했습니다.\n");
        return -1;
    }
    
    printf("문자열을 입력하세요 : ");
    if(fgets(input, sizeof(input), stdin) != NULL){
        
        //2.입력받은 문자열을 스택에 Push (LIFO 구조)
        for(int i = 0;input[i] != '\0' && i < MAX;i++){
            //엔터(줄바꿈) 문자는 무시하고 넘어감
            if(input[i] == '\n') continue;
            
            // stack 배열에 값을 넣고 top 위치 갱신 (Push 로직)
            stack[++top] = input[i];
        }
        // 3. 스택에서 Pop하여 거꾸로 출력
        printf("거꾸로 출력된 문자열: ");
        while (top >= 0) {
            // 맨 위(top)부터 차례대로 꺼내서 출력하고 top 감소 (Pop 로직)
            printf("%c", stack[top--]); 
        }
        printf("\n");
    }
    // 4. 과제 조건: 프로그램 종료 시 메모리 해제
    free(stack);
    return 0;
}
