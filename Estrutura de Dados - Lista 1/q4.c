#include <stdio.h>
#include <string.h>

// Definindo a struct Contato
struct Contato {
    char nome[50];
    char telefone[15];
};

// Função para adicionar um novo contato
void adicionarContato(struct Contato agenda[], int *totalContatos) {
    if (*totalContatos < 100) {
        printf("Digite o nome do contato: ");
        scanf("%s", agenda[*totalContatos].nome);

        printf("Digite o número de telefone: ");
        scanf("%s", agenda[*totalContatos].telefone);

        (*totalContatos)++;
        printf("Contato adicionado com sucesso!\n");
    } else {
        printf("A agenda está lotada!\n");
    }
}

// Função para listar todos os contatos
void listarContatos(struct Contato agenda[], int totalContatos) {
    printf("Lista de Contatos:\n");
    for (int i = 0; i < totalContatos; i++) {
        printf("Nome: %s\n", agenda[i].nome);
        printf("Telefone: %s\n", agenda[i].telefone);
        printf("---------------\n");
    }
}

// Função para buscar um contato pelo nome
void buscarContato(struct Contato agenda[], int totalContatos, char nomeBusca[]) {
    for (int i = 0; i < totalContatos; i++) {
        if (strcmp(agenda[i].nome, nomeBusca) == 0) {
            printf("Contato encontrado:\n");
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n", agenda[i].telefone);
            return;
        }
    }
    printf("Contato não encontrado.\n");
}

int main() {
    struct Contato agenda[100];
    int totalContatos = 0;

    int opcao;
    char nomeBusca[50];

    do {
        printf("Menu:\n");
        printf("1 - Adicionar contato\n");
        printf("2 - Listar contatos\n");
        printf("3 - Buscar contato pelo nome\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato(agenda, &totalContatos);
                break;
            case 2:
                listarContatos(agenda, totalContatos);
                break;
            case 3:
                printf("Digite o nome do contato: ");
                scanf("%s", nomeBusca);
                buscarContato(agenda, totalContatos, nomeBusca);
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