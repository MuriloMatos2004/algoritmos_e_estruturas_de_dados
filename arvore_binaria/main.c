#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "ab.h"

int main() {
	ab_t *a = cria();
	
	insere_esq(a, 'a', -1);
	insere_esq(a, 'b', 'a');
	insere_dir(a, 'c', 'a');
	insere_esq(a, 'e', 'c');
	insere_dir(a, 'f', 'c');
	insere_esq(a, 'h', 'f');
	insere_dir(a, 'i', 'f');
	insere_dir(a, 'g', 'e');
	insere_esq(a, 'd', 'b');

	em_ordem_iterativo(a);

	pre_ordem(a);
	em_ordem(a);
	pos_ordem(a);
	
    // imprime(a);
	// remover(a, 5);
	// imprime(a);
	
	finaliza(a);
	
	return EXIT_SUCCESS;
}