int busca_rec(LISTA *lista, int chave){
    static int total = 0;

    int TAM = lista_tamanho(lista);


    if(lista == NULL) return 0;

    ITEM *i = lista_busca(lista, chave);

    if(i == NULL) {
        int resultado = total;
        total = 0;
        int TAM = lista_tamanho(lista);

        for(int j = 0; j < resultado; j++){
            i = lista_busca(lista, -1);
            item_set_chave(i, chave); 
        } 
        return resultado;
    }

    total++;

    item_set_chave(i, -1);
    busca_rec(lista, chave);
}