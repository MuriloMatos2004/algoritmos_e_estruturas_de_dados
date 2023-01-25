#include <stdbool.h>

typedef struct pilha PILHA;
typedef int elem;

void push(PILHA *p, elem x);
elem pop(PILHA *p, elem x);
elem top(PILHA *p);
void create(PILHA *p);
bool IsEmpty(PILHA *p);
void esvazia_pilha(PILHA *p);

