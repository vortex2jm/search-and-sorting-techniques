#include <stdio.h>
#include <stdlib.h>
#include "crivo-bit.h"

struct crivobit {
    unsigned char * crivo;
    int offset;
    int size;
    int range;
};

// ============================================== //
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
        if(crivo->offset){
            range++;
        } 
    }
    crivo->range = range;

    // crivo
    crivo->crivo = malloc(sizeof(unsigned char) * crivo->range);
    for(int x=0; x<crivo->range; x++){
        crivo->crivo[x] = 0;
    }

    return crivo;
}

// ============================================== //
void mark_crivo_bit(CrivoBit * crivo){
    unsigned char one = 1;
    unsigned char result_byte=0;
    unsigned int range, shift;

    for(int x=2; x<crivo->size+2; x++){
        for(int y=x+1; y<crivo->size+2; y++){
            if(!(y%x)){
                if((y-2) < 8){
                    range = 0;
                    shift = 7 - (y-2);
                } else {
                    range = ((y-2)/8);
                    shift = 7 - ((y-2)%8);
                }

                result_byte = one << shift;
                crivo->crivo[range] = crivo->crivo[range] | result_byte;
            }
        }
    }
    for(int x=0; x<crivo->range; x++){
        crivo->crivo[x] = ~crivo->crivo[x];
    }    
}

// ============================================== //
void print_primes_bit(CrivoBit * crivo){
    int bit_index = 2;
    unsigned char one = 1, mask = 0;

    for(int x=0; x<crivo->range; x++){
        for(int y=7; y>=0; y--){
            
            if((x == (crivo->range - 1)) && (y == 7-crivo->offset) && (y != 7)) break;
            mask = one << y;
            int u = crivo->crivo[x] & mask;

            if(crivo->crivo[x] & mask){
                printf("%d ", bit_index);
            }
            bit_index++;
        }
    }
    printf("\n");
}

// ============================================== //
void delete_crivo_bit(CrivoBit * crivo){
    if(crivo){
        if(crivo->crivo){
            free(crivo->crivo);
        }
        free(crivo);
    }
}
