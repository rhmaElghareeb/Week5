#include "Stack.h"

#if LIMITED_MEMORY == 1
// Linked-list based implementation

typedef struct Node {
    int data;
    struct Node* next;
} Node;

static Node* top = NULL;

void CreatStack(void) {
    top = NULL;
}

bool isEmpty(void) {
    return top == NULL;
}

bool isFull(void) {
    return false; // Linked list based stack cannot be full
}

void push(int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = item;
    newNode->next = top;
    top = newNode;
}

int pop(void) {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    Node* temp = top;
    int data = temp->data;
    top = top->next;
    free(temp);
    return data;
}

int Top(void) {
    if (isEmpty()) {
        printf("Stack is Empty\n");
        return -1; // or some error code
    }
    return top->data;
}

int StackSize(void){
    Node* current = top;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}


#elif LIMITED_MEMORY == 2
// Array based implementation

#define MAX_SIZE 100

static int stack[MAX_SIZE];
static int top = -1;

void CreatStack(void) {
    top = -1;
}

bool isEmpty(void) {
    return top == -1;
}

bool isFull(void) {
    return top == MAX_SIZE - 1;
}

void push(int item) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

int pop(void) {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top--];
}

int Top(void) {
    if (isEmpty()) {
        printf("Stack is Empty\n");
        return -1; // or some error code
    }
    return stack[top];
}

int StackSize(void){
    if (isEmpty()) {
        return 0;
    }
    return top + 1;
}


#else
#error "Invalid LIMITED_MEMORY value. Use 1 for Linked-list based or 2 for Array based."
#endif
