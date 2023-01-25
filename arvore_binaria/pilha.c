#include "pilha.h"
#include <stdlib.h>

typedef struct elementos_pilha EP;

struct elementos_pilha{
    no_t *info;
    EP *ant, *prox;
};

struct tipo_pilha{
    EP *fim;
};


PILHA *criar_pilha(){
   PILHA *p = malloc(sizeof(PILHA));
   if(p == NULL) return NULL;

   p->fim = NULL;

   return p;
}

bool insere_na_pilha(no_t *i, PILHA *p){
    if(p == NULL) return false;
    if(p->fim == NULL){
        EP *j = malloc(sizeof(EP));
        p->fim = j;
        
        p->fim->info = i;
        p->fim->ant = NULL;
        p->fim->prox = NULL;
        return true;
    }
    EP *aux = malloc(sizeof(EP));
    aux->info = i;
    p->fim->prox = aux;
    aux->ant = p->fim;
    p->fim = aux;

    return true;
}

no_t *remover_da_pilha(PILHA *p){
    if(p == NULL) return NULL;

    if(p->fim == NULL){
        printf("pilha vazia");
        return NULL;
    }

    no_t *no_removido = p->fim->info;

    p->fim = p->fim->ant;

    return no_removido;
}

bool destroi_pilha(PILHA **p){
    if(*p == NULL) return false;
    if( p == NULL) return false;

    free(*p);
    *p = NULL;
    return true;
}
