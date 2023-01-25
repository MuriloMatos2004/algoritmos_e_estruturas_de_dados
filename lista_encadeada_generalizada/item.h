#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>
#include <stdlib.h>


typedef char elem;
typedef struct _item ITEM;

ITEM *criar_item(elem x);
void set_valor(ITEM *e, elem x);
elem get_valor(ITEM *e);
void apagar_item(ITEM **e);

#endif
