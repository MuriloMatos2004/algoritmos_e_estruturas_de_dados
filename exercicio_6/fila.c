#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct no NO;

struct no{
    NO *prox;
    ITEM *info;
};

struct fila_{
    int total;
    NO *ini, *fim;
};

FILA *fila_criar(void){
    FILA *f = malloc(sizeof(FILA));
    if(f == NULL) return NULL;

    f->total = 0;
    f->ini = NULL;
    f->fim = NULL;
    return f;
}


bool fila_cheia(FILA *fila){
    if(fila == NULL) return false;

    if(fila->total == TAM_MAX) return true;

    return false;
}

void fila_imprimir(FILA *fila){
    if(fila == NULL) exit(1);

    NO *p = fila->ini;

    while(p!= NULL){
        printf("%d ", item_get_chave(p->info));
        p = p->prox;
    }
    printf("\n");
}


bool fila_inserir(FILA *fila, ITEM *item){
    if(fila == NULL) return false;

    NO *p = malloc(sizeof(NO));
    if(p == NULL) return false;
    p->info = item;

    if(fila_cheia(fila)) return false;

    //1º caso: fila vazia
    if(fila->ini == NULL){
        fila->ini = p;
        fila->fim = p;
    }
    
    //2ºcaso: fila com elementos
    else{
        fila->fim->prox = p;
        fila->fim = p;
    }

    fila->total++;

    return true;
}

ITEM *fila_remover(FILA *fila){
    if(fila == NULL) return NULL;

    NO *p = fila->ini;
    if(p == NULL) return NULL;

    fila->ini = fila->ini->prox;

    ITEM *i = p->info;
    fila->total--;
    free(p);

    return i;
}

int fila_tamanho(FILA *fila){
    if(fila == NULL) return 0;

    return fila->total;
}

void fila_apagar(FILA **fila){
    if(fila == NULL) exit(1);
    ITEM *i;

    while(!fila_vazia(*fila)){
        i = fila_remover(*fila);
        item_apagar(&i);
    }

    free(*fila);
    *fila = NULL;
}

bool fila_vazia(FILA *fila){
    if(fila == NULL) return false;

    if(fila->total == 0) return true;

    return false;
}

ITEM *fila_frente(FILA *fila){
    if(fila == NULL) return NULL;

    return fila->ini->info;
}