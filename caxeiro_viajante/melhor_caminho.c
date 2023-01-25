#include "melhor_caminho.h"

//Função para imprimir o array
void printarray(int possivel_caminho[], int size){
    int i,j;

    for(i=0; i<size; i++){
        printf("%d ",possivel_caminho[i] + 1);
    }
    printf("%d ",possivel_caminho[0] + 1);
}

//Função de troca, usada na permutação
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//Função que encontra o melhor caminho
bool melhor_caminho(int *array, int start, int end, MATRIZ *m, int *min, int *best_path){
    int soma = 0, j;      
    if(start==end){
       for(j=0; j<end; j++){
            soma += retorna_elemento(m, array[j], array[j+1]);
            if(retorna_elemento(m, array[j], array[j+1]) == 0)
                return false;
        }
        soma += retorna_elemento(m, array[j], array[0]);
        if(retorna_elemento(m, array[j], array[0]) == 0)
            return false;

        if(soma < *min){
            *min = soma;
            
            for(int k=0; k < end+1; k++){
                best_path[k] = array[k];
            }
        }
    }


    for(int i=start;i<=end;i++){
        //Trocando os números
        swap((array+i), (array+start));
        //Fixando um digito e permutando os demais    
        melhor_caminho(array, start+1, end, m, min, best_path);
        swap((array+i), (array+start));
    }
}