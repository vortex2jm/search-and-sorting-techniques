#include "item.h"
#include <stdlib.h>
#define CUTOFF 10
#define SZ2 (sz + sz)
#define MIN(X,Y) ((X < Y) ? (X) : (Y))

void merge_sort(Item *a, Item *aux, int lo, int hi);
void merge(Item *a, Item *aux, int lo, int mid, int hi);
void insertion_sort(Item *a, int lo, int hi);

// =====================================================
// MERGE SORT TOP-DOWN RECURSIVE
// =====================================================
void sort(Item *a, int lo, int hi){
    int n = (hi - lo) + 1;
    Item *aux = malloc(sizeof(Item) * n);
    merge_sort(a, aux, lo, hi);
    free(aux);
}

// =====================================================
// MERGE SORT BOTTOM-UP ITERATIVE
// =====================================================
/*
void sort(Item *a, int lo, int hi){
    int N = (hi - lo) + 1;
    int y = N - 1;

    Item *aux = malloc(N * sizeof(int));

    for(int sz=1; sz < N; sz = SZ2){
        for(int lo=0; lo < N-sz; lo += SZ2){
            int x = lo + SZ2 - 1;
            merge(a, aux, lo, lo+sz-1, MIN(x,y));
        }
    }
    free(aux);
}
*/

// =====================================================
// MERGE SORT BOTTOM-UP + CUTOFF
// =====================================================
/*
void sort(Item *a, int lo, int hi){
    int N = (hi - lo) + 1;
    int y = N - 1;

    Item *aux = malloc(N * sizeof(int));

    for(int sz=1; sz < N; sz = SZ2){
        for(int lo=0; lo < N-sz; lo += SZ2){
        
            int x = lo + SZ2 - 1;
            
            if(sz < CUTOFF){
                insertion_sort(a, lo, MIN(x,y));
            }
            
            merge(a, aux, lo, lo+sz-1, MIN(x,y));
        }
    }
    free(aux);
}
*/

// =====================================================
// SIMPLE MERGE SORT TOP-DOWN
// =====================================================
/*
void merge_sort(Item *a, Item *aux, int lo, int hi){
    if (hi <= lo) return;
    int mid = lo + (hi - lo) / 2; // Avoid overflow.

    merge_sort(a, aux, lo, mid);
    merge_sort(a, aux, mid+1, hi);
    merge(a, aux, lo, mid, hi);
}
*/

// =====================================================
// MERGE SORT TOP-DOWN WITH CUT OFF
// =====================================================
/*
void merge_sort(Item *a, Item *aux, int lo, int hi){
    if (hi <= lo + CUTOFF + 1){
        insertion_sort(a, lo, hi);
        return;
    }

    int mid = lo + (hi - lo) / 2; // Avoid overflow.
    merge_sort(a, aux, lo, mid);
    merge_sort(a, aux, mid+1, hi);
    merge(a, aux, lo, mid, hi);
}
*/

// =================================================
// MERGE SORT TOP-DOWN WITH MERGE SKIP
// =================================================
/*
void merge_sort(Item *a, Item *aux, int lo, int hi){
    if (hi <= lo) return;
    int mid = lo + (hi - lo) / 2; // Avoid overflow.
 
    merge_sort(a, aux, lo, mid);
    merge_sort(a, aux, mid+1, hi);
    if(!less(a[mid+1], a[mid])) return;
    merge(a, aux, lo, mid, hi);
}
*/

// =================================================
// MERGE SORT TOP-DOWN WITH MERGE SKIP AND CUTOFF
// =================================================

void merge_sort(Item *a, Item *aux, int lo, int hi){
    if (hi <= lo + CUTOFF + 1){
        insertion_sort(a, lo, hi);
        return;
    }

    int mid = lo + (hi - lo) / 2; // Avoid overflow.
 
    merge_sort(a, aux, lo, mid);
    merge_sort(a, aux, mid+1, hi);
    if(!less(a[mid+1], a[mid])) return;
    merge(a, aux, lo, mid, hi);
}


// Auxiliar function to use in cutoff
void insertion_sort(Item *a, int lo, int hi)
{
	for (int x = lo + 1; x <= hi; x++)
	{
		for (int y = x; y >= lo; y--)
		{
			compexch(a[y-1], a[y]);
		}
	}
}

// Used by all functions
void merge(Item *a, Item *aux, int lo, int mid, int hi){
    for (int k = lo; k <= hi; k++)
        aux[k] = a[k]; // Copy array
    
    int i = lo, j = mid+1;
    for (int k = lo; k <= hi; k++) { // Merge
        if (i > mid) a[k] = aux[j++];
        else if (j > hi) a[k] = aux[i++];
        else if (less(aux[j], aux[i])) a[k] = aux[j++];
        else a[k] = aux[i++];
    }
}
