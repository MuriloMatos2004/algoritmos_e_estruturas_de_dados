#include "item.h"
#include <stdio.h>

int main(){

    ITEM* i = criar_item(1);

    printf("item: %d\n", get_valor(i));

    set_valor(i, 2);

    printf("item: %d\n", get_valor(i));

    apagar_item(&i);

    apagar_item(&i);


    return 0;
}

