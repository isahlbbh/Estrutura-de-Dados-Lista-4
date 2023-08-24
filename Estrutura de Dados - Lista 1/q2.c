#include <stdio.h>

// Definindo a struct Tipo
struct Tipo {
    int valorInteiro;
    float valorFlutuante;
    char letra;
};

int main() {
    // Declarando uma variável do tipo Tipo
    struct Tipo meuTipo;

    // Preenchendo os campos da struct
    meuTipo.valorInteiro = 42;
    meuTipo.valorFlutuante = 3.14;
    meuTipo.letra = 'A';

    // Imprimindo os valores da struct
    printf("Valor Inteiro: %d\n", meuTipo.valorInteiro);
    printf("Valor Flutuante: %.2f\n", meuTipo.valorFlutuante);
    printf("Letra: %c\n", meuTipo.letra);

    return 0;
}
