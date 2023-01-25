#include "lista.h"

int main(){
    NO *l = sublista(concat(concat(atomo(criar_item('x'),2),atomo(criar_item('y'),3)),atomo(criar_item('z'),1)), 4);
    l = concat(l,sublista(concat(atomo(criar_item('x'),1),atomo(criar_item('y'),1)),3));
    l = concat(l, sublista(atomo(criar_item('_'),0),5));


    imprimir(l);

    int r = resultado_ponlinomio(l, 1, 1, 1);
    printf("%d\n", r);




    return 0;
}