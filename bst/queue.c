#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct queue {
    Node ** elements;
    int size;
    int amount;
    int front;
};

//========================================//
Queue * init_queue(int size);
Queue * enqueue(Queue * queue, Node * node);
Node * dequeue (Queue * queue);
void end_queue(Queue *queue);

//========================================//
Queue * init_queue(int size){
    Queue * q = malloc(sizeof(Queue));
    q->elements = malloc(sizeof(Node*)*size * 2);
    q->size = size;
    q->amount = 0;
    q->front = 0;    
}

Queue * enqueue(Queue * queue, Node * node){
    if(queue->amount == queue->size){
        perror("Full queue. Could not add an element!\n");
        exit(1);
    }
    int end = (queue->front + queue->amount) % queue->size;
    queue->elements[end] = node;
    queue->amount++;
    return queue;
}

Node * dequeue (Queue * queue){
    if(!queue->amount){
        perror("Empty queue. Could not remove an element!\n");
        exit(1);
    }
    Node * n = queue->elements[queue->front]; 
    queue->front = (queue->front + 1) % queue->size;
    queue->amount--;
    return n;
}

bool is_empty_queue(Queue * queue){
    return !queue->amount;
}

void end_queue(Queue *queue){
    if(queue){
        if(queue->elements)
            free(queue->elements);
        free(queue);
    }
}
