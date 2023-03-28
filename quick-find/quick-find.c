#include "quick-find.h"
#include <stdio.h>

// This implementation uses global variables
static int id[1000];
static int N;

// Prototypes
void init(int size);
int find(int index);
bool connected(int index1, int index2);
void unnion(int index1, int index2);

// Implementation
void init(int size){
    N = size;
    for(int x=0; x<size; x++){
        id[x] = x;
    }
}

int find(int index){
    return id[index];
}

bool connected(int index1, int index2){
    return find(index1) == find(index2);
}

void unnion(int index1, int index2){
    int pid = find(index1);
    int qid = find(index2);
    
    for(int x=0; x<N; x++){
        if(id[x] == pid){
            id[x] = qid;
        }
    }
}
