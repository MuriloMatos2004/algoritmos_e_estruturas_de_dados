#include "ABB.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct No NO;

struct No{
    ITEM *item;
    NO *esq;
    NO *dir;
};

struct abb{ 
    NO *raiz;    
    int profundidade;
};

ABB *abb_criar (void){
    ABB *arvore = malloc(sizeof(ABB));
    if(arvore == NULL) return NULL;

    arvore->raiz = NULL;
    arvore->profundidade = 0;

    return arvore;
}

bool abb_insere(NO **raiz, ITEM *item){
    NO *novo_no = malloc(sizeof(NO));
    if(novo_no == NULL) return false;
    novo_no->item = item;
    
    if((*raiz) == NULL){ 
        *raiz = novo_no;
        //printf("raiz nula\n");
        //printf("raiz->item: %d\n", valor_item((*raiz)->item));
        return true;
    }
    // printf("raiz nao nula\n");
    // printf("raiz->item: %d\n", valor_item((*raiz)->item));
    // printf("item: %d\n", valor_item(item));

    if(valor_item((*raiz)->item) > valor_item(item)){
        //printf("entrou no primeiro if\n");
        if((*raiz)->esq == NULL){
            //printf("raiz de esq\n");
            (*raiz)->esq = novo_no;
        }
        else{
            free(novo_no);
            abb_insere(&((*raiz)->esq), item);
        }
    }
    else if(valor_item((*raiz)->item) < valor_item(item)){
        if((*raiz)->dir == NULL)
            (*raiz)->dir = novo_no;
        else{
            free(novo_no);        
            abb_insere(&((*raiz)->dir), item);
        }
    }
    else{
        free(novo_no);
        return false;
    }
    return true;
}

bool abb_inserir (ABB *T, ITEM *item){
    if(T == NULL) return false;

    return abb_insere(&(T->raiz), item);
}

void abb_imprime(NO *raiz){
    if(raiz != NULL){
        printf("%d(", valor_item(raiz->item));
        abb_imprime(raiz->esq);
        printf(",");
        abb_imprime(raiz->dir);
        printf(")");
    }
    else
        printf("_");   
}

void abb_imprimir (ABB *T){
    if(T != NULL)
        abb_imprime(T->raiz);
}

void apagar_folhas(NO *raiz){
    if(raiz != NULL){
        apagar_item(&(raiz->item));
        apagar_folhas(raiz->esq);
        apagar_folhas(raiz->dir);
    }
}

void abb_apagar (ABB **T){
    if(T == NULL) exit(1);
    if((*T) == NULL) exit(1);

    apagar_folhas((*T)->raiz);

    free(*T);
    *T = NULL;
}

NO *buscar_pai(NO *raiz, int chave){
    NO *no_pai;
    if(raiz != NULL){
        if(raiz->esq != NULL && valor_item(raiz->esq->item) == chave){
            return raiz;
        }
        else if(raiz->dir != NULL && valor_item(raiz->dir->item) == chave){
            return raiz;
        }
        else{
            no_pai = buscar_pai(raiz->esq, chave);
            if(no_pai == NULL)
                no_pai = buscar_pai(raiz->dir, chave);
        }
        return no_pai;
    }
    else return NULL;
}

bool abb_remove(NO **raiz, int chave, ABB **T){
    if((*raiz) == NULL) return false;

    if(valor_item((*raiz)->item) == chave){
        if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
            apagar_item(&((*raiz)->item));
            free(*raiz);
            *raiz = NULL;
        }
        else if((*raiz)->esq != NULL && (*raiz)->dir == NULL){
            NO *no_pai = buscar_pai((*T)->raiz, chave);
            //fprintf(stderr, "\n%d", valor_item((*raiz)->item));
            //fprintf(stderr, "\n%d", valor_item(no_pai->item));
            if(valor_item(no_pai->item) > valor_item((*raiz)->item)){
                //fprintf(stderr, "\n26 eh menor que 20");
                apagar_item(&((*raiz)->item));
                no_pai->esq = (*raiz)->esq;
            }
            else if(valor_item(no_pai->item) < valor_item((*raiz)->item)){
                apagar_item(&((*raiz)->item));
                no_pai->dir = (*raiz)->esq;
            }
        }
        else if((*raiz)->esq == NULL && (*raiz)->dir != NULL){
            NO *no_pai = buscar_pai((*T)->raiz, chave);
            if(valor_item(no_pai->item) > valor_item((*raiz)->item)){
                apagar_item(&((*raiz)->item));
                no_pai->esq = (*raiz)->dir;
            }
            else if(valor_item(no_pai->item) < valor_item((*raiz)->item)){
                apagar_item(&((*raiz)->item));
                no_pai->dir = (*raiz)->dir;
            }
        }
        else if((*raiz)->esq != NULL && (*raiz)->dir != NULL){
            NO *no_substituto = (*raiz)->esq;
            while(no_substituto->dir != NULL){
                no_substituto = no_substituto->dir;
            }
            //fprintf(stderr, "%d ", valor_item(no_substituto->item));
            int x = valor_item((*raiz)->item);
            muda_valor_item((*raiz)->item, valor_item(no_substituto->item));
            //fprintf(stderr, "%d s", valor_item(no_substituto->item));
            muda_valor_item(no_substituto->item, x);
            //fprintf(stderr, "%d s", valor_item(no_substituto->item));
            // fprintf(stderr, "%d ", valor_item(no_substituto->item));
            //fprintf(stderr, "%d sjjjj", valor_item((*raiz)->esq->item));
            NO *outro_no_pai = buscar_pai((*T)->raiz, chave);
            
            //fprintf(stderr, "%d \n", valor_item(outro_no_pai->item));
            if(valor_item(outro_no_pai->item) < valor_item((*raiz)->item))
                outro_no_pai->dir = NULL;
            else
                outro_no_pai->esq = NULL;          
            
            //fprintf(stderr, "oiooooo");
            apagar_item(&(no_substituto->item));
            free(no_substituto);
            //if(outro_no_pai->dir == NULL) fprintf(stderr, "aaaaaaaa");
            //fprintf(stderr, "%d ", valor_item((*raiz)->item));
        }
    }
    else{
        if(valor_item((*raiz)->item) > chave){
            abb_remove(&((*raiz)->esq), chave, T);
        }
        else{
            abb_remove(&((*raiz)->dir), chave, T);
        }
    }
    return true;
}

bool abb_remover(ABB *T, int chave){
    if(T == NULL) return false;

    return abb_remove(&(T->raiz), chave, &T);
}

ITEM *abb_buscar(NO *raiz, int chave){
    if(raiz == NULL) return NULL;

    if(valor_item(raiz->item) == chave) return raiz->item;

    else if(valor_item(raiz->item) > chave) 
        return abb_buscar(raiz->esq, chave);
    
    else if(valor_item(raiz->item) < chave) 
        return abb_buscar(raiz->dir, chave);
}

ITEM *abb_busca(ABB *T, int chave){
    if(T == NULL) return NULL;

    abb_buscar(T->raiz, chave);
}