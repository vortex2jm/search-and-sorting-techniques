#include "item.h"
#include <stdlib.h>
#define CUTOFF 10

void merge_sort(Item *a, Item *aux, int lo, int hi);

void sort(Item *a, int lo, int hi){
    int n = (hi - lo) + 1;
    Item *aux = malloc(sizeof(Item) * n);
    merge_sort(a, aux, lo, hi);
    free(aux);
}

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

void merge_sort(Item *a, Item *aux, int lo, int hi){
    if (hi <= lo) return;
    int mid = lo + (hi - lo) / 2; // Avoid overflow.

    merge_sort(a, aux, lo, mid);
    merge_sort(a, aux, mid+1, hi);
    merge(a, aux, lo, mid, hi);
}

// =====================================================
// MERGE SORT WITH CUT OFF
// =====================================================
/*
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
// 
void merge_sort(Item *a, Item *aux, int lo, int hi){
    if (hi <= lo + CUTOFF + 1){
        insertion_sort(a, lo, hi);
        return;
    }
// 
    int mid = lo + (hi - lo) / 2; // Avoid overflow.
    merge_sort(a, aux, lo, mid);
    merge_sort(a, aux, mid+1, hi);
    merge(a, aux, lo, mid, hi);
}
*/

// =================================================
// MERGE SORT WITH MERGE SKIP
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
