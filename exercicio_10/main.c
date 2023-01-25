#include "ABB.h"
#include <stdio.h>
#include <stdlib.h>
    
int main(int argc, char *argv[]){

  // ABB *T = abb_criar();

  // abb_inserir(T, item_criar(4));
  // abb_inserir(T, item_criar(5));
  // abb_inserir(T, item_criar(3));
  // abb_inserir(T, item_criar(1));
  // abb_inserir(T, item_criar(10));

  // abb_imprimir(T);
  // printf("\n");
  // abb_remover(T, 5);
  // abb_imprimir(T);
  // abb_apagar(&T);


  ABB *T;
  int n, m, x, op;
  
  T = abb_criar();

  scanf("%d %d", &n, &m);

  for(int i = 0; i < n; i++){
    scanf("%d", &x);
    ITEM *item = item_criar(x);
    abb_inserir(T, item);
  }

  while(m--){
    scanf("%d", &op);

    switch(op){
      case 1: { //Busca
        int num;
        scanf("%d", &num);

        if(abb_busca(T, num) != NULL) printf("Item encontrado.\n");
        else printf("Item não encontrado.\n");
        
        break;
    }
      case 2: { //Remoção
        int num;
        scanf("%d", &num);
      
        if(abb_remover(T,num)) printf("Item removido.\n");
        else printf("Item não removido.\n");
      
        break;
      }
    }
  }
  

  return 0;
}
