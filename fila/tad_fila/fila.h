//criar_fila
//esta_cheia
//esta_vazia
//inserir
//remover
//destruir

#ifndef _fila_H
#define _fila_H
#define TAM_FILA 10

typedef struct fila tipo_fila;

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

tipo_fila* criar_fila();
bool esta_cheia(tipo_fila *f);
bool esta_vazia(tipo_fila *f);
bool inserir(tipo_fila *f, int *e);
bool remover(tipo_fila *f, int *e);
bool destruir(tipo_fila **f);



#endif