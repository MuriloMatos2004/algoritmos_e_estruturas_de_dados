#include "abb.h"
#include <stdlib.h>
#include <stdio.h>

struct no{
    int info;
    NO *esq, *dir;
};

struct arvore{
    NO *raiz;
};

abb *criar_arvore(){
    abb *T = malloc(sizeof(abb));
    if(T == NULL) return NULL;

    T->raiz = NULL;
    return T;
}

int insere(NO **p, elem x){
    NO *novo_no = malloc(sizeof(NO));
    novo_no->info = x;
    novo_no->esq = NULL;
    novo_no->dir = NULL;

    if((*p) == NULL){
        *p = novo_no;
        return 1;
    }
    if((*p)->info < x){
        insere(&((*p)->dir), x);
    }
    else if((*p)->info > x)
        insere(&((*p)->esq), x);
    else{
        free(novo_no);
        return 0;
    }

    return 1;
}

int inserir(abb **T, elem x){
    if(T == NULL) return 0;
    if((*T) == NULL) return 0;

    insere(&((*T)->raiz), x);

    return 1;
}

int imprime(NO *p){
    if(p != NULL){
        printf("%c(", p->info);
        imprime(p->esq);
        printf(",");
        imprime(p->dir);
        printf(")");
    }
    else{
        printf("_");
    }
}

int imprimir(abb *T){
    if(T == NULL) return 0;

    imprime(T->raiz);
}

int busca(NO *p, elem x){
    if(p == NULL) return -1;

    if(p->info == x)
        return x;
    if(p->info > x)
        return busca(p->esq, x);
    else if(p->info < x)
        return busca(p->dir, x);
}

int buscar(abb *T, elem x){
    if(T == NULL) return 0;

    return busca(T->raiz, x);
}

NO **busca_pai(NO **p, elem x){
    if(p == NULL) return NULL;
    if((*p) == NULL) return NULL;

    if((*p)->esq != NULL && (*p)->esq->info == x)
        return p;
    if((*p)->dir != NULL && (*p)->dir->info == x)
        return p;
    if((*p)->info > x)
        return busca_pai(&((*p)->esq), x);
    else if((*p)->info < x)
        return busca_pai(&((*p)->dir), x);
}

NO **buscar_pai(abb **t, elem x){
    if(t == NULL) return NULL;
    if((*t) == NULL) return NULL;

    return busca_pai(&((*t)->raiz),x);
}

int remover(NO **p, elem x, abb **t){
    if(p == NULL) return 0;
    if((*p) == NULL) return 0;

    if((*p)->info != x){
        if((*p)->info < x){
            return remover(&((*p)->dir), x, t);
        }
        else
            return remover(&((*p)->esq), x, t);
    }

    if((*p)->esq == NULL && (*p)->dir == NULL){
        free((*p));
        *p = NULL;
        return 1;
    }
    else if((*p)->esq != NULL && (*p)->dir == NULL){
        int aux = (*p)->info;
        (*p)->info = (*p)->esq->info;
        (*p)->esq->info = aux;
        return remover(&((*p)->esq), x, t);
    }
    else if((*p)->esq == NULL && (*p)->dir != NULL){
        NO *aux = (*p);
        *p = (*p)->dir;
        free(aux);
        aux = NULL;
        return 1;
    }
    else if((*p)->esq != NULL && (*p)->dir == NULL){
        NO *aux = (*p);
        *p = (*p)->esq;
        free(aux);
        aux = NULL;
        return 1;
    }
    else if((*p)->esq != NULL && (*p)->dir != NULL){
        NO *aux = (*p)->esq;
        while(aux->dir != NULL){
            aux = aux->dir;
        }
        int ajudante = (*p)->info;
        (*p)->info = aux->info;
        aux->info = ajudante;
        return  remover(&((*p)->esq), x, t);
    }
}

int remocao(abb **T, elem x){
    if(T == NULL) return 0;
    if((*T) == NULL) return 0;

    remover(&((*T)->raiz), x, T);
}