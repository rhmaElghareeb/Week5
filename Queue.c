#include "Queue.h"

#if LIMITED_MEMORY == 1
// Linked-list based implementation

typedef struct Node {
    int data;
    struct Node* next;
} Node;

static Node* front = NULL;
static Node* rear = NULL;

void CreatQueue(void) {
    front = rear = NULL;
}

bool isQueueEmpty(void) {
    return front == NULL;
}

bool isQueueFull(void) {
    return 0;
}

void enqueue(int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Queue Overflow\n");
        return;
    }
    newNode->data = item;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue(void) {
    if (isQueueEmpty()) {
        printf("Queue Underflow\n");
        return -1; // or some error code
    }
    Node* temp = front;
    int data = temp->data;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
    return data;
}

int Queuesize( void ){
    Node* current = front;
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

static int queue[MAX_SIZE];
static int front = 0;
static int rear = -1;
static int size = 0;

void initQueue(void) {
    front = 0;
    rear = -1;
    size = 0;
}

bool isQueueEmpty(void) {
    return size == 0;
}

bool isQueueFull(void) {
    return size == MAX_SIZE;
}

void enqueue(int item) {
    if (isQueueFull()) {
        printf("Queue Overflow\n");
        return;
    }
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = item;
    size++;
}

int dequeue(void) {
    if (isQueueEmpty()) {
        printf("Queue Underflow\n");
        return -1; // or some error code
    }
    int data = queue[front];
    front = (front + 1) % MAX_SIZE;
    size--;
    return data;
}
int Queuesize( void ){
    return size;
}
#else
#error "Invalid LIMITED_MEMORY value. Use 1 for Linked-list based or 2 for Array based."
#endif
