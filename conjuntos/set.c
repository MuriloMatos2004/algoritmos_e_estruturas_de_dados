#include "set.h"
#include <stdbool.h>

// Estrutura do nó.
struct no{
    ITEM *info;
    NO *esq, *dir;
    int altura;
};

// Estrutura do conjunto.
struct set{
    NO *raiz;
};

// Função criar conjunto.
SET *set_criar(){
    SET *T = (SET *) malloc(sizeof(SET));
    T->raiz = NULL;
    return T;
}

// Função auxiliar de união de conjuntos.
void unir(NO *n, SET *C){
    /*Se o nó não for nulo, insere o elemento no conjunto C e chama
      recursão para as subárvores da esquerda e da direita.  */
    if(n != NULL){
        // se o elemento ainda não estiver presente no conjunto C,
        // cria uma cópia do item passado como parâmetro
        // (não é usado o mesmo item para não criar conflito entre os ponteiros,
        // o que leva a problemas ao apagar os conjuntos)
        if(!set_pertence(C, n->info)){
            ITEM *copia = criar_item(get_valor(n->info));
            set_inserir(C, copia);
        }
        unir(n->esq, C);
        unir(n->dir, C);
    }
}

// Função que gera a união de dois conjuntos.
SET *set_uniao(SET *A, SET *B){
    /*Cria o conjunto união C e chama a função de união para as
      raízes de A e de B.*/
    SET *C = set_criar();
    unir(A->raiz, C);
    unir(B->raiz, C);
    return C;
}

// Função que gera a intersecção de dois conjuntos.
SET *set_interseccao(SET *A, SET *B){
    /*Cria um conjunto intersecção C e chama a função intersecção
      passando a raíz do conjunto A e o conjunto B como parâmetros.*/
    SET *C = set_criar(); 
    interseccao(A->raiz, B, C);
    return C;
}

// Função auxiliar da intersecção.
void interseccao(NO *a, SET *B, SET *C){
    /*Se o nó a for diferente de nulo e se o item desse nó pertencer
      ao conjunto B, esse nó é inserido em um terceiro conjunto C, que
      será o conjunto intersecção. Depois disso, chama-se a recursão 
      para as subárvores da esquerda e da direita.*/
    if(a != NULL){
        if(set_pertence(B, a->info)){
            // mesmo procedimento usado na função unir()
            if(!set_pertence(C, a->info)){
                ITEM *copia = criar_item(get_valor(a->info));
                set_inserir(C, copia);
            }
        }
        interseccao(a->esq, B, C);
        interseccao(a->dir, B, C);
        
    }
}

//Função que retorna a altura de um nó.
int altura(NO *n){
    if(n == NULL){
        return 0;
    }
    return n->altura;
}

//Função para criar um nó.
NO *no_criar(ITEM *item){
    NO *n = (NO *) malloc(sizeof(NO));
    if(n != NULL){
        n->info = item;
        n->esq = NULL;
        n->dir = NULL;
        n->altura = 1; //O nó é inicialmente adicionado como uma folha.
        return n;
    }
    return NULL;
}

// Retorna o máximo entre dois valores.
int max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

// Rotaciona uma subárvore para a esquerda.
NO *rotacionar_esq(NO *x){
    // x é o nó a ser rotacionado, e y é o nó que será colocado em seu lugar.
    NO *y = x->dir;
    // n_filho, que era filho de y, agora será filho de x.
    NO *n_filho = y->esq; 

    y->esq = x; // x passa a ser o filho da esquerda de y.
    x->dir = n_filho; // A subárvore à esquerda de y passa a ser a subárvore à direita de x.
    
    // Atualiza a altura dos nós.
    x->altura = max(altura(x->dir), altura(x->esq)) + 1;
    y->altura = max(altura(y->esq), altura(y->esq)) + 1;

    return y; // Retorna o novo nó raiz da subárvore rotacionada.
}

// Rotaciona uma subárvore para a direita.
NO *rotacionar_dir(NO *x){
    // x é o nó a ser rotacionado, e y é o nó que será colocado em seu lugar.
    NO *y = x->esq;
    // n_filho, que era filho de y, agora será filho de x.
    NO *n_filho = y->dir; 
    
    y->dir = x; // x passa a ser o filho da direita de y.
    x->esq = n_filho; // A subárvore à direita de y passa a ser a subárvore à esquerda de x.
    
    // Atualiza a altura dos nós.
    x->altura = max(altura(x->dir), altura(x->esq)) + 1;
    y->altura = max(altura(y->esq), altura(y->esq)) + 1;

    return y; // Retorna o novo nó raiz da subárvore rotacionada.
}

