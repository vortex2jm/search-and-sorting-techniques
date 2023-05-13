#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{   
    int amount = atoi(argv[1]);
    int range = atoi(argv[2]);

    srand(time(NULL));
    
    for(int x=0; x<amount; x++){
        printf("%d\n", rand() % range);    
    }

    return 0;
}
