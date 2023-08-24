#include <stdio.h>
#include <string.h>

// Definindo a struct Livro
struct Livro {
    char titulo[100];
    char autor[50];
    int anoPublicacao;
};

// Função para adicionar um novo livro
void adicionarLivro(struct Livro biblioteca[], int *totalLivros) {
    if (*totalLivros < 100) {
        printf("Digite o título do livro: ");
        scanf(" %[^\n]s", biblioteca[*totalLivros].titulo);

        printf("Digite o autor do livro: ");
        scanf(" %[^\n]s", biblioteca[*totalLivros].autor);

        printf("Digite o ano de publicação: ");
        scanf("%d", &biblioteca[*totalLivros].anoPublicacao);

        (*totalLivros)++;
        printf("Livro adicionado com sucesso!\n");
    } else {
        printf("A biblioteca está lotada!\n");
    }
}

// Função para listar todos os livros
void listarLivros(struct Livro biblioteca[], int totalLivros) {
    printf("Lista de Livros:\n");
    for (int i = 0; i < totalLivros; i++) {
        printf("Título: %s\n", biblioteca[i].titulo);
        printf("Autor: %s\n", biblioteca[i].autor);
        printf("Ano de Publicação: %d\n", biblioteca[i].anoPublicacao);
        printf("---------------\n");
    }
}

// Função para buscar livros por autor
void buscarLivroPorAutor(struct Livro biblioteca[], int totalLivros, char autorBusca[]) {
    printf("Livros do autor %s:\n", autorBusca);
    int encontrados = 0;
    for (int i = 0; i < totalLivros; i++) {
        if (strcmp(biblioteca[i].autor, autorBusca) == 0) {
            printf("Título: %s\n", biblioteca[i].titulo);
            printf("Ano de Publicação: %d\n", biblioteca[i].anoPublicacao);
            printf("---------------\n");
            encontrados++;
        }
    }
    if (encontrados == 0) {
        printf("Nenhum livro encontrado desse autor.\n");
    }
}

int main() {
    struct Livro biblioteca[100];
    int totalLivros = 0;

    int opcao;
    char autorBusca[50];

    do {
        printf("Menu:\n");
        printf("1 - Adicionar livro\n");
        printf("2 - Listar livros\n");
        printf("3 - Buscar livros por autor\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarLivro(biblioteca, &totalLivros);
                break;
            case 2:
                listarLivros(biblioteca, totalLivros);
                break;
            case 3:
                printf("Digite o nome do autor: ");
                scanf(" %[^\n]s", autorBusca);
                buscarLivroPorAutor(biblioteca, totalLivros, autorBusca);
                break;
            case 4:
                printf("Até logo!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}