// This implementation uses global variables
#include <stdio.h>
#include "quick-union.h"

static int id[1000];
static int N;

// Prototypes
int find(int index);
void init(int size);

// Implementation
int find(int index){
    while(index != id[index]){
        index = id[index];
    }
    return index;
}

void init(int size){
    N = size;
    for(int x=0; x<size; x++){
        id[x] = x;
    }    
}

bool connected(int index1, int index2){
    return find(index1) == find(index2);
}

void unnion(int index1, int index2){
    int p_root = find(index1);
    int q_root = find(index2);
    id[p_root] = q_root; 
}
