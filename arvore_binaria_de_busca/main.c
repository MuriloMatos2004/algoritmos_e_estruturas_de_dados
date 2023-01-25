#include "abb.h"
#include <stdio.h>

int main(){
    abb *t = criar_arvore();

    inserir(&t, 'O');
    inserir(&t, 'E');
    inserir(&t, 'V');
    inserir(&t, 'C');
    inserir(&t, 'H');
    inserir(&t, 'D');
    inserir(&t, 'G');
    inserir(&t, 'I');
    inserir(&t, 'J');
    inserir(&t, 'T');
    inserir(&t, 'Y');
    inserir(&t, 'X');
    inserir(&t, 'Z');
    imprimir(t);

    remocao(&t, 'O');

    printf("\n");
    imprimir(t);
    printf("\n");

    return 0;
}