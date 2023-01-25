float rpn(char *sequencia){
    float resultado = 0;
    PILHA *p = pilha_criar();
    for(int i = 0; sequencia[i] != '\0'; i++){
        if(sequencia[i] == '1')
            pilha_empilhar(p,item_criar(1));
        else if(sequencia[i] == '2')
            pilha_empilhar(p,item_criar(2));
        else if(sequencia[i] == '3')
            pilha_empilhar(p,item_criar(3));
        else if(sequencia[i] == '4')
            pilha_empilhar(p,item_criar(4));
        else if(sequencia[i] == '5')
            pilha_empilhar(p,item_criar(5));
        else if(sequencia[i] == '6')
            pilha_empilhar(p,item_criar(6));
        else if(sequencia[i] == '7')
            pilha_empilhar(p,item_criar(7));
        else if(sequencia[i] == '8')
            pilha_empilhar(p,item_criar(8));
        else if(sequencia[i] == '9')
            pilha_empilhar(p,item_criar(9));

        if(sequencia[i] == '/') {
            ITEM *i = pilha_desempilhar(p);
            ITEM *j = pilha_desempilhar(p);
            resultado = item_get_chave(j) / item_get_chave(i);
            pilha_empilhar(p, item_criar(resultado));
            item_apagar(&i);
            item_apagar(&j);
        }
        else if(sequencia[i] == '*') {
            ITEM *i = pilha_desempilhar(p);
            ITEM *j = pilha_desempilhar(p);
            resultado = item_get_chave(j) * item_get_chave(i);
            pilha_empilhar(p, item_criar(resultado));
            item_apagar(&i);
            item_apagar(&j);
        }
        else if(sequencia[i] == '+') {
            ITEM *i = pilha_desempilhar(p);
            ITEM *j = pilha_desempilhar(p);
            resultado = item_get_chave(j) + item_get_chave(i);
            pilha_empilhar(p, item_criar(resultado));
            item_apagar(&i);
            item_apagar(&j);
        }
        else if(sequencia[i] == '-') {
            ITEM *i = pilha_desempilhar(p);
            ITEM *j = pilha_desempilhar(p);
            resultado = item_get_chave(j) - item_get_chave(i);
            pilha_empilhar(p, item_criar(resultado));
            item_apagar(&i);
            item_apagar(&j);
        }
        // printf("i: %d \n", i);
        // pilha_print(p);
        // printf("\n");
    }

    pilha_apagar(&p);
    return resultado;
}