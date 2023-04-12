#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "stack.h"
#include "queue.h"

struct node {
    int key;
    Node * left;
    Node * right;
};

//=====================================//
Node * init_node();
Node * fill_node(Node * left, Node * right, int key);
Node * init_tree();
Node * tree_push(Node * node, int key);
void end_tree(Node * node);
//=====================================//
Node * init_tree(){
    return init_node();
}

Node * tree_push(Node * node, int key){
    if(!node)
        return fill_node(init_node(), init_node(), key);
    if(key > node->key)
        node->right = tree_push(node->right, key);
    if(key < node->key)
        node->left = tree_push(node->left, key);
    return node;
}

void end_tree(Node * node){
    if(!node)
        return;
    end_tree(node->left);
    end_tree(node->right);
    free(node);
}

void print_tree(Node * node){
    if(!node)
        return;
    printf("%d\n", node->key);
    print_tree(node->left);
    print_tree(node->right);
}

int tree_height(Node * node){
    if(!node)
        return -1;
    if(tree_height(node->left) > tree_height(node->right))
        return 1+tree_height(node->left);
    return 1+tree_height(node->right);
}

void rec_preorder(Node * node, void(*visit)(Node*)){
    if(!node)
        return;
    visit(node);
    rec_preorder(node->left, visit);
    rec_preorder(node->right, visit);
}

void rec_inorder(Node * node, void(*visit)(Node*)){
    if(!node)
        return;
    rec_inorder(node->left, visit);
    visit(node);
    rec_inorder(node->right, visit);
}

void rec_posorder(Node * node, void(*visit)(Node*)){
    if(!node)
        return;
    rec_posorder(node->left, visit);
    rec_posorder(node->right, visit);
    visit(node);
}

void iter_preorder(Node * node, int size, void(*visit)(Node*)){
    if(!node)
        return;
    Stack * stack = init_stack(size);
    stack_push(stack, node);
    
    while(!is_empty_stack(stack)){
        node = stack_pop(stack);
        visit(node);
        if(node->right)
            stack_push(stack, node->right);
        if(node->left)
            stack_push(stack, node->left);
    }
    end_stack(stack);
}

void iter_inorder(Node * node, int size, void(*visit)(Node*)){
    Stack * stack = init_stack(size);
    while(!is_empty_stack(stack) || node){
        if(node){
            stack_push(stack, node);
            node = node->left;
            continue;
        }   
        node = stack_pop(stack);
        visit(node);
        node = node->right;
    }
    end_stack(stack);
}

void iter_posorder(Node * node, int size, void(*visit)(Node*)){
    Stack * stack = init_stack(size);
    Node * lastNode, *peekNode;

    while(!is_empty_stack(stack) || node){
        if(node){
            stack_push(stack, node);
            node = node->left;
            continue;
        }
        peekNode = stack_peek(stack);
        if(peekNode->right && (lastNode != peekNode->right)){
            node = peekNode->right;
            continue;
        }
        visit(peekNode);
        lastNode = stack_pop(stack);
    }
    end_stack(stack);
}

void level_order_traversal(Node * node, int size, void(*visit)(Node*)){
    if(!node)
        return;
    Queue * queue = init_queue(size);
    enqueue(queue, node);
    while(!is_empty_queue(queue)){
        node = dequeue(queue);
        visit(node);
        if(node->left)
            enqueue(queue, node->left);
        if(node->right)
            enqueue(queue, node->right);
    }
    end_queue(queue);
}

//==================================================//
Node * init_node(){
    return NULL;
}

Node * fill_node(Node * left, Node * right, int key){
    Node * node = malloc(sizeof(Node));
    node->left = left;
    node->right = right;
    node->key = key;
    return node;
}

void print_node(Node * node){
    if(node)
        printf("%d\n", node->key);
}
