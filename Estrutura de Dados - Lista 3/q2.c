#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do nó da lista
struct Product {
    char name[50];
    int quantity;
    struct Product* next;
};

// Função para criar um novo nó
struct Product* createProductNode(char name[], int quantity) {
    struct Product* newNode = (struct Product*)malloc(sizeof(struct Product));
    if (newNode == NULL) {
        printf("Erro ao alocar memória para o novo nó.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->name, name, sizeof(newNode->name));
    newNode->quantity = quantity;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um produto na lista de compras de forma ordenada
void insertOrdered(struct Product** head, char name[], int quantity) {
    struct Product* newNode = createProductNode(name, quantity);
    struct Product* current = *head;
    struct Product* prev = NULL;

    // Encontrar a posição correta para inserção
    while (current != NULL && strcmp(current->name, name) < 0) {
        prev = current;
        current = current->next;
    }

    // Inserir o novo produto na posição correta
    if (prev == NULL) {
        // Inserir no início da lista
        newNode->next = *head;
        *head = newNode;
    } else {
        // Inserir no meio ou no final da lista
        newNode->next = current;
        prev->next = newNode;
    }
}

// Função para imprimir a lista de compras
void printShoppingList(struct Product* head) {
    struct Product* current = head;
    while (current != NULL) {
        printf("%s (%d) -> ", current->name, current->quantity);
        current = current->next;
    }
    printf("NULL\n");
}

// Função principal
int main() {
    struct Product* shoppingList = NULL;
    int size, quantity;
    char name[50];

    // Solicitar o tamanho da lista
    printf("Digite o tamanho da lista de compras: ");
    scanf("%d", &size);

    // Solicitar e inserir produtos na lista de compras
    printf("Digite os produtos da lista de compras:\n");
    for (int i = 0; i < size; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", name);
        printf("Quantidade: ");
        scanf("%d", &quantity);
        insertOrdered(&shoppingList, name, quantity);
    }

    // Imprimir a lista de compras ordenada
    printf("Lista de compras ordenada: ");
    printShoppingList(shoppingList);

    return 0;
}