/*
    libera
    atomo
    sublista
    concat
    cabeca
    cauda
    imprimir
*/

#ifndef LISTAGEN_H
#define LISTAGEN_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "item.h"

typedef union info INFO;
typedef struct no NO;

union info {
    ITEM *atomo;
    NO *sublista;
};

void libera(NO *p);
NO *atomo(ITEM *atomo, int expoente);
NO *sublista(NO *sublista, int coeficente);
NO *concat(NO *p, NO *q);
INFO cabeca(NO *p, int *tipo);
NO *cauda(NO *p);
void imprimir(NO *p);
void verifica_na_listona(NO *p, int x);
void verifica_em_tudo(NO *p, int x);
int igualdade(NO *p, NO *q);
int profundidade(NO *p);
int resultado_ponlinomio(NO *p, int x, int y, int z);

#endif