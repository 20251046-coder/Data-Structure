/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void init(Stack* s) { s->top = -1; }
int is_empty(Stack* s) { return s->top == -1; }
void push(Stack* s, int val) { s->data[++(s->top)] = val; }
int pop(Stack* s) { return s->data[(s->top)--]; }
int peek(Stack* s) { return s->data[s->top]; }

int prec(char op) {
    switch (op) {
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1;
}

int evaluate(char* postfix) {
    Stack s;
    init(&s);
    for (int i = 0; i < (int)strlen(postfix); i++) {
        char ch = postfix[i];
        if (isdigit(ch)) {
            push(&s, ch - '0');
        } else {
            int op2 = pop(&s);
            int op1 = pop(&s);
            switch (ch) {
                case '+': push(&s, op1 + op2); break;
                case '-': push(&s, op1 - op2); break;
                case '*': push(&s, op1 * op2); break;
                case '/': push(&s, op1 / op2); break;
            }
        }
    }
    return pop(&s);
}

int infixToPostfix(char* infix, char* postfix) {
    Stack s;
    init(&s);
    int k = 0;

    for (int i = 0; i < (int)strlen(infix); i++) {
        char ch = infix[i];
        if (isdigit(ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            push(&s, ch);
        } else if (ch == ')') {
            while (!is_empty(&s) && peek(&s) != '(')
                postfix[k++] = pop(&s);
            pop(&s);
        } else {
            while (!is_empty(&s) && prec(ch) <= prec(peek(&s)))
                postfix[k++] = pop(&s);
            push(&s, ch);
        }
    }
    while (!is_empty(&s))
        postfix[k++] = pop(&s);
    
    postfix[k] = '\0';
    return evaluate(postfix);
}

int main(void) {
    char infix[MAX];
    char postfix[MAX];
    int result;

    printf(":중위표기식 입력 : ");
    scanf("%s", infix);

    result = infixToPostfix(infix, postfix);

    printf("후위표기식 : %s\n", postfix);
    printf("후위표기식 계산 결과 : %d\n", result);

    return 0;
}
