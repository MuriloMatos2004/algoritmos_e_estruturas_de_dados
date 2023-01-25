#include <stdio.h>
#include <stdlib.h>

typedef int elem;
typedef struct item ITEM;

ITEM *criar_item(elem x);
void set_valor(ITEM *e, elem x);
elem get_valor(ITEM *e);
void apagar_item(ITEM **e);