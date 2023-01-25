void fila_apagar(FILA **fila){
    if(fila == NULL) exit(1);
    ITEM *i;

    while(!fila_vazia(*fila)){
        i = fila_remover(*fila);
        item_apagar(&i);
    }

    free(*fila);
    *fila = NULL;
}