// Função auxiliar para imprimir elementos de uma árvore (percurso em-ordem)
void imprimir_aux(NO *n){
	if(n != NULL) {
		imprimir_aux(n->esq);
		printf("%d, ", get_valor(n->info));
		imprimir_aux(n->dir);
	}
}

// Função para imprimir um conjunto.
void set_imprimir(SET *s){
    if(s != NULL){
        imprimir_aux(s->raiz);
        //printf("\n");
    }
    printf("\n");
}

// Insere elementos em um conjunto, utilizando uma função auxiliar.
bool set_inserir(SET *s, ITEM *elemento){
    if(s == NULL){
        return false;
    }
    s->raiz = inserir_no_aux(s->raiz, elemento);
    return true;
}

//Calcula o fator de balanceamento de um nó.
int calcular_fb(NO *n){
    if(n == NULL){
        return 0;
    }
    return altura(n->esq) - altura(n->dir);
}

//Função auxiliar para inserir um novo item num conjunto.
NO *inserir_no_aux(NO *n, ITEM *item){
    //Se o nó passado como parâmetro for nulo,
    //significa que foi encontrada a posição correta para o item a ser inserido, então é criado um novo nó
    if(n == NULL){
        return no_criar(item);
    }
    //Senão, continua a função

    //Se o valor do item a ser inserido na árvore for menor que o valor do nó atual, faz a inserção à esquerda deste
    if(get_valor(item) < get_valor(n->info)){
        n->esq = inserir_no_aux(n->esq, item);
    }
    //Se for menor, faz a inserção à direita do nó atual
    else if(get_valor(item) > get_valor(n->info)){
        n->dir = inserir_no_aux(n->dir, item);
    }
    //Se for igual, significa que o item já está presente na árvore, então retorna o próprio nó
    else{
        return n;
    }

    //A função só chega aqui se o novo item foi inserido a esquerda ou à direita do nó atual
    //Nesse caso, a altura do nó atual (pai do nó inserido) deve ser atualizada, pois pode ter aumentado
    n->altura = 1 + max(altura(n->esq), altura(n->dir));

    //Faz o balanceamento da árvore após a inserção do novo nó
    //Rotação Direita-Direita
    if (calcular_fb(n) > 1 && calcular_fb(n->esq) >= 0){
        return rotacionar_dir(n);
    }

    // Rotação Esquerda-Esquerda
    if (calcular_fb(n) < -1 && calcular_fb(n->dir) <= 0){
        return rotacionar_esq(n);
    }  

    // Rotação Esquerda-Direita
    if (calcular_fb(n) > 1 && calcular_fb(n->esq) < 0){
        n->esq = rotacionar_esq(n->esq);
        return rotacionar_dir(n);
    }
  
    // Rotação Direita-Esquerda
    if (calcular_fb(n) < -1 && calcular_fb(n->dir) > 0){
        n->dir = rotacionar_dir(n->dir);
        return rotacionar_esq(n);
    }

    // Se a árvore já estiver balanceada, apenas retorna o nó atual, pai do nó inserido
    return n;
}

