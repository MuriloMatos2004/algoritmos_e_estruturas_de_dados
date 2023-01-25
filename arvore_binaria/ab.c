#include "ab.h"
#include "pilha.h"

struct no {
    item_t *info;
    no_t *esq, *dir;
};

struct ab {
    no_t *raiz;
};

ab_t* cria(){
    ab_t *arvore = malloc(sizeof(ab_t));
    if (arvore == NULL) return NULL;
    arvore->raiz = NULL;

    return arvore;
}

int esta_vazia(ab_t *arvore){
    assert(arvore != NULL);

    return (arvore->raiz == NULL);
}


void finalizar(no_t *raiz){
    if(raiz != NULL){
        finalizar(raiz->esq);
        finalizar(raiz->dir);
        apagar_item(&(raiz->info));
        free(raiz);
    }
}
void finaliza(ab_t *A){
    if(!esta_vazia(A))
        finalizar(A->raiz);
}

void imprimir(no_t *raiz){
    if(raiz != NULL){
        printf("%d", get_valor(raiz->info));
        printf("(");
        if(raiz->esq != NULL){
            imprimir(raiz->esq);
            printf(",");
        }
        else{
            printf("_,");
        }
        if(raiz->dir != NULL){
            imprimir(raiz->dir);
        }
        else{
            printf("_");
        }
        printf(")");
    }
}


void imprime(ab_t *A){
    if(!esta_vazia(A)){
        imprimir(A->raiz);
        printf("\n");
    }
}

int altura_rec(no_t *raiz){
    if(raiz == NULL) return 0;

    int altura_esq = 1 + altura_rec(raiz->esq);
    int altura_dir = 1 + altura_rec(raiz->dir);

    if(altura_esq > altura_dir)
        return altura_esq;

    return altura_dir;
}

int altura(ab_t *A){
    if(!esta_vazia(A)){
        altura_rec(A->raiz);
    }
    return 0;
}

no_t *buscar_pai(no_t *raiz, elem x){
    if(raiz == NULL) return NULL;

    else if(raiz->esq != NULL && get_valor(raiz->esq->info) == x)
        return raiz;
    else if(raiz->dir != NULL && get_valor(raiz->dir->info) == x)
        return raiz;

    no_t *p = buscar_pai(raiz->esq, x);
    if(p == NULL)
        p = buscar_pai(raiz->dir, x);

    return p; 
}

no_t *busca_pai(ab_t *A, elem x){
    if(!esta_vazia(A)){
        buscar_pai(A->raiz, x);
    }
}

no_t *buscar(no_t *raiz, elem x){
    if(raiz == NULL) return NULL;

    if(get_valor(raiz->info) == x) return raiz;

    no_t *p = buscar(raiz->esq, x);
    if(p == NULL)
        p = buscar(raiz->dir, x);

    return p;
}

no_t *busca(ab_t *A, elem x){
    if(!esta_vazia(A))
        buscar(A->raiz, x);
}

bool insere_esq(ab_t *A, elem x, elem pai){
    no_t *p = malloc(sizeof(ab_t));

    p->esq = NULL;
    p->dir = NULL;
    p->info = criar_item(x);

    if(pai == -1){
        if(A->raiz == NULL){
            A->raiz = p;
            return true;
        }
        else{
            apagar_item(&(p->info));
            free(p);
            return false;
        }
    }
    else{
        no_t *aux = buscar(A->raiz, pai);
        if(aux != NULL && aux->esq == NULL){
            aux->esq = p;
            return true;
        }
        else{
            apagar_item(&(p->info));
            free(p);
            return false;
        }
    }
}

