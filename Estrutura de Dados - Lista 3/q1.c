#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
struct Node {
    int data;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memória para o novo nó.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um elemento na lista de forma ordenada
void insertOrdered(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    struct Node* current = *head;
    struct Node* prev = NULL;

    // Encontrar a posição correta para inserção
    while (current != NULL && current->data < value) {
        prev = current;
        current = current->next;
    }

    // Inserir o novo nó na posição correta
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

// Função para imprimir a lista
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Função principal
int main() {
    struct Node* head = NULL;
    int size, value;

    // Solicitar o tamanho da lista
    printf("Digite o tamanho da lista: ");
    scanf("%d", &size);

    // Solicitar e inserir elementos na lista
    printf("Digite os elementos da lista:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &value);
        insertOrdered(&head, value);
    }

    // Imprimir a lista ordenada
    printf("Lista ordenada: ");
    printList(head);

    return 0;
}