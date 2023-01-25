#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

struct ponto_{
    float x, y;
};

PONTO *ponto_criar (float x, float y){
    PONTO *p = malloc(sizeof(PONTO));
    if(p == NULL){
        return NULL;
    }
    p->x = x;
    p->y = y;

    return p;
}

void ponto_print (PONTO *p){
    printf("Ponto: (%.1f, %.1f)\n", p->x, p->y);
}

void ponto_apagar (PONTO **p){
    if(p != NULL){
        free(*p);
        p = NULL;
    }
}

bool ponto_set (PONTO *p, float x, float y){
    if(p != NULL){
        p->x = x;
        p->y = y;
        return true;
    }
    return false;
}

float ponto_get_x (PONTO *p){
    if(p != NULL){
        return p->x;
    }
    exit(1);
}

float ponto_get_y (PONTO *p){
    if(p != NULL){
        return p->y;
    }
    exit(1);
}

float distancia(PONTO*  a, PONTO* b){
    /*Justificativa para a função distância estar no 
      TAD ponto: Como a função mede a distância entre pontos,
      devido o fato do centro do círculo ser um ponto, é mais
      coerente em termos de organização e semelhança entre
      as funções do TAD*/

    return sqrt(pow(ponto_get_x(a) - ponto_get_x(b), 2) + pow(ponto_get_y(a) - ponto_get_y(b), 2)); 
}