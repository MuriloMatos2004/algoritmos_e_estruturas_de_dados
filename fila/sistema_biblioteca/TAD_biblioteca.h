#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "fila.h"
#define TAM_ESTANTE 20

typedef struct livro tipo_livro;

tipo_livro* nova_estante_de_livros();
void cadastra_livro(tipo_livro *livro);
void requisita_livro(tipo_livro *livro, char nome_livro[50]);
void retira_livro(tipo_livro *livro);