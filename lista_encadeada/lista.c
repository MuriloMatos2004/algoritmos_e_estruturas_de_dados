#include "lista.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>

struct no{
    ITEM *info;
    NO *prox;
};

struct lista{
    NO *ini, *fim;
    int total;
};

LISTA *cria_lista(){
    LISTA *l = malloc(sizeof(LISTA));

    if(l == NULL) return NULL;

    l->ini = NULL;
    l->fim = NULL;
    l->total = 0;

    return l;
}

void libera_lista(LISTA **l){
    if(l != NULL && *l != NULL){
        NO *p = (*l)->ini;

        while(p != NULL){
            (*l)->ini = (*l)->ini->prox;
            apagar_item(&(p->info));
            free(p);
            p = (*l)->ini;
        }
        (*l)->fim = NULL;
        free(*l);
        l = NULL;
    }
}

void insere(LISTA *l, ITEM *x){
    if(l == NULL) return NULL;

    NO *p = malloc(sizeof(NO));
    if(p == NULL) return NULL;

    if(l->ini == NULL) l->ini = p;
    else l->fim->prox = p;
    
    l->fim = p;
    l->total++;
}

int tamanho(LISTA *l){
    if(l == NULL) return 0;

    return l->total;
}

bool esta_na_lista(LISTA *l, elem x){
    if(l == NULL) return NULL;

    NO *p = l->ini;

    while(p != NULL){
        if(get_valor(p->info) == x) true;
        p = p->prox;
    }
    return false;
}

void imprimir(LISTA *l){
    if(l == NULL) return NULL;

    NO *p = l->ini;

    while(p != NULL){
        printf("%d ", p->info);
        p = p->prox;
    }
    printf("\n");
}

void remover(LISTA *l, elem x){
    if(l == NULL) return NULL;
    NO *p = l->ini;
    NO *ant = NULL;

    while(p != NULL && get_valor(p->info) != x){
        ant = p;
        p = p->prox;
    }

    //1º caso: elemento nao encontrado
    if(p == NULL){
        return ;
    }
    //2º caso: elemento encontrado eh o primeiro da lista
    if(ant == NULL){
        l->ini = p->prox;
        if(l->total == 1) l->fim = NULL;
    }
    //3º caso: elemento encontrado eh o ultimo da lista
    else if(p == l->fim){
        ant->prox = NULL;
        l->fim = ant;
    }
    //4º caso: elemento encontrado esta no meio da lista
    else{
        ant->prox = p->prox;
    }

    apagar_item(&(p->info));
    free(p);
    l->total--;
}