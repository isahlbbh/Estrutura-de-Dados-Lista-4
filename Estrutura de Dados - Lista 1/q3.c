#include <stdio.h>
#include <math.h>

// Definindo a struct Ponto
struct Ponto {
    float x;
    float y;
};

// Função para calcular a distância entre dois pontos
float calcularDistancia(struct Ponto p1, struct Ponto p2) {
    float deltaX = p2.x - p1.x;
    float deltaY = p2.y - p1.y;
    return sqrt(deltaX * deltaX + deltaY * deltaY);
}

// Função para calcular a inclinação da reta entre dois pontos
float calcularInclinacao(struct Ponto p1, struct Ponto p2) {
    return (p2.y - p1.y) / (p2.x - p1.x);
}

int main() {
    struct Ponto ponto1 = {2.0, 3.0};
    struct Ponto ponto2 = {5.0, 7.0};

    // Calculando a distância entre os pontos
    float distancia = calcularDistancia(ponto1, ponto2);
    printf("Distância entre os pontos: %.2f\n", distancia);

    // Calculando a inclinação da reta
    float inclinacao = calcularInclinacao(ponto1, ponto2);
    printf("Inclinação da reta: %.2f\n", inclinacao);

    return 0;
}
