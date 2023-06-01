#include "heap.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>

struct heap {
  Item *pq;
  int size;
};

// public functions
Heap *init_pq(int size);
void end_pq(Heap *heap);
void pq_insert(Heap *heap, Item item);
Item pq_delmax(Heap *heap);
Item pq_max(Heap *heap);
bool is_empty_pq(Heap *heap);
int pq_size(Heap *heap);

// private functions
void fix_up(Item *pq, int k);
void fix_down(Item *pq, int size, int k);

// Implementation
//==============================//
void fix_up(Item *pq, int k) {
  while (k > 1 && less(pq[k / 2], pq[k])) {
    exch(pq[k], pq[k / 2]);
    k = k / 2;
  }
}

//==============================//
void fix_down(Item *pq, int size, int k){
  int j;
  while(2*k <= size){
    j=2*k;
    if(j<size && less(pq[j], pq[j+1]))
      j++;
    if(!less(pq[k], pq[j]))
      break;
    exch(pq[k], pq[j]);
    k=j;
  }
}

//======================//
Heap *init_pq(int size){
  Heap * h = malloc(sizeof(Heap));
  h->pq = malloc(sizeof(Item) * size);
  h->size = 0;
  return h;
}

//====================================//
void pq_insert(Heap *heap, Item item) {

  if(!heap)
    perror("Could not add item to unexisting heap!\n");

  heap->size++;
  heap->pq[heap->size] = item;
  fix_up(heap->pq, heap->size);
}

Item pq_delmax(Heap *heap){
  Item max = heap->pq[1];
  exch(heap->pq[1], heap->pq[heap->size]);
  heap->size--;
  fix_down(heap->pq, heap->size, 1);
  return max;
}

//===================================//
Item pq_max(Heap *heap){
  if(!heap || !heap->size)
    perror("Empty heap\n");
  return heap->pq[1];
}

//====================//
int pq_size(Heap *heap){
  if(!heap)
    perror("Could not read size of unexisting heap!\n");
  return heap->size;
}

//==========================//
bool is_empty_pq(Heap *heap){
  if(!heap)
    perror("Could not read unexisting heap!\n");
  return (heap->size==0);
}

//==========================//
void end_pq(Heap *heap){
  if(heap){
    if(heap->pq)
      free(heap->pq);
    free(heap);
  }
}
