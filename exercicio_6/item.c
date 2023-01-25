#include "item.h"
#include <stdio.h>
#include <stdlib.h>

struct item_{
    int valor;
};

ITEM *item_criar(int chave){
    ITEM *i = malloc(sizeof(ITEM));

    if(i == NULL) return NULL;

    i->valor = chave;
    return i;
}

bool item_apagar(ITEM **item){
    if(item != NULL && *item != NULL){
        free(*item);
        *item = NULL;
        return true;
    }
    return false;
}

void item_imprimir(ITEM *item){
    if(item == NULL) exit(1);

    printf("%d\n", item->valor);
}


int item_get_chave(ITEM *item){
    if(item == NULL) return 0;

    return item->valor;
}

bool item_set_chave(ITEM *item, int chave){
    if(item == NULL) return false;

    item->valor = chave;
    return true;    
}

