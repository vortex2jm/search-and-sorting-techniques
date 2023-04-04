#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"

extern void sort(Item *a, int lo, int hi);

int main(int argc, char const *argv[])
{
    //==========================//
    int n = atoi(argv[1]);    
    int * array = malloc(sizeof(int)*n);

    //==========================//
    for(int x=0; x<n; x++){
        scanf("%d", &array[x]);
    }

    //==========================//
    sort(array, 0, n-1);

    //==========================//
    for(int x=0; x<n; x++){
        printf("%d\n", array[x]);
    }

    //============// 
    free(array);
    return 0;
}

