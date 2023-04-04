#include "item.h"
#include <stdbool.h>

void sort(Item *a, int lo, int hi)
{
	bool swap;
	while (true)
	{
		swap = false;
		for (int x = lo; x < hi; x++)
		{
			if (less(a[x + 1], a[x]))
			{
				swap = true;
				exch(a[x + 1], a[x]);
			}
		}
		hi--;
		if (!swap)
			break;
	}
}
