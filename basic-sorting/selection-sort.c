#include "item.h"
#include <stdio.h>

void sort(Item *a, int lo, int hi)
{
    int minor = 0, aux = 0, index = 0;
    for (int x = lo; x < hi; x++)
    {
        minor = a[x];
        index = x;
        for (int y = x + 1; y <= hi; y++)
        {
            if (less(a[y], minor))
            {
                minor = a[y];
                index = y;
            }
        }
        exch(a[x], a[index]);
    }
}
