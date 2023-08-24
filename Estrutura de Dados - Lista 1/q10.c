#include <stdio.h>

// Definindo a struct Moeda
struct Moeda {
    float dolares;
    float euros;
};

// Função para converter dólares para euros
float converterDolaresParaEuros(float dolares, float taxa) {
    return dolares * taxa;
}

// Função para converter euros para dólares
float converterEurosParaDolares(float euros, float taxa) {
    return euros / taxa;
}

int main() {
    struct Moeda taxaCambio = {5.30, 6.20}; // Taxas de câmbio (dólar -> real, euro -> real)

    int opcao;
    float valor;

    printf("Bem-vindo ao Conversor de Moedas!\n");

    do {
        printf("Menu:\n");
        printf("1 - Converter de Dólares para Euros\n");
        printf("2 - Converter de Euros para Dólares\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor em Dólares: $");
                scanf("%f", &valor);
                printf("Valor em Euros: €%.2f\n", converterDolaresParaEuros(valor, taxaCambio.euros));
                break;
            case 2:
                printf("Digite o valor em Euros: €");
                scanf("%f", &valor);
                printf("Valor em Dólares: $%.2f\n", converterEurosParaDolares(valor, taxaCambio.euros));
                break;
            case 3:
                printf("Até mais e boas conversões!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}