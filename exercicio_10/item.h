#ifndef ITEM_H
#define ITEM_h

typedef struct item ITEM;
#include <stdbool.h>

ITEM *item_criar(int x);
bool apagar_item(ITEM **i);
int valor_item(ITEM *i);
bool muda_valor_item(ITEM *i, int y);


#endif