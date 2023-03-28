#include <stdio.h>
#include <stdlib.h>
#include "crivo-bit.h"

struct crivobit {
    unsigned char * crivo;
    int offset;
    int size;
    int range;
};

// Prototypes
CrivoBit * init_crivo_bit(int size);

// Implementation
CrivoBit * init_crivo_bit(int size){
    CrivoBit * crivo = malloc(sizeof(CrivoBit));    
    crivo->size = size;
    
    // Range and offset
    int range = size/8;
    if(!range){
        range = 1;
        crivo->offset = 8 - size;
    } 
    else {
        crivo->offset = size % 8; 
    }
    crivo->range = range;

    // crivo
    crivo->crivo = malloc(sizeof(char) * crivo->range);
    for(int x=0; x<crivo->range; x++){
        crivo->crivo[x] = 0;
    }

    return crivo;
}

// ============================================== //
void mark_crivo_bit(CrivoBit * crivo){
    unsigned char one = 1;
    unsigned char result_byte = 7 << one;
    crivo->crivo[0] = 0 | result_byte;

    int range, shift;

    for(int x=2; x<crivo->size; x++){
        for(int y=x+1; y<crivo->size; y++){
            if(!(y%x)){
                
                range = y/8;
                shift = 0;
                if(y%8){
                    range++;
                    shift = 7 - y%8;
                } 

                result_byte = shift << one;
                crivo->crivo[range] = crivo->crivo[range] | result_byte;
            }
        }
    }    
}

// ============================================== //
void print_primes_bit(CrivoBit * crivo){
}

// ============================================== //
void delete_crivo_bit(CrivoBit * crivo){
}
