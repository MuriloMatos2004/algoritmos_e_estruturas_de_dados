#include "item.h"

struct item_{
    char elemento;
};

ITEM *item_criar(char chave){
    ITEM *p = malloc(sizeof(ITEM));
    p->elemento = chave;
    return p;
}

bool item_apagar(ITEM **item){
    if(item != NULL && *item != NULL){
        free(*item);
        *item = NULL;
        return true;
    }
    return false;
}
/*i = 1 
  *p = &i
  **item = &p
  *item -> &i
*/
void item_imprimir(ITEM *item){
    printf("%c\n", item->elemento);
}

int item_get_chave(ITEM *item){
    if(item == NULL){
        printf("item nao exite\n");
        exit(1);
    }
    //printf("%c: %d\n", item->elemento, (int)item->elemento);
    return item->elemento;
}

bool item_set_chave(ITEM *item, char chave){
    if(item == NULL)
        return false;
    item->elemento = chave;
    return true;
}