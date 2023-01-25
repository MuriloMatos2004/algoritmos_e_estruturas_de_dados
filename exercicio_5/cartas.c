void cartas(int n){
    int descartados[n-1];
    ITEM *t;
    FILA *fila = fila_criar();
    for(int i = 1; i <= n; i++)
        fila_inserir(fila, item_criar(i));
    
    int contador = 0;
    while(contador < (n - 1)){
        ITEM *t = fila_remover(fila);
        descartados[contador] = item_get_chave(t);
        item_apagar(&t);

        t = fila_remover(fila);
        fila_inserir(fila,t);
        contador++;
    }

    printf("Discarded cards: ");
    for(int j = 0; j < (n - 1); j++)
        if(j == (n - 2)) printf("%d ", descartados[j]);
        else printf("%d, ", descartados[j]);
    
    printf("\nRemaining card: ");
    t = fila_remover(fila);
    int carta_que_sobrou = item_get_chave(t);
    printf("%d\n", carta_que_sobrou);

    item_apagar(&t);
    fila_apagar(&fila);
}