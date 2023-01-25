#ifndef _AB_H_
#define _AB_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "item.h"

typedef struct no no_t;
typedef struct ab ab_t;

ab_t *cria();
int esta_vazia(ab_t *A);
void finaliza(ab_t *A);
void imprime(ab_t *A);
int altura(ab_t *A);
no_t *busca_pai(ab_t *A, elem x);
no_t *busca(ab_t *A, elem x);
bool insere_esq(ab_t *A, elem x, elem pai);
bool insere_dir(ab_t *A, elem x, elem pai);
bool remover(ab_t *A, elem x);

void pre_ordem(ab_t *A);
void em_ordem(ab_t *A);
void pos_ordem(ab_t *A);
void em_ordem_iterativo(ab_t *A);

#endif