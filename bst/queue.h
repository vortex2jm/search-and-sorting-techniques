#ifndef queue_h
#define queue_h
#include <stdbool.h>
#include "tree.h"

typedef struct queue Queue;

Queue * init_queue(int size);

Queue * enqueue(Queue * queue, Node * node);

Node * dequeue (Queue * queue);

bool is_empty_queue(Queue * queue);

void end_queue(Queue *queue);

#endif
