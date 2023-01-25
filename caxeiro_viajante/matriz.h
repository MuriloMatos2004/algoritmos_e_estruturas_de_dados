/*Declaração das funções, bibliotecas e tipos contidos
  no TAD matriz de adjacências*/

#ifndef _MATRIZ_H
#define _MATRIZ_H

//Bibliotecas usadas
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

//Declaração do tipo matriz
typedef struct tipo_matriz MATRIZ;

//Funções do TAD 
MATRIZ *criar_matriz(int qtd_linhas_e_colunas);
bool inserir_na_matriz(MATRIZ *m, int elemento, int i, int j, int vertices);
bool destruir_matriz(MATRIZ **m, int tam_matriz);
int retorna_elemento(MATRIZ *m, int i, int j);
void printar_matriz(MATRIZ *m, int qtd_linhas_e_colunas);

#endif