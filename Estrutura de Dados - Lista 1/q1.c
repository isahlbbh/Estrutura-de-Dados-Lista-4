#include <stdio.h>

// Definindo a struct Pessoa
struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};

int main() {
    // Declarando uma variável do tipo Pessoa
    struct Pessoa pessoa1;

    // Preenchendo os campos da struct
    strcpy(pessoa1.nome, "Fulano");
    pessoa1.idade = 25;
    pessoa1.altura = 1.75;

    // Imprimindo os valores da struct
    printf("Nome: %s\n", pessoa1.nome);
    printf("Idade: %d anos\n", pessoa1.idade);
    printf("Altura: %.2fcm\n", pessoa1.altura);

    return 0;
}