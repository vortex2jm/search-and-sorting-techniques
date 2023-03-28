#ifndef crivo_bit_h
#define crivo_bit_h

typedef struct crivobit CrivoBit;

CrivoBit * init_crivo_bit(int size);

void mark_crivo_bit(CrivoBit * crivo);

void print_primes_bit(CrivoBit * crivo);

void delete_crivo_bit(CrivoBit * crivo);

#endif
