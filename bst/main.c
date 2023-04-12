#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"

int main(int argc, char const *argv[])
{   
    // Values amount to insert
    int key_amount = atoi(argv[1]);

    // Initializing null tree
    Node * tree = init_tree();

    // Filling tree with random values
    srand(time(NULL));
    int random=0;
    for(int x=0; x<key_amount; x++){
        random = rand() % 100;
        tree = tree_push(tree, random);
        printf("%d ", random);
    }
    printf("\n"); 

    clock_t rpre_start, rpre_end, ipre_start, ipre_end;
    clock_t rin_start, rin_end, iin_start, iin_end;
    clock_t rpos_start, rpos_end, ipos_start, ipos_end;
    clock_t lv_order_start, lv_order_end;

    // Crossing the tree recursively in different orders
    printf("Pre-order recursive:\n");
    rpre_start = clock();
    rec_preorder(tree, print_node);
    rpre_end = clock();

    printf("In-order recursive:\n");
    rin_start = clock();
    rec_inorder(tree, print_node);
    rin_end = clock();

    printf("Pos-order recursive:\n");
    rpos_start = clock();
    rec_posorder(tree, print_node);
    rpos_end = clock();

    // Crossing the tree iterately in different orders
    printf("Pre-order iterative:\n");
    ipre_start = clock();
    iter_preorder(tree, key_amount, print_node);
    ipre_end = clock();
    
    printf("In-order iterative:\n");
    iin_start = clock();
    iter_inorder(tree, key_amount, print_node);
    iin_end = clock();
    
    printf("Pos-order iterative:\n");
    ipos_start = clock();
    iter_posorder(tree, key_amount, print_node);
    ipos_end = clock();

    printf("Level-order iterative:\n");
    lv_order_start = clock();
    level_order_traversal(tree, key_amount, print_node);
    lv_order_end = clock();

    // Calculating times
    double rpre_time, rin_time, rpos_time;
    double ipre_time, iin_time, ipos_time;
    double lv_order_time;

    rpre_time = ((double)rpre_end - rpre_start)/CLOCKS_PER_SEC;
    rin_time = ((double)rin_end - rin_start)/CLOCKS_PER_SEC;
    rpos_time = ((double)rpos_end - rpos_start)/CLOCKS_PER_SEC;

    ipre_time = ((double)ipre_end - ipre_start)/CLOCKS_PER_SEC;
    iin_time = ((double)iin_end - iin_start)/CLOCKS_PER_SEC;
    ipos_time = ((double)ipos_end - ipos_start)/CLOCKS_PER_SEC;
    
    lv_order_time = ((double)lv_order_end - lv_order_start)/CLOCKS_PER_SEC;

    printf("recursive pre-order time: %lf seconds\n", rpre_time);
    printf("recursive in-order time: %lf seconds\n", rin_time);
    printf("recursive pos-order time: %lf seconds\n", rpos_time);
    printf("iterative pre-order time: %lf seconds\n", ipre_time);
    printf("iterative in-order time: %lf seconds\n", iin_time);
    printf("iterative pos-order time: %lf seconds\n", ipos_time);
    printf("iterative lv_order time: %lf seconds\n", lv_order_time);

    // Printing height
    printf("height = %d\n", tree_height(tree));
    
    // Deallocating memory 
    end_tree(tree);
    return 0;
}
