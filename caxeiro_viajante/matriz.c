#include "matriz.h"

//Definição do tipo matriz
struct tipo_matriz{
    int **matriz;
    int Qtd_linhas_e_colunas;
};

//Função para criar matriz
MATRIZ *criar_matriz(int qtd_linhas_e_colunas){
    MATRIZ *m = malloc(sizeof(MATRIZ));
    assert(m != NULL);

    m->matriz = calloc(qtd_linhas_e_colunas, sizeof(int**));
    if(m->matriz == NULL)
        return NULL;
    for(int i = 0; i < qtd_linhas_e_colunas; i++){
        m->matriz[i] = calloc(qtd_linhas_e_colunas,sizeof(int *));
        if(m->matriz[i] == NULL){
            for(int j = 0; j < i; j++)
                free(m->matriz[j]);
            free(m->matriz);
            free(m);
            return NULL;
        }
    }

    return m;
}

//Função para inserir elemento na matriz
bool inserir_na_matriz(MATRIZ *m, int elemento, int i, int j, int vertices){
    assert(m != NULL);

    m->matriz[i][j] = elemento;
    if(vertices == 1)
        m->matriz[j][i] = elemento;
    return true;
}

//Função para destruir matriz
bool destruir_matriz(MATRIZ **m, int tam_matriz){
    if(*m != NULL)
        return false;
    if(m != NULL)
        return false;
    
    for(int i = 0; i < tam_matriz; i++){
        free((*m)->matriz[i]);
    }
    free((*m)->matriz);
    free(*m);
    *m = NULL;
    return true;
}

//Função para imprimir matriz
void printar_matriz(MATRIZ *m, int qtd_linhas_e_colunas){
    for(int j = 0; j < qtd_linhas_e_colunas; j++){
        for(int k = 0; k < qtd_linhas_e_colunas; k++){
            printf("%d ", m->matriz[j][k]);
        }
        printf("\n");
    }
    printf("\n");   
}

int retorna_elemento(MATRIZ *m, int i, int j){
    assert(m != NULL);

    return m->matriz[i][j];
}
