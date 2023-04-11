#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "tree.h"

struct stack {
    Node ** elements;
    int size;
    int top;
};

//========================================//
Stack * init_stack(int size);
Stack * stack_push(Stack * stack, Node * node);
Node * stack_pop(Stack * stack);
void end_stack(Stack * stack);

//========================================//
Stack * init_stack(int size){
    Stack * s = malloc(sizeof(Stack));
    s->elements = malloc(sizeof(Node*)*size);
    s->size=size;
    s->top=0;
    return s;
}

Stack * stack_push(Stack * stack, Node * node){
    if(stack->size == stack->top){
        perror("Full stack. Could not add element!\n");
        exit(1);
    }
    stack->elements[stack->top] = node;
    stack->top++;
    return stack;
}

Node * stack_pop(Stack * stack){
    if(!stack->top){
        perror("Empty stack. Could not remove element!\n");
        exit(1);
    }
    stack->top--;
    return stack->elements[stack->top];
}

Node * stack_peek(Stack * stack){
    return stack->elements[stack->top-1];
}

bool is_empty_stack(Stack * stack){
    return !stack->top;
}

void end_stack(Stack * stack){
    if(stack){
        if(stack->elements)
            free(stack->elements);
        free(stack);
    }
}
