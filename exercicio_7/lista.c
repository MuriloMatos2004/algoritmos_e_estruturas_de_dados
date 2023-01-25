#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

struct lista_{
    ITEM *lista[TAM_MAX];
    int inicio, fim;
};

LISTA *lista_criar(void){
    LISTA *l = malloc(sizeof(LISTA) * TAM_MAX);
    if(l == NULL) return NULL;

    l->inicio = inicial;
    l->fim = l->inicio;

    return l;
}

bool lista_inserir(LISTA *lista, ITEM *item){
    if(lista == NULL) return false;

    if(lista_cheia(lista)) return false;

    //lista vazia
    if(lista_vazia(lista)){
        lista->lista[lista->inicio] = item;
    }
    else{
        lista->lista[lista->fim] = item;
    }
    lista->fim = lista->fim + 1;

    ITEM *aux;

    for(int i = 1;i <= lista->fim - 1; i++){
        for(int j = 0; j < lista->fim - i; j++){
            if(item_get_chave(lista->lista[j]) > item_get_chave(lista->lista[j+1])){
                aux = lista->lista[j+1];
                lista->lista[j+1] = lista->lista[j];
                lista->lista[j] = aux;
            }
        }
    }


    return true;
}

bool lista_vazia(LISTA *lista){
    if(lista == NULL) return false;

    if(lista->fim == 0) return true;

    return false;
}

bool lista_cheia(LISTA *lista){
    if(lista == NULL) return false;

    if(lista->fim == TAM_MAX) return true;

    return false;
}

void lista_imprimir(LISTA *lista){
    if(lista == NULL) exit(1);


    for(int i = 0; i < lista->fim; i++)
        printf("%d ", item_get_chave(lista->lista[i]));
    printf("\n");
}