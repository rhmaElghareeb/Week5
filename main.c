#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
    int top;
    char items[MAX];
} Stack;

void CreatStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char item) {
    if (s->top == (MAX - 1)) {
        printf("Stack is full\n");
        return;
    }
    s->items[++(s->top)] = item;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return '\0';
    }
    return s->items[(s->top)--];
}

char Top(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[s->top];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    CreatStack(&s);
    int k = 0;
    for (int i = 0; infix[i]; i++) {
        if (isspace(infix[i])) {
            continue;  // Ignore spaces
        }
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            push(&s, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(&s) && Top(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s);
        } else if (isOperator(infix[i])) {
            while (!isEmpty(&s) && precedence(Top(&s)) >= precedence(infix[i])) {
                postfix[k++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }
    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0';
}

//================================================================================================================================================
int main() {
    char infix[MAX];
    char postfix[MAX];

    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);


    size_t len = strlen(infix);
    if (len > 0 && infix[len - 1] == '\n') {
        infix[len - 1] = '\0';
    }

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
