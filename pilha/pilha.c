#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pilha.h"
#define TAMANHO_TOPO 20


struct pilha{
    int topo;
    elem pilha[TAMANHO_TOPO];
};

void create(PILHA *p){
    if(p == NULL){
        p = malloc(sizeof(PILHA));
        p->topo = -1;
        printf("%p", p);
    }
}

void push(PILHA *p, elem x){
    assert(p != NULL);
    if(p->topo == (TAMANHO_TOPO -1))
        printf("pilha cheia\n");
    else{
        p->topo++;
        p->pilha[p->topo] = x;
    }
}

elem top(PILHA *p){
    assert(p != NULL);
    return p->pilha[p->topo];
}

elem pop(PILHA *p, elem x){
    assert(p != NULL);
    if(p->topo == -1){
        printf("pilha vazia\n");
        exit(1);
    }
    x = p->pilha[p->topo];
    p->topo--;
    return x;
}

bool IsEmpty(PILHA *p){
    assert(p != NULL);
    if(p->topo == -1){
        printf("pilha vazia\n");
    }
}

void esvazia_pilha(PILHA *p){
    assert(p != NULL);
    free(p);
}