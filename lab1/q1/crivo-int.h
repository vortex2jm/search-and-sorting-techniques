#ifndef crivo_h
#define crivo_h

typedef struct crivoint CrivoInt;

CrivoInt * init_crivo(int size);

void mark_crivo(CrivoInt * crivo);

void print_primes(CrivoInt * crivo);

void delete_crivo(CrivoInt * crivo);

#endif
