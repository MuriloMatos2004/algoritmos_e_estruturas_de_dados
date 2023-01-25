#include "Pilha.h"
#include <stdio.h>
#include <stdlib.h>

struct pilha{
    int total;
    ITEM *pilha[TAM];
};

PILHA *pilha_criar(void){
    PILHA *p = malloc(sizeof(PILHA));
    if(p == NULL)
        return NULL;

    p->total = -1;

    return p;
}

void pilha_apagar(PILHA **pilha){
    if(pilha == NULL)
        exit(1);
    if(*pilha == NULL)
        exit(1);
    if(pilha_vazia(*pilha))
        exit(1);
    
    for(int i = 0; i < (*pilha)->total; i++)
        free(pilha[i]);

    free(*pilha);
    *pilha = NULL;
}

bool pilha_vazia(PILHA *pilha){
    if(pilha == NULL)
        return false;

    if(pilha->total == -1)
        return true;

    return false;
}

bool pilha_cheia(PILHA *pilha){
    if(pilha == NULL)
        return false;
    if(pilha->total == TAM)
        return true;
    return false;
}

int pilha_tamanho(PILHA *pilha){
    if(pilha == NULL)
        exit(1);
    
    return pilha->total +1;
}

ITEM *pilha_topo(PILHA *pilha){
    if(pilha == NULL)
        exit(1);
        
    return pilha->pilha[pilha->total];
}

bool pilha_empilhar(PILHA *pilha, ITEM *item){
    if(pilha == NULL)
        return false;
    if(pilha_cheia(pilha))
        return false;

    pilha->total+=1;
    pilha->pilha[pilha->total] = item;
    return true;
}

ITEM *pilha_desempilhar(PILHA *pilha){
    if(pilha == NULL)
        exit(1);
    if(pilha_vazia(pilha))
        exit(1);
    
    
    ITEM * r = pilha->pilha[pilha->total];
    pilha->total -= 1;
    return r;
}

void pilha_print(PILHA *p){
    if(p == NULL)
        exit(1);
    
    for(int i = 0; i <= p->total; i++){
        printf("%f ", item_get_chave(p->pilha[i]));
    }
}

float rpn(char *sequencia){
    float resultado = 0;
    PILHA *p = pilha_criar();
    for(int i = 0; sequencia[i] != '\0'; i++){
        if(sequencia[i] == '1')
            pilha_empilhar(p,item_criar(1));
        else if(sequencia[i] == '2')
            pilha_empilhar(p,item_criar(2));
        else if(sequencia[i] == '3')
            pilha_empilhar(p,item_criar(3));
        else if(sequencia[i] == '4')
            pilha_empilhar(p,item_criar(4));
        else if(sequencia[i] == '5')
            pilha_empilhar(p,item_criar(5));
        else if(sequencia[i] == '6')
            pilha_empilhar(p,item_criar(6));
        else if(sequencia[i] == '7')
            pilha_empilhar(p,item_criar(7));
        else if(sequencia[i] == '8')
            pilha_empilhar(p,item_criar(8));
        else if(sequencia[i] == '9')
            pilha_empilhar(p,item_criar(9));

        if(sequencia[i] == '/') {
            ITEM *i = pilha_desempilhar(p);
            ITEM *j = pilha_desempilhar(p);
            resultado = item_get_chave(j) / item_get_chave(i);
            pilha_empilhar(p, item_criar(resultado));
            item_apagar(&i);
            item_apagar(&j);
        }
        else if(sequencia[i] == '*') {
            ITEM *i = pilha_desempilhar(p);
            ITEM *j = pilha_desempilhar(p);
            resultado = item_get_chave(j) * item_get_chave(i);
            pilha_empilhar(p, item_criar(resultado));
            item_apagar(&i);
            item_apagar(&j);
        }
        else if(sequencia[i] == '+') {
            ITEM *i = pilha_desempilhar(p);
            ITEM *j = pilha_desempilhar(p);
            resultado = item_get_chave(j) + item_get_chave(i);
            pilha_empilhar(p, item_criar(resultado));
            item_apagar(&i);
            item_apagar(&j);
        }
        else if(sequencia[i] == '-') {
            ITEM *i = pilha_desempilhar(p);
            ITEM *j = pilha_desempilhar(p);
            resultado = item_get_chave(j) - item_get_chave(i);
            pilha_empilhar(p, item_criar(resultado));
            item_apagar(&i);
            item_apagar(&j);
        }
        // printf("i: %d \n", i);
        // pilha_print(p);
        // printf("\n");
    }

    pilha_apagar(&p);
    return resultado;
}