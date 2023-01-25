#include "fila.h"
#include <stdlib.h>
#include <stdio.h>
#define TAM_FILA 49

struct fila_{
    int inicio, fim, total;
    ITEM *itens[TAM_FILA];
};

FILA *fila_criar(void){
    FILA *f = malloc(sizeof(FILA));
    if(f == NULL) return NULL;

    f->inicio = 0;
    f->fim = 0;
    f->total = 0;

    return f;
}

bool fila_inserir(FILA *fila, ITEM *item){
    if(fila == NULL) return false;
    if(fila_cheia(fila)) return false;

    fila->itens[fila->fim] = item;
    fila->fim = (fila->fim + 1) % TAM_FILA;
    fila->total++;

    return true;
}

bool fila_vazia(FILA *fila){
    if(fila == NULL) exit(1);

    if(fila->total == 0) return true;
    return false;
}

bool fila_cheia(FILA *fila){
    if(fila == NULL) exit(1);

    if(TAM_FILA == fila->total) return true;
    
    return false;
}

ITEM *fila_remover(FILA *fila){
    if(fila == NULL) return NULL;

    ITEM *i = fila->itens[fila->inicio];

    fila->inicio++;
    fila->total--;

    return i;
}

void fila_apagar(FILA **fila){
    if(fila != NULL && *fila != NULL){
        free(*fila);
        fila = NULL;
    }
}

ITEM *fila_frente(FILA *fila){
    if(fila == NULL) return NULL;

    return fila->itens[fila->total-1];
}

int fila_tamanho(FILA *fila){
    if(fila == NULL) return 0;

    return fila->total;
}

void fila_imprimir(FILA *fila){
    if(fila == NULL) exit(1);

    for(int i = fila->inicio; i < (fila->inicio + fila->total); i++)
        printf("%d ", item_get_chave(fila->itens[i]));
}

void cartas(int n){
    int descartados[n-1];
    ITEM *t;
    FILA *fila = fila_criar();
    for(int i = 1; i <= n; i++)
        fila_inserir(fila, item_criar(i));
    
    int contador = 0;
    while(contador < (n - 1)){
        ITEM *t = fila_remover(fila);
        descartados[contador] = item_get_chave(t);
        item_apagar(&t);

        t = fila_remover(fila);
        fila_inserir(fila,t);
        contador++;
    }

    printf("Discarded cards: ");
    for(int j = 0; j < (n - 1); j++)
        if(j == (n - 2)) printf("%d ", descartados[j]);
        else printf("%d, ", descartados[j]);
    
    printf("\nRemaining card: ");
    t = fila_remover(fila);
    int carta_que_sobrou = item_get_chave(t);
    printf("%d", carta_que_sobrou);

    item_apagar(&t);
    fila_apagar(&fila);
}