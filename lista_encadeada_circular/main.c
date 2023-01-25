#include "lista.h"
#include <stdio.h>

int main(){

    LISTA *lista = criar_lista();

    inserir_elemento(lista, item_criar(1));
    inserir_elemento(lista, item_criar(3));
    inserir_elemento(lista, item_criar(5));
    inserir_elemento(lista, item_criar(2));

    imprimir_lista(lista);

    remover_elemento(lista, 3);
    printf("\n");
    imprimir_lista(lista);

    ITEM *i = buscar_elemento(lista, 1);
    item_imprimir(i);

    lista_apagar(&lista);
    imprimir_lista(lista);

    return 0;
}