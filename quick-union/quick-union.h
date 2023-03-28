#ifndef qu_h
#define qu_h
#include <stdbool.h>

void init(int size);

int find(int index);

bool connected(int index1, int index2);

void unnion(int index1, int index2);

#endif
