#include <stdio.h>
#include <stdlib.h>
#include "TAD_biblioteca.h"

int main(){
    tipo_livro *estante_de_livros = nova_estante_de_livros();

    cadastra_livro(estante_de_livros);
    requisita_livro(estante_de_livros, "harry potter");


    return 0;
}