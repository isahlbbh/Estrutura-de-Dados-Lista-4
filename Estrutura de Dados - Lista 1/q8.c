#include <stdio.h>
#include <string.h>

// Definindo a struct Produto
struct Produto {
    char nome[100];
    float preco;
    int quantidadeEstoque;
};

// Função para comprar produtos
void comprarProduto(struct Produto *produto, int quantidade) {
    if (produto->quantidadeEstoque >= quantidade) {
        float totalCompra = produto->preco * quantidade;
        produto->quantidadeEstoque -= quantidade;
        printf("Compra realizada com sucesso!\n");
        printf("Total da compra: R$%.2f\n", totalCompra);
    } else {
        printf("Estoque insuficiente.\n");
    }
}

int main() {
    struct Produto produto1 = {"Camiseta", 29.90, 50};
    struct Produto produto2 = {"Calça Jeans", 99.90, 30};

    printf("Bem-vindo à nossa loja virtual!\n");

    int opcao, quantidade;
    do {
        printf("Menu:\n");
        printf("1 - Comprar %s\n", produto1.nome);
        printf("2 - Comprar %s\n", produto2.nome);
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Quantidade desejada: ");
                scanf("%d", &quantidade);
                comprarProduto(&produto1, quantidade);
                break;
            case 2:
                printf("Quantidade desejada: ");
                scanf("%d", &quantidade);
                comprarProduto(&produto2, quantidade);
                break;
            case 3:
                printf("Até mais e boas compras!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}