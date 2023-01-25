#ifndef _AB_H_
#define _AB_H_

typedef struct no NO;
typedef struct arvore abb;
typedef char elem;

abb *criar_arvore();
int buscar(abb *T, elem x);
int inserir(abb **T, elem x);
int remocao(abb **T, elem x);
int imprimir(abb *T);

#endif