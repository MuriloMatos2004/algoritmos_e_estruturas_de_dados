#include "lista.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct no NO;

struct no{
    int info;
    NO *prox, *ant;
};

struct lista{
    int total;
    NO *ini, *fim;
};


LISTA *criar_lista(){
    LISTA *l = malloc(sizeof(LISTA));
    if(l == NULL) return NULL;

    l->total = 0;
    l->ini = NULL;
    l->fim = NULL;
    return l;
}


bool inserir_elemento(LISTA *l, int chave){
    if(l == NULL) return false;
    if(l->total == MAX_TAM) return false;

    NO *p = malloc(sizeof(NO));
    p->info = chave;
    p->ant = NULL;
    p->prox = NULL;

    //1º caso: 1º elemento inserido da lista
    if(l->ini == NULL){
        l->ini = p;
        l->fim = l->ini;
        return true;
    }
    NO *r = l->ini;
    NO *aux = NULL;
    while(p->info > r->info){
        if(r->prox == NULL) break;
        aux = r;
        r = r->prox;
    }
    //2ºcaso: inserir no fim da lista
    if(r->prox == NULL){
        r->prox = p;
        p->ant = r;
        l->fim = p;
    }
    //3ºcaso: inserir no meio da lista
    else{
        aux->prox = p;
        p->prox = r;
        p->ant = aux;
        r->ant = p;
    }
    l->total++;
    return true;
}


bool remover_elemento(LISTA *l, int chave){
    if(l == NULL) return false;
    if(l->total == 0) return false;

    NO *p = l->ini;
    NO *aux = NULL;

    while(p != NULL){
        if(p->info == chave) break;
        aux = p;
        p = p->prox;
    }
    //1º caso elemento não encontrado
    if(p == NULL) return false;

    //2º caso: remover o primeiro elemento
    if(p->ant == NULL){
        l->ini = l->ini->prox;
        l->ini->ant = NULL;
        free(p);
    }
    //3º caso: remover o elemento do final
    else if(p->prox == NULL){
        l->fim = l->fim->ant;
        l->fim->prox = NULL;
        free(p);
    }
    //4º caso: remover o elemento do meio
    else{
        aux->prox = p->prox;
        p->ant = aux;
        free(p);
    }
    l->total--;

    return true;
}

int buscar_elemento(LISTA *l, int chave){
    if(l == NULL) return 0;

    NO *p = l->ini;

    while(p != NULL){
        if(p->info == chave) return chave;
        p = p->prox;
    }

    return 0;
}

void imprimir_lista(LISTA *l){
    if(l == NULL){
        printf("lista nao existe!\n");
        exit(1);
    }

    NO *p = l->ini;

    while(p != NULL){
        printf("%d ", p->info);
        p = p->prox;
    }
    printf("\n");
}


void imprimir_lista_inversamente(LISTA *l){
    if(l == NULL) exit(1);

    NO *p = l->fim;

    while(p != NULL){
        printf("%d ", p->info);
        p = p->ant;
    }
    printf("\n");
}

bool liberar_lista(LISTA **l){
    if(l == NULL) return false;

    free(*l);
    *l = NULL;
    return true;
}