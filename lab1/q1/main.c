#include <stdio.h>
#include <stdlib.h>
#include "crivo-int.h"

int main(int argc, char const *argv[])
{
    int size = atoi(argv[1]);

    CrivoInt * crivo = init_crivo(size);
    mark_crivo(crivo);
    print_primes(crivo);
    delete_crivo(crivo);

    return 0;
}
