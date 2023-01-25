#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct no NO;

struct no{
    ITEM *info;
    NO *prox;
};

struct lista {
    int total;
    NO *sentinela;
};

LISTA *criar_lista(){
    LISTA *l = malloc(sizeof(LISTA));
    if(l == NULL) return NULL;
    l->total = 0;
    l->sentinela = NULL;

    return l;
}

bool lista_cheia(LISTA *l){
    if(l == NULL) return false;

    if(l->total == TAM_MAX) return true;

    return false;
}

bool lista_vazia(LISTA *l){
    if(l == NULL) return false;

    if(l->total == 0) return true;

    return false;
}

bool inserir_elemento(LISTA *l, ITEM *x){
    if(l == NULL) return false;

    if(lista_cheia(l)) return false;

    NO *novo_no = malloc(sizeof(NO));

    novo_no->info = x;

    /*Obs: Nesse modelo, o sentinela sempre
           aponta para o maior elemento*/

    //1º caso: lista vazia
    if(lista_vazia(l)){
        l->sentinela = novo_no;
        l->sentinela->prox = novo_no;
        l->total++;
        return true;
    }
    //2º caso: sentinela menor do que o elemento a ser inserido
    if(item_get_chave(l->sentinela->info) < item_get_chave(novo_no->info)){
        novo_no->prox = l->sentinela->prox;
        l->sentinela->prox = novo_no;
        l->sentinela = novo_no;
        l->total++;
        return true;
    }
    /*3º caso: sentinela maior do que o elemento a ser inserido*/
    //se o elemento for menor do que o próximo de sentinela
    if(item_get_chave(novo_no->info) < item_get_chave(l->sentinela->prox->info)){
        novo_no->prox = l->sentinela->prox;
        l->sentinela->prox = novo_no;
        l->total++;
        return true;
    }
    //se o elemento for maior do que o próximo de sentinela
    NO *p = l->sentinela->prox;
    NO *aux = NULL;
    while(item_get_chave(p->info) < item_get_chave(novo_no->info)){
        aux = p;
        p = p->prox;
    }
    novo_no->prox = p;
    aux->prox = novo_no;
    l->total++;

    return true;
}

void imprimir_lista(LISTA *l){
    if(l == NULL) exit(1);

    NO* p = l->sentinela->prox;
    while(p != l->sentinela){
        printf("%d ", item_get_chave(p->info));
        p = p->prox;
    }
    printf("%d ", item_get_chave(p->info));
}

bool remover_elemento(LISTA *l, int x){
    if(l == NULL) return false;

    NO *p = l->sentinela->prox;
    NO *aux = NULL;

    while(p != l->sentinela){
        if(item_get_chave(p->info) == x) break;
        aux = p;
        p = p->prox;
    }
    if(item_get_chave(p->info) == x){
        aux->prox = p->prox;
        item_apagar(&p->info);
        free(p);
        return true;
    }
    l->total--;
    return false;
}

ITEM *buscar_elemento(LISTA *l, int x){
    if(l == NULL) return NULL;

    NO *p = l->sentinela->prox;
    NO *aux = NULL;

    while(p != l->sentinela){
        if(item_get_chave(p->info) == x) break;
        aux = p;
        p = p->prox;
    }
    if(item_get_chave(p->info) == x){
        return p->info;
    }
    return NULL;
}

bool lista_apagar(LISTA **l){
    if(l == NULL) return false;

    if(*l != NULL && l != NULL){
        if(!lista_vazia(*l)){
            NO *p = (*l)->sentinela->prox;
            NO *aux = NULL;

            while(p != (*l)->sentinela){
                aux = p->prox;
                item_apagar(&p->info);
                free(p);
                p = aux;
            }
            item_apagar(&p->info);
            free(p);
            (*l)->total--;
        }
        free(*l);
        *l = NULL;
        return true;
    }

    return false;
}