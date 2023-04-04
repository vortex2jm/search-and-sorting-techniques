#include "item.h"

void sort(Item *a, int lo, int hi)
{
	if(!hi) return;
    for(int x=lo; x<hi; x++){
        compexch(a[x], a[x+1]);
    }
    sort(a, lo, hi-1);
}
