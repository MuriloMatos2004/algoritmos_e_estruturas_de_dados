#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
    PILHA *p;
    printf("%p\n", p);
    create(p);
    printf("\n%p", p);
    //push(p, 1);
    //printf("%d", top(p));

    return 0;
}