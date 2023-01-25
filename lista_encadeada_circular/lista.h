//criar/liberar lista
//inserir elemento (ordenado)
//remover elemento
//buscar elemento
//imprimir lista
//lista cheia 
//lista vazia

#ifndef _LISTA_H
    #define _LISTA_H

    typedef struct lista LISTA;
    #define TAM_MAX 10

    #include "item.h"
    #include <stdbool.h>

    LISTA *criar_lista();
    bool lista_cheia(LISTA *l);
    bool lista_vazia(LISTA *l);
    bool inserir_elemento(LISTA *l, ITEM *x);
    bool remover_elemento(LISTA *l, int x);
    ITEM *buscar_elemento(LISTA *l, int x);
    void imprimir_lista(LISTA *l);
    bool lista_apagar(LISTA **l);

#endif



