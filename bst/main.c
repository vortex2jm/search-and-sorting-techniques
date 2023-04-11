#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"

int main(int argc, char const *argv[])
{
    int key_amount = atoi(argv[1]);

    Node * tree = init_tree();

    srand(time(NULL));
    for(int x=0; x<key_amount; x++){
        tree = tree_push(tree, rand() % 100);
    } 

    // print_tree(tree);

    printf("altura = %d\n", tree_height(tree));
    end_tree(tree);
    return 0;
}
