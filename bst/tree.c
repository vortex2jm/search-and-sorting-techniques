#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

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
