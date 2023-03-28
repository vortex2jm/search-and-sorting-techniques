// Quick find
#include <stdio.h>
#include <stdlib.h>
#include "quick-find.h"

int main(int argc, char const *argv[])
{
    int p, q, N = atoi(argv[1]);
    
    init(N);

    while(scanf("%d %d", &p, &q) == 2){
        if(!connected(p, q)){
            unnion(p,q);
            printf("%d %d\n",p, q);
        }
    }
    return 0;
}
