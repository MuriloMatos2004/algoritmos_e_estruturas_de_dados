#ifndef _LISTA_H
#define _LISTA_H

#include <stdbool.h>
#include "item.h"

typedef struct lista LISTA;
typedef struct no NO;

LISTA *cria_lista();
void libera_lista(LISTA **l);
void insere(LISTA *l, ITEM *x);
int tamanho(LISTA *l);
bool esta_na_lista(LISTA *l, elem x);
void imprimir(LISTA *l);
void remover(LISTA *l, elem x);


#endif