bool insere_dir(ab_t *A, elem x, elem pai){
    no_t *p = malloc(sizeof(ab_t));

    p->esq = NULL;
    p->dir = NULL;
    p->info = criar_item(x);

    if(pai == -1){
        if(A->raiz == NULL){
            A->raiz = p;
            return true;
        }
        else{
            apagar_item(&(p->info));
            free(p);
            return false;
        }
    }
    else{
        no_t *aux = buscar(A->raiz, pai);
        if(aux != NULL && aux->dir == NULL){
            aux->dir = p;
            return true;
        }
        else{
            apagar_item(&(p->info));
            free(p);
            return false;
        }
    }   
}

bool remover(ab_t *A, elem x){
    no_t *pai, *p;
    int eh_esq;

    if(A->raiz != NULL && get_valor(A->raiz->info) == x){
        pai = NULL;
        p = A->raiz;
    }
    else{
        pai = buscar_pai(A->raiz, x);
        if(pai != NULL){
            if(get_valor(pai->esq->info) == x){
                p = pai->esq;
                eh_esq = 1;
            }
            else{
                p = pai->dir;
                eh_esq = 0;
            }
        }
        else p = NULL;
    }
    if (p == NULL) return false;
    if(p->esq == NULL && p->dir == NULL){
        if(pai == NULL) A->raiz = NULL;
        else{
            if(eh_esq) pai->esq = NULL;
            else pai->dir = NULL;
            apagar_item(&(p->info));
            free(p);
        }
    }
    else{
        if(p->esq != NULL){
            set_valor(p->info, get_valor(p->esq->info));
            set_valor(p->esq->info, x);
        }
        else{
            set_valor(p->info, get_valor(p->dir->info));
            set_valor(p->dir->info, x);
        }
        return remover(A, x);
    }
    return true;
}

void percorre_pre_ordem(no_t *raiz){
    if(raiz != NULL){
        printf("%c ", get_valor(raiz->info));
        percorre_pre_ordem(raiz->esq);
        percorre_pre_ordem(raiz->dir);
    }
}
void pre_ordem(ab_t *A){
    printf("pre ordem: ");

    if(!esta_vazia(A)) percorre_pre_ordem(A->raiz);

    printf("\n\n");
}

void percorre_em_ordem(no_t *raiz){
    if(raiz != NULL){
        if(raiz->esq == NULL){
            printf("%c ", get_valor(raiz->info));
            percorre_em_ordem(raiz->dir);
        }
        else{
            percorre_em_ordem(raiz->esq);
            printf("%c ", get_valor(raiz->info));      
            percorre_em_ordem(raiz->dir);
        }    
    }
}

void em_ordem(ab_t *A){
    printf("em ordem: ");
    if(!esta_vazia(A)) percorre_em_ordem(A->raiz); 

    printf("\n\n");   
}

void percorre_pois_ordem(no_t *raiz){
    if(raiz != NULL){
        if(raiz->esq != NULL){
            percorre_pois_ordem(raiz->esq);
            percorre_pois_ordem(raiz->dir);
            printf("%c ", get_valor(raiz->info));
        }
        else if(raiz->dir != NULL){
            percorre_pois_ordem(raiz->dir);
            printf("%c ", get_valor(raiz->info));
        }
        else printf("%c ", get_valor(raiz->info));
    }
}

void pos_ordem(ab_t *A){
    printf("pos ordem: ");
    if(!esta_vazia(A)) percorre_pois_ordem(A->raiz); 

    printf("\n");
}

void percorre_em_ordem_iterativo(no_t *raiz){
    no_t *p = raiz;
    
    PILHA *pilha = criar_pilha();
    no_t *elemento;
    int i = 0;

    while(true){
        while(p != NULL){
            insere_na_pilha(p, pilha);
            p = p->esq;
        }
        
        elemento = remover_da_pilha(pilha);
        if(elemento == NULL) break;
        printf("%c ",get_valor(elemento->info));
        p = elemento->dir;
        i++;
    }
}

void em_ordem_iterativo(ab_t *A){
    if(!esta_vazia(A))
        percorre_em_ordem_iterativo(A->raiz);
}