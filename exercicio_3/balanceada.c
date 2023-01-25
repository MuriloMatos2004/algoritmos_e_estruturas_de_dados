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