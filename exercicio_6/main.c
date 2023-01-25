#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


int main (void){

  // FILA *fila = fila_criar();

  // fila_inserir(fila, item_criar(1));
  // fila_inserir(fila, item_criar(2));
  // fila_inserir(fila, item_criar(3));

  // fila_imprimir(fila);

  // ITEM *i = fila_remover(fila);
  // printf("\nitem removido: %d \n", item_get_chave(i));
  // item_apagar(&i);
  
  // fila_inserir(fila, item_criar(5));
  // fila_inserir(fila, item_criar(6));

  // fila_imprimir(fila);

  // fila_remover(fila);

  // fila_imprimir(fila);

  // printf("tamanho: %d\n", fila_tamanho(fila));

  // i = fila_frente(fila);

  // printf("\nitem da frente: %d \n", item_get_chave(i));


  // while(!fila_vazia(fila)){
  //   i = fila_remover(fila);
  //   item_apagar(&i);
  // }

  // printf("tamanho: %d\n", fila_tamanho(fila));

  // fila_apagar(&fila);

  

  



  FILA *fila=NULL;

  int n;

  fila = fila_criar();

  //qtd de números
  scanf("%d", &n);

  for(int i = 0; i < n; i++)
    fila_inserir(fila, item_criar(i));

  fila_apagar(&fila);

  if (fila == NULL)
    printf("Fila vazia!\n");

  return(0);
}
