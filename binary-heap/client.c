#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(int argc, char const *argv[])
{
  Heap * h = init_pq(10);

  printf("heap size = %d\n", pq_size(h));
  pq_insert(h, 28);
  pq_insert(h, 89);
  pq_insert(h, 102);
  pq_insert(h, 45);

  printf("heap size = %d\n", pq_size(h));
  Item a = pq_delmax(h);

  printf("Item retirado da fila = %d\n", a);
  printf("heap size = %d\n", pq_size(h));
  printf("Agora o maior item da fila eh = %d\n", pq_max(h));
  
  end_pq(h);
  
  return 0;
}
