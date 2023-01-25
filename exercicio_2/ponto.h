#include <stdbool.h>
#include <math.h>
typedef struct ponto_ PONTO;
PONTO *ponto_criar(float x, float y);
void ponto_apagar(PONTO **p);
bool ponto_set (PONTO *p, float x, float y);
float ponto_get_x (PONTO *p);
float ponto_get_y (PONTO *p);
void ponto_print(PONTO *p);
float distancia(PONTO*  a, PONTO* b);