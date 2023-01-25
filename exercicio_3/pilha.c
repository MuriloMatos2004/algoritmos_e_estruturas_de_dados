#include "pilha.h"

struct pilha{
    int topo;
    ITEM *pilha[TAM];
};

PILHA* pilha_criar(void){
    PILHA *p = malloc(sizeof(PILHA));
    p -> topo = -1;
    return p;
}

void pilha_apagar(PILHA** pilha){
    if(pilha == NULL)
        exit(1);
    free(*pilha);
    *pilha = NULL;
}

bool pilha_vazia(PILHA* pilha){
    if(pilha == NULL)
        return false;
    if(pilha->topo == -1){
        return true;
    }
    return false;
}

bool pilha_cheia(PILHA* pilha){
    if(pilha == NULL)
        return false;
    if((pilha->topo + 1) == TAM){
        return true;
    }
    return false; 
}

int pilha_tamanho(PILHA* pilha){
    if(pilha == NULL){
        printf("pilha nao existe\n");
        exit(1);
    }
    return pilha->topo + 1;
}

ITEM* pilha_topo(PILHA* pilha){
    if(pilha == NULL)
        return NULL;


    return pilha -> pilha[pilha->topo];
}

bool pilha_empilhar(PILHA* pilha, ITEM* item){
    if(pilha == NULL){
        printf("pilha nao existe\n");
        return false;
    }
    if(!pilha_cheia(pilha)){
        pilha->topo++;
        pilha->pilha[pilha->topo] = item;
    }

    return true;
}

ITEM* pilha_desempilhar(PILHA* pilha){
    if(pilha == NULL){
        printf("pilha nao existe\n");
        return false;
    }
    if(!pilha_vazia(pilha)){
        ITEM* u = pilha->pilha[pilha->topo];
        pilha->topo--;
        return u;
    }
    exit(1);
}

void pilha_print(PILHA* p){
    printf("%c ", item_get_chave(pilha_topo(p)));
    ITEM *t = pilha_desempilhar(p);
    ITEM *j;
    ITEM *l;
    ITEM *m;
    ITEM *n;
    int c = 0;
    if(!pilha_vazia(p)){
        printf("%c ", item_get_chave(pilha_topo(p)));
        j = pilha_desempilhar(p);
        c++;
    }
    if(!pilha_vazia(p)){
        printf("%c ", item_get_chave(pilha_topo(p)));
        l = pilha_desempilhar(p);
        c++;
    }
    if(!pilha_vazia(p)){
        printf("%c ", item_get_chave(pilha_topo(p)));
        m = pilha_desempilhar(p);
        c++;
    }
    if(!pilha_vazia(p)){
        printf("%c ", item_get_chave(pilha_topo(p)));
        n = pilha_desempilhar(p);
        c++;
    }
    if(c == 0)
        pilha_empilhar(p, n);
    else if(c == 1)
        pilha_empilhar(p, m);
    else if(c == 2)
        pilha_empilhar(p, l);
    else if(c == 3)
        pilha_empilhar(p, j);
    else if(c == 4)
        pilha_empilhar(p, t);
}



bool balanceada(char *sequencia){
    int c = 0;
    int n = 0;
    PILHA* pilha = pilha_criar();
    while(sequencia[n] != '\0'){
        n++;
    }
    for(int i = 0; i < n; i++){
        if(!pilha_vazia(pilha)){
            int topo  = item_get_chave(pilha_topo(pilha));
            int valor = item_get_chave(item_criar(sequencia[i]));
            if((topo == valor - 1) || (topo == valor - 2)){
                ITEM *item_1 = pilha_desempilhar(pilha);
                item_apagar(&item_1);
                c = 1;
            }
        }
        if(c == 0){
            pilha_empilhar(pilha, item_criar(sequencia[i]));
        }
        else{
            c = 0;
        }
    }

    if(pilha_vazia(pilha)){
        pilha_apagar(&pilha);
        return true;
    }
    else{
        while(!pilha_vazia(pilha)){
            ITEM *item_2 = pilha_desempilhar(pilha);
            item_apagar(&item_2);
        }
        pilha_apagar(&pilha);
        return false;
    }
}