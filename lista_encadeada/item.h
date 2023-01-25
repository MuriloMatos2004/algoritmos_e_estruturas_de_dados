//criar item
//set valor
//get valor
//apagar item

#ifndef _ITEM_H
#define _ITEM_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tipo_item ITEM;
typedef int elem;

ITEM* criar_item(elem x);
void set_valor(ITEM* valor, elem x);
elem get_valor(ITEM* valor);
void apagar_item(ITEM **valor);

#endif