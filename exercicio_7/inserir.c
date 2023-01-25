bool lista_inserir(LISTA *lista, ITEM *item){
    if(lista == NULL) return false;

    if(lista_cheia(lista)) return false;

    //lista vazia
    if(lista_vazia(lista)){
        lista->lista[lista->inicio] = item;
    }
    else{
        lista->lista[lista->fim] = item;
    }
    lista->fim = lista->fim + 1;

    ITEM *aux;

    for(int i = 1;i <= lista->fim - 1; i++){
        for(int j = 0; j < lista->fim - i; j++){
            if(item_get_chave(lista->lista[j]) > item_get_chave(lista->lista[j+1])){
                aux = lista->lista[j+1];
                lista->lista[j+1] = lista->lista[j];
                lista->lista[j] = aux;
            }
        }
    }


    return true;
}