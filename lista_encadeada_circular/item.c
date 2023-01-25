#include "item.h"
#include <stdlib.h>
#include <stdio.h>


struct item_ {
    int elemento;
};


ITEM *item_criar(int chave){
    ITEM *i = malloc(sizeof(ITEM));
    if(i == NULL){
        return NULL;
    }
    i->elemento = chave;
    return i;
}

bool item_apagar(ITEM **item){
    if(item == NULL)
        return false;
    if(*item == NULL)
        return false;
    free(*item);
    *item = NULL;

    return true;
}

void item_imprimir(ITEM *item){
    if(item == NULL)
        exit(1);
    printf("%d\n", item->elemento);
}

int item_get_chave(ITEM *item){
    if(item == NULL) exit(1);
    
    return item->elemento;
}

bool item_set_chave(ITEM *item, int chave){
    if(item == NULL)
        return false;
    item->elemento = chave;
    return true;
}