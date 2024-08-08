#ifndef QUEUE_H
#define QUEUE_H

#include "global.h"

void CreatQueue(void);
bool isQueueEmpty(void);
bool isQueueFull(void);
void enqueue(int item);
int dequeue(void);
int Queuesize( void );
#endif // QUEUE_H
