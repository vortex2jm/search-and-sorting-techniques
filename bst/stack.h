#ifndef stack_h 
#define stack_h
#include <stdbool.h>
#include "tree.h"

typedef struct stack Stack;

Stack * init_stack(int size);

Stack * stack_push(Stack * stack, Node * node);

Node * stack_pop(Stack * stack);

Node * stack_peek(Stack * stack);

bool is_empty_stack(Stack * stack);

void end_stack(Stack * stack);

#endif
