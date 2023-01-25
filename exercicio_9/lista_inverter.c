bool lista_inverter(LISTA **lista){
    if(lista != NULL && *lista != NULL){
        int TAM = lista_tamanho(*lista);
        int *elementos = malloc(sizeof(int)*TAM);
        NO *p = (*lista)->inicio;

        int contador = 0;

        while(p != NULL){
            elementos[contador] = item_get_chave(p->item);
            p = p->proximo;
            contador++;
        }

        contador--;
        p = (*lista)->inicio;

        while(contador >= 0){
            item_set_chave(p->item, elementos[contador]);
            p = p->proximo;
            contador--;
        }

        free(elementos);
    }
    return false;
}