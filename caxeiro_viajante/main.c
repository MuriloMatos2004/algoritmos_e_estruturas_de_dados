#include "matriz.h"
#include "melhor_caminho.h"

int main(){
    int Qtd_cidades, cidade_inicial;
    int min = __INT_MAX__;
    int *possivel_caminho, *melhor;

    scanf("%d", &Qtd_cidades);
    scanf("%d", &cidade_inicial);
    
    /*Alocando espaço na memória para guardar um possível 
    caminho e o melhor caminho*/
    possivel_caminho = malloc(Qtd_cidades*sizeof(int));
    assert(possivel_caminho);
    melhor = malloc(Qtd_cidades*sizeof(int));
    assert(melhor);

    //Inserindo os vértices em um vetor, sendo o primeiro elemento o vértice inicial
    possivel_caminho[0] = cidade_inicial - 1;
    int j = 1, sentinela = 0;
    for(int i = 1; i < Qtd_cidades; i++){
        if(j != cidade_inicial && sentinela == 0)
            possivel_caminho[j] = j -1;
        else if(sentinela == 1){
            possivel_caminho[j] = j;
        }
        else{
            possivel_caminho[j] = j;
            sentinela = 1;
        }
        j++;
    }

    //CRIANDO A MATRIZ
    MATRIZ *matriz = criar_matriz(Qtd_cidades);

    //Preenchendo matriz com as distâncias entre as cidades.
    int aux1, aux2, valor;
    for(int j = 0; j < Qtd_cidades; j++){
        for(int k = 0; k < Qtd_cidades; k++){
            if(j == k){
                inserir_na_matriz(matriz, 0, j, k, 1);
            }else{
                scanf("%d %d", &aux1, &aux2);
                scanf("%d", &valor);
                inserir_na_matriz(matriz, valor, aux1-1, aux2-1, 1);
            }
        }
    }

    //Encontrando o melhor caminho
    melhor_caminho(possivel_caminho, 1, Qtd_cidades-1, matriz, &min, melhor);

    //Imprimindo resultados
    printarray(melhor,Qtd_cidades);
    printf("\n");

    //Desalocando espaços na memória
    free(possivel_caminho);
    free(melhor);
    destruir_matriz(&matriz, Qtd_cidades);


    return 0;
}