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
    clock_t start_sort = clock();
    sort(array, 0, n-1);
    clock_t end_clock = clock();

    //==========================//
    // for(int x=0; x<n; x++){
        // printf("%d\n", array[x]);
    // }

    double sort_time = ((double)end_clock - start_sort)/CLOCKS_PER_SEC;
    printf("Tempo de ordenacao: %lf\n", sort_time);
    //============// 
    free(array);
    return 0;
}
