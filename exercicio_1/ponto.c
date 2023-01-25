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

