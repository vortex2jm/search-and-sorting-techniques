#ifndef heap_h
#define heap_h
#include "item.h"
#include <stdbool.h>

typedef struct heap Heap;

Heap *init_pq(int size);

void end_pq(Heap *pq);

void pq_insert(Heap *pq, Item item);

Item pq_delmax(Heap *pq);

Item pq_max(Heap *pq);

bool is_empty_pq(Heap *pq);

int pq_size(Heap *pq);

#endif // !heap_hf
