#ifndef tree_h
#define tree_h

typedef struct node Node;

Node * init_tree();
Node * tree_push(Node * node, int key);
int tree_height(Node * node);
void print_tree(Node * node);
void end_tree(Node * node);

#endif
