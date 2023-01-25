#include "item.h"

struct tipo_item{
    elem item;
};

ITEM *criar_item(elem x){
    ITEM *i = malloc(sizeof(ITEM));
    if(i == NULL) return NULL;

    i->item = x;

    return i;
}

void set_valor(ITEM* valor, elem x){
    if(valor == NULL) exit(1);

    valor->item = x;
}

elem get_valor(ITEM* valor){
    if(valor == NULL) exit(1);

    return valor->item;
}

void apagar_item(ITEM **valor){
    if(valor != NULL && *valor != NULL){
        free(*valor);
        *valor = NULL;
    }
    else printf("sem item");
}