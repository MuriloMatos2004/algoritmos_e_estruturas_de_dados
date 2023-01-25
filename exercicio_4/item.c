#include "item.h"
#include <stdlib.h>
#include <stdio.h>


struct item_ {
    float elemento;
};


ITEM *item_criar(float chave){
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
    printf("%f\n", item->elemento);
}

float item_get_chave(ITEM *item){
    if(item == NULL)
        exit(1);
    
    return item->elemento;
}

bool item_set_chave(ITEM *item, float chave){
    if(item == NULL)
        return false;
    item->elemento = chave;
    return true;
}