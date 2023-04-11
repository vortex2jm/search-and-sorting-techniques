#ifndef tree_h
#define tree_h

typedef struct node Node;

Node * init_tree();
Node * tree_push(Node * node, int key);
int tree_height(Node * node);
void rec_preorder(Node * node, void(*visit)(Node*));
void rec_inorder(Node * node, void(*visit)(Node*));
void rec_posorder(Node * node, void(*visit)(Node*));
void iter_preorder(Node * node, int size, void(*visit)(Node*));
void iter_inorder(Node * node, int size, void(*visit)(Node*));
void iter_posorder(Node * node, int size, void(*visit)(Node*));
void level_order_traversal(Node * node, int size, void(*visit)(Node*));
void print_node(Node * node);
void print_tree(Node * node);
void end_tree(Node * node);

#endif
