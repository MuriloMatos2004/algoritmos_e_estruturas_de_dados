#include <stdio.h>
#include "ponto.h"
#include "circulo.h"

int main(){
    float x_ponto, y_ponto;
    float x_circulo, y_circulo;
    int raio;
    scanf("%f", &x_ponto);
    scanf("%f", &y_ponto);
    scanf("%f", &x_circulo);
    scanf("%f", &y_circulo);
    scanf("%d", &raio);
    PONTO *ponto = ponto_criar(x_ponto, y_ponto);
    PONTO *centro_circulo = ponto_criar(x_circulo, y_circulo);
    CIRCULO *circulo = circulo_criar(centro_circulo, raio);
    ponto_print(ponto);
    printf("Circulo: Centro (%.1f, %.1f), ", ponto_get_x(centro_circulo), ponto_get_y(centro_circulo));
    printf("Raio = %.1f\n", (float)circulo_get_raio(circulo));
    ponto_apagar(&ponto);
    circulo_apagar(&circulo);

    return 0;
}