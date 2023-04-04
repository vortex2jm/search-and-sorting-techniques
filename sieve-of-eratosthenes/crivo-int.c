#include <stdio.h>
#include <stdlib.h>
#include "crivo-int.h"

struct crivoint {
    int * crivo;
    int size;
};

// Prototypes
CrivoInt * init_crivo(int size);

// Implementation
CrivoInt * init_crivo(int size){
    CrivoInt * crivo = malloc(sizeof(CrivoInt));
    crivo->size = size;    
    crivo->crivo = malloc(sizeof(int)*size);

    for(int x=0; x<size; x++){
        crivo->crivo[x] = x+2;
    }
    
    return crivo;
}

void mark_crivo(CrivoInt * crivo){
    for(int x=0; x<crivo->size; x++){
        if(crivo->crivo[x]){
            for(int y=x+1; y<crivo->size; y++){
                if(!(crivo->crivo[y]%crivo->crivo[x])){
                    crivo->crivo[y] = 0;
                }
            }
        }    
    }    
}

void print_primes(CrivoInt * crivo){
    for(int x=0; x<crivo->size; x++){
        if(crivo->crivo[x] != 0){
            printf("%d ", crivo->crivo[x]);
        }
    }
    printf("\n");
}

void delete_crivo(CrivoInt * crivo){
    if(crivo){
        if(crivo->crivo){
            free(crivo->crivo);
        }
        free(crivo);
    }
}
