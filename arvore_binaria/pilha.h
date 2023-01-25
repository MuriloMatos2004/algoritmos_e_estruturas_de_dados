#ifndef PILHA_H
#define PILHA_H

typedef struct tipo_pilha PILHA;

#include <stdbool.h>
#include "ab.h"

PILHA *criar_pilha();
bool insere_na_pilha(no_t *i, PILHA *p);
no_t *remover_da_pilha(PILHA *p);
bool destroi_pilha(PILHA **p);

#endif