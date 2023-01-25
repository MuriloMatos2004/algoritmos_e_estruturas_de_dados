#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    LISTA *lista = criar_lista();

    inserir_elemento(lista, 1);
    inserir_elemento(lista, 4);
    inserir_elemento(lista, 7);
    inserir_elemento(lista, 3);
    inserir_elemento(lista, 2);

    imprimir_lista(lista);
    imprimir_lista_inversamente(lista);

    remover_elemento(lista, 3);
    imprimir_lista(lista);

    int v = buscar_elemento(lista, 4);

    printf("%d \n", v);
    liberar_lista(&lista);
    imprimir_lista(lista);



    return 0;
}