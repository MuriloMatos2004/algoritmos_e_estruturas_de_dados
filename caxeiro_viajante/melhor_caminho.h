#ifndef _MELHOR_CAMINHO_H
#define _MELHOR_CAMINHO_H

//bibliotecas usadas
#include "matriz.h"

//Declaração da função que imprime o array
void printarray(int possivel_caminho[], int size);

//Declaração da função que encontra o melhor caminho
bool melhor_caminho(int *array, int start, int end, MATRIZ *m, int *min, int *best_path);

//Declaração da função de troca, usada na permutação
void swap(int *a, int *b);

#endif