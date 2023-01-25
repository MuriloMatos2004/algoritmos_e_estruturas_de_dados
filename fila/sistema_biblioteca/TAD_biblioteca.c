#include "TAD_biblioteca.h"


struct livro{
    char nome[50];
    int disponibilidade;
    tipo_fila *fila_espera;
};

tipo_livro* nova_estante_de_livros(){
    tipo_livro *livros = malloc(TAM_ESTANTE*sizeof(tipo_livro));
    assert(livros != NULL);
    return livros;
}

void cadastra_livro(tipo_livro *livro){
    assert(livro != NULL);
    int sentinela = 0;
    for(int i = 0; i < TAM_ESTANTE; i++){
        printf("Digite o nome do livro: ");
        scanf("%[^\n]%*c", livro->nome);
        livro[i].disponibilidade = 0;
        livro[i].fila_espera = criar_fila();
        printf("\nDigite 1 para parar: ");
        scanf("%d", &sentinela);
        if(sentinela == 1)
            break;
    }
}

void retira_livro(tipo_livro *livro){
    char nome[50];
    livro->disponibilidade = 1;
    printf("INFORMACOES SOBRE O LIVRO:\n");
    printf("nome: %s\n", livro->nome);
    printf("livro disponivel!\n");
    printf("digite seu nome para o cadastro: ");
    scanf("%s", nome);
    inserir(livro->fila_espera, &nome[0]);
}

void requisita_livro(tipo_livro *livro, char nome_livro[50]){
    assert(livro != NULL);
    char nome[50];
    for(int i = 0; i < TAM_ESTANTE; i++){
        get_valor(livro[i].fila_espera);
        if(strcmp(livro[i].nome, nome_livro) == 0){
            if(livro[i].disponibilidade == 0){
                retira_livro(&livro[i]);
            }
            else{
                printf("INFORMACOES SOBRE O LIVRO:\n");
                printf("nome: %s\n", livro[i].nome);
                printf("livro indisponivel :(\n");
                //printf("nome do atual possuidor do livro: \n", get_valor(livro[i].fila_espera));
                printf("digite seu nome para entrar na fila: ");
                scanf("%s", nome);
                inserir(livro[i].fila_espera, &nome[0]);
            }           
        }
        else{
            printf("livro nao existe na estante!\n");
        }
    }
}

void esvaziar_estante(tipo_livro *livros){
    assert(livros != NULL);
    free(livros);
}

