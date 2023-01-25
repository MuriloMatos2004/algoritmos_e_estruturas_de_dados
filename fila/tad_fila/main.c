#include <stdio.h>
#include "fila.h"

int main(){
    tipo_fila *p = criar_fila();
    int vetor[5] = {1,23,3,0,5};
    int elementos_pilha[5];

    inserir(p, &vetor[0]);
    inserir(p, &vetor[1]);
    inserir(p, &vetor[2]);
    inserir(p, &vetor[3]);
    inserir(p, &vetor[4]);


    int count = 0;

    while(remover(p, &elementos_pilha[count])){
        count++;
    }
    for(int i = 4; i >= 0; i--){
        printf("%d ", elementos_pilha[i]);
    }   
    destruir(&p);


    return 0;
}