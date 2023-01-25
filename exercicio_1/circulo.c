#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"

struct circulo_{
    float a, b, raio;
};

CIRCULO *circulo_criar (PONTO *p, float raio){
    CIRCULO *p_cir = malloc(sizeof(CIRCULO));
    if(p_cir == NULL){
        return p_cir;
    }
    p_cir->a = ponto_get_x(p);
    p_cir->b = ponto_get_y(p);
    p_cir->raio = raio;

    return p_cir;
}

PONTO *circulo_get_ponto (CIRCULO *c){
    if(c != NULL){
        return ponto_criar(c->a, c->b);
    }
    exit(1);
}


bool circulo_set_ponto (CIRCULO *c, PONTO *p){
    if(c == NULL && p == NULL){
        return false;
    }
    c->a = ponto_get_x(p);
    c->b = ponto_get_y(p);

    return c; 
}

bool circulo_set_raio (CIRCULO *c, int raio){
    if(c == NULL){
        return false;
    }
    c->raio = raio;
    return true;
}

int circulo_get_raio (CIRCULO *c){
    if(c != NULL)
        return c->raio;
    exit(1);
}

void circulo_apagar (CIRCULO **circulo){
    if(circulo != NULL){
        free(*circulo);
        circulo = NULL;
    }
}