#ifndef STACK_H
#define STACK_H

#include "global.h"

// Function declarations for stack operations
void CreatStack(void);
bool isEmpty(void);
bool isFull(void);
void push(int item);
int pop(void);
int Top(void);
int StackSize(void);
#endif // STACK_H
