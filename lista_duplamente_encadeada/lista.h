#ifndef _LISTA_H_
#define _LISTA_H_
typedef struct lista LISTA;
#define MAX_TAM 10

#include <stdbool.h>

LISTA *criar_lista();
bool inserir_elemento(LISTA *l, int chave);
bool remover_elemento(LISTA *l, int chave);
int buscar_elemento(LISTA *l, int chave);
void imprimir_lista(LISTA *l);
void imprimir_lista_inversamente(LISTA *l);
bool liberar_lista(LISTA **l);

#endif