// Função auxiliar para deletar um item de um conjunto.
NO *deletar_no_aux(NO *n, ITEM *item){
    // Se o nó passado como parâmetro for nulo já no início da função, retorna ele próprio
    if (n == NULL)
        return NULL;
    // Senão, continua a função
    // Se o valor a ser excluído for menor que do nó atual, então ele está na subárvore da esquerda
    if (get_valor(item) < get_valor(n->info)){
        n->esq = deletar_no_aux(n->esq, item);
    }
  
    // Se for maior que o valor do nó atual, está na subárvore da direita
    else if(get_valor(item) > get_valor(n->info)){
        n->dir = deletar_no_aux(n->dir, item);   
    }
    // Se for igual, então o nó a ser deletado foi encontrado
    else{
        //Caso em que o nó possui um ou nenhum filho
        if((n->esq == NULL) || (n->dir == NULL)){
            NO *aux;
            //Se o filho da esquerda for nulo, o auxiliar será igual ao filho da direita
            if(n->esq == NULL){
                aux = n->dir;
            }
            //Senão, o auxiliar será igual ao filho da esquerda
            else{
                aux = n->esq;
            }
            
            //Esse caso acontecerá quando n->esq e n->dir forem nulos,
            //isto é, quando n não tiver filhos
            if(aux == NULL){
                aux = n;
                n = NULL;
            }
            //Se n tiver um de seus filhos, o conteúdo desse filho será copiado em n
            else{
                set_valor((n->info), get_valor(aux->info));
            }
            apagar_item(&(aux->info));
            //Finalmente, o auxiliar é excluído
            free(aux);
        }

        //Caso em que o nó possui ambos os filhos
        else{
            //O nó antecessor do nó a ser excluído é encontrado e armazenado num nó auxiliar
            NO *aux = no_maior_valor(n->esq);
            //O conteúdo do nó antecessor é copiado em n
            set_valor((n->info), get_valor(aux->info));
            //Por fim, o nó antecessor é excluído
            n->esq = deletar_no_aux(n->esq, aux->info);
        }
    } 
    // Se a função chegou até aqui e n for nulo,
    // significa que ele se tornou nulo depois da execução dos comandos acima,
    // o que ocorrerá apenas se ele não tiver nenhum filho
    if (n == NULL){
        return n;
    }
    // A função só chega aqui se o item removido estiver à esquerda ou à direita do nó atual
    // nesse caso, a altura do nó atual deve ser atualizada, pois pode ter diminuído
    n->altura = 1 + max(altura(n->esq), altura(n->dir));
  
    // Faz o balanceamento da árvore após a remoção do nó
    // rotação Direita-Direita
    if (calcular_fb(n) > 1 && calcular_fb(n->esq) >= 0){
        return rotacionar_dir(n);
    }
    // Rotação Esquerda-Esquerda
    if (calcular_fb(n) < -1 && calcular_fb(n->dir) <= 0){
        return rotacionar_esq(n);
    }  
    //Rotação Esquerda-Direita
    if (calcular_fb(n) > 1 && calcular_fb(n->esq) < 0){
        n->esq = rotacionar_esq(n->esq);
        return rotacionar_dir(n);
    }
  
    //Rotação Direita-Esquerda
    if (calcular_fb(n) < -1 && calcular_fb(n->dir) > 0){
        n->dir = rotacionar_dir(n->dir);
        return rotacionar_esq(n);
    }
    //Se a árvore já estiver balanceada, apenas retorna o nó atual, pai do nó removido
    return n;
}

// Função para remover elemento de um conjunto.
bool set_remover(SET *s, ITEM *elemento){
    if(s == NULL){
        return false;
    }
    s->raiz = deletar_no_aux(s->raiz, elemento);
    apagar_item(&elemento);
    return true;
}

// Função auxiliar para buscar nó.
ITEM *buscar_aux(NO *n, ITEM *chave){
    // se o nó não existir retorna NULL
    if(n == NULL){
        return NULL;
    }
    else{
        // se a chave for menor que a raiz, faz a busca na subárvore esquerda
        if(get_valor(chave) < get_valor(n->info)){
            return buscar_aux(n->esq, chave);
        }

        // se a chave for maior que a raiz, faz a busca na subárvore direita
        else if(get_valor(chave) > get_valor(n->info)){
            return buscar_aux(n->dir, chave);
        }

        // se a chave for igual à do nó passado como raiz, retorna o item correspondente
        else{
            return n->info;
        }
    }
}

// Função que verifica o pertencimento de um elemento no conjunto.
bool set_pertence(SET *A, ITEM *elemento){
    ITEM *res = buscar_aux(A->raiz, elemento);
    if(res != NULL){
        return true;
    }
    return false;
}

// Função auxiliar para apagar um conjunto
void apagar_aux(NO *n){
    if(n != NULL){
        apagar_aux(n->esq);
        apagar_aux(n->dir);
        apagar_item(&(n->info));
        free(n);
    }
}

// Função para apagar um conjunto.
void set_apagar(SET **s){
    apagar_aux((*s)->raiz);
    free(*s);
    *s = NULL;
}

// Encontra o maior valor de uma subárvore
NO *no_maior_valor(NO *n){
    NO *atual = n;

    while(atual->dir != NULL){
        atual = atual->dir;
    }

    return atual;
}