#include "lista.h"
#include <math.h>


struct no{
    int tipo;
    INFO info;
    NO *prox;
    int valor;
};


void libera(NO *p){
    if(p == NULL) exit(1);

    NO *aux;
    while(p != NULL){
        aux = p;
        p = p->prox;
        if(aux->tipo == 0){
            apagar_item(&(aux->info.atomo));
        }
        else{
            libera(aux->info.sublista);
        }
        free(aux);
    }
}

NO *atomo(ITEM *atomo, int expoente){
    if(atomo == NULL) return NULL;

    NO *p = malloc(sizeof(NO));
    if(p == NULL) return NULL;

    p->tipo = 0;
    p->info.atomo = atomo;
    p->valor = expoente;
    p->prox = NULL;
    return p;
}

NO *sublista(NO *sublista, int coeficente){
    if(sublista == NULL) return NULL;

    NO *p = malloc(sizeof(NO));
    if(p == NULL)return NULL;

    p->tipo = 1;
    p->info.sublista = sublista;
    p->valor = coeficente;
    p->prox = NULL;
    return p;
}

NO *concat(NO *p, NO *q){
    assert(p != NULL);

    NO *aux = p;
    while(p->prox != NULL){
        p = p->prox;
    }
    p->prox = q;

    return aux;
}

INFO cabeca(NO *p, int *tipo){
    assert(p != NULL);

    *tipo = p->tipo;
    return p->info;
}

NO *cauda(NO *p){
    assert(p != NULL); 
    return p->prox;
}

void imprime(NO *p){
    assert(p != NULL);

    printf("[");
    while(p != NULL){
        if(p->tipo == 0){
            if(p->valor == 0)
                printf(" ");
            else
                printf("%c, %d", get_valor(p->info.atomo), p->valor);
        }
        else{
            printf("%d", p->valor);
            imprime(p->info.sublista);
        }
        if(p->prox != NULL)
            printf(", ");
        p = p->prox;
    }
    printf("]");
}

void verifica_na_listona(NO *p, int x){
    assert(p != NULL);

    while(p != NULL){
        if(p->tipo == 0){
            if(get_valor(p->info.atomo) == x){
                printf("Esta na lista\n");
            }
        }
        p = p->prox;
    }
}

void verifica_em_tudo(NO *p, int x){
    assert(p != NULL);

    while(p != NULL){
        if(p->tipo == 0){
            if(get_valor(p->info.atomo) == x){
                printf("Esta na lista\n");
            }
        }
        else
            verifica_em_tudo(p->info.sublista, x);
        p = p->prox;
    }
}

int igualdade(NO *p, NO *q){
    assert(p != NULL);
    assert(q != NULL);
    static int i = 0;

    while(p != NULL){
        if(p->tipo == 1 && q->tipo == 0){
            printf("nao sao iguais");
            i++;
            break;
        }
        else if(p->tipo == 0 && q->tipo == 1){
            printf("nao sao iguais");
            i++;
            break;
        }
        else if(p->tipo == 0 && q->tipo == 0){
            if(get_valor(p->info.atomo) != get_valor(q->info.atomo) ){
                printf("nao sao iguais\n");
                i++;
                break;
            }
        }
        else{
            igualdade(p->info.sublista, q->info.sublista);
        }
        p = p->prox;
        q = q->prox;
    }
    if(i == 0)return 0;
    else return 1;
}

void imprimir(NO *p){
    assert(p != NULL);
    imprime(p);
    printf("\n");
}

int profundidade(NO *p){
    assert(p != NULL);
    static int i = 1;

    while(p != NULL){
        if(p->tipo == 1){
            i++;
            profundidade(p->info.sublista);
            break;
        }
        p = p->prox;
    }
    return i;
}

int resultado_ponlinomio(NO *p, int x, int y, int z){
    assert(p != NULL);
    static int resultado = 0;

    while(p != NULL){
        if(p->tipo == 0){
            int produto = 1;
            if(p->prox != NULL){
                produto *= pow(x,p->valor);
                if(p->prox != NULL){
                    p = p->prox;
                    produto *= pow(y,p->valor);
                    if(p->prox != NULL){
                        p = p->prox;
                        produto *= pow(z,p->valor);
                    }
                }
            }
            return produto;
        }
        else{
            resultado += p->valor * resultado_ponlinomio(p->info.sublista, x, y, z);
        }
        p = p->prox;
    }
    return resultado;
}