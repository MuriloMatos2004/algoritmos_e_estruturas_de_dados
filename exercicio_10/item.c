#include "item.h"
#include <stdlib.h>

struct item{
    int info;
};

ITEM *item_criar(int x){
    ITEM *i = malloc(sizeof(ITEM));
    if(i == NULL) return NULL;

    i->info = x;

    return i;
}

bool apagar_item(ITEM **i){
    if(i == NULL) return false;
    if(*i == NULL) return false;

    free(*i);
    *i = NULL;
    return true;
}

int valor_item(ITEM *i){
    if(i != NULL) return i->info;
}

bool muda_valor_item(ITEM *i, int y){
    if(i == NULL) return false;

    i->info = y;

    return true;
}

