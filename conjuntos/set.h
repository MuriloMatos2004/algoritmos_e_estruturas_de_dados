#ifndef _SET_H
#define _SET_H

  #include <stdbool.h>
  #include "item.h"
  typedef struct no NO;
  typedef struct set SET;

  SET *set_criar(void); //O(1)
  bool set_pertence(SET *A, ITEM *elemento);//O(log n)
  bool set_inserir (SET *s, ITEM *elemento); //O(log n)
  bool set_remover(SET *s, ITEM *elemento); //O(log n) 
  void set_apagar(SET **s); //O(1) 
  void set_imprimir(SET *s); //O(n)
  SET *set_uniao(SET *A, SET *B); //O(n log n)
  SET *set_interseccao(SET *A, SET *B); //O(n log n)


  int altura(NO *n); // O(1)
  NO *no_criar(ITEM *item); // O(1)
  int max(int a, int b); // O(1)
  NO *rotacionar_esq(NO *x); // O(1)
  NO *rotacionar_dir(NO *x); // O(1)
  int calcular_fb(NO *n); // O(1)
  NO *inserir_no_aux(NO *n, ITEM *item); //O(log n)
  NO *no_maior_valor(NO *n); //O(log n)
  NO *deletar_no_aux(NO *n, ITEM *item); //O(log n) 
  void imprimir_aux(NO *n); //O(n)
  ITEM *buscar_aux(NO *n, ITEM *chave); //O(log n)
  void apagar_aux(NO *n); //O(n)
  void unir(NO *n, SET *C); //O(n log n) 
  void interseccao(NO *a, SET *B, SET *C); //O(n log n)


#endif