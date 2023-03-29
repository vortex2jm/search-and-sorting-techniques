#include <stdio.h>
#include <stdlib.h>
#include "crivo-int.h"
#include "crivo-bit.h"

int main(int argc, char const *argv[])
{
    int size = atoi(argv[1]);

    CrivoInt * crivo = init_crivo(size);
    mark_crivo(crivo);
    print_primes(crivo);
    delete_crivo(crivo);

    CrivoBit * crivobit = init_crivo_bit(size);
    mark_crivo_bit(crivobit);
    print_primes_bit(crivobit);
    delete_crivo_bit(crivobit);

    return 0;
}
