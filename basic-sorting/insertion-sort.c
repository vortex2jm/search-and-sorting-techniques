#include "item.h"
#include <stdio.h>

void sort(Item *a, int lo, int hi)
{
	for (int x = lo + 1; x <= hi; x++)
	{
		for (int y = x; y >= lo; y--)
		{
			compexch(a[y-1], a[y]);
		}
	}
}
