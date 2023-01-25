#include "fila.h"

struct fila{
    int total, fim, inicio;
    int *fila[TAM_FILA];
};

tipo_fila* criar_fila(){
    tipo_fila *p = malloc(sizeof(tipo_fila));
    assert(p != NULL);
    p->inicio = 0;
    p->fim = 0;
    p->total = 0;
    return p;
}

bool esta_cheia(tipo_fila *f){
    assert(f != NULL);
    if(f->total == TAM_FILA)
        return true;
    return false;
}

bool esta_vazia(tipo_fila *f){
    assert(f != NULL);
    if(f->total == 0)
        return true;
    return false;
}

bool inserir(tipo_fila *f, int *e){
    assert(f != NULL);
    if(!esta_cheia(f)){
        f->fila[f->fim] = e;
        f->fim = (f->fim + 1) % TAM_FILA;
        f->total++;
        return true;
    }
    return false;
}

bool remover(tipo_fila *f, int *e){
    assert(f != NULL);

    if(!esta_vazia(f)){
        *e = *(f->fila[f->inicio]);
        f->inicio = (f->inicio + 1) % TAM_FILA;
        f->total--;
        return true;
    }
    return false;
}

bool destruir(tipo_fila **f){
    assert(f != NULL);
    if(esta_vazia(*f)){
        free(*f);
        *f = NULL;
        return true;
    }
    return false;
}

