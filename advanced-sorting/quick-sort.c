#include "item.h"
#include <stdlib.h>
#include <sys/time.h>
#define CUTOFF  10

// Prototypes =====================//
void shuffle(Item *a, int N);
void quick_sort(Item *a, int lo, int hi);
int partition(Item *a, int lo, int hi);
void sort(Item *a, int lo, int hi);

// Implementation =================//
void sort(Item *a, int lo, int hi)
{
    // shuffle(a, hi-lo+1); // Needed for performance guarantee.
    quick_sort(a, lo, hi);
}

//======================================//
void quick_sort(Item *a, int lo, int hi)
{
    if (hi <= lo)
        return;

    int j = partition(a, lo, hi);
    quick_sort(a, lo, j - 1);
    quick_sort(a, j + 1, hi);
}

//=========================//
// + CUTOFF
//=========================//
// void insertion_sort(Item *a, int lo, int hi)
// {
	// for (int x = lo + 1; x <= hi; x++)
	// {
		// for (int y = x; y >= lo; y--)
		// {
			// compexch(a[y-1], a[y]);
		// }
	// }
// }
// 
// void quick_sort(Item *a, int lo, int hi)
// {
    // if (hi <= lo + CUTOFF -1)
    // {
        // insertion_sort(a, lo, hi);        
        // return;
    // }
// 
    // int j = partition(a, lo, hi);
    // quick_sort(a, lo, j - 1);
    // quick_sort(a, j + 1, hi);
// }

//===================================//
int partition(Item *a, int lo, int hi)
{
    int i = lo, j = hi + 1;
    Item v = a[lo];
    while (1)
    {
        while (less(a[++i], v)) // Find item on left to swap.
            if (i == hi)
                break;
        while (less(v, a[--j])) // Find item on right to swap.
            if (j == lo)
                break;
        if (i >= j)
            break; // Check if pointers cross.
        exch(a[i], a[j]);
    }
    exch(a[lo], a[j]); // Swap with partitioning item.

    return j; // Return index of item known to be in place.
}

//=========================//
void shuffle(Item *a, int N)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand48(tv.tv_usec);
    //
    for (int i = N - 1; i > 0; i--)
    {
        int j = (unsigned int)(drand48() * (i + 1));
        exch(a[i], a[j]);
    }
}
