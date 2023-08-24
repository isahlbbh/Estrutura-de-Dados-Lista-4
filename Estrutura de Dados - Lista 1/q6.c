#include <stdio.h>

// Definindo a struct Estudante
struct Estudante {
    char nome[50];
    int matricula;
    float notas[3];
};

// Função para calcular a média das notas
float calcularMedia(struct Estudante aluno) {
    float somaNotas = 0.0;
    for (int i = 0; i < 3; i++) {
        somaNotas += aluno.notas[i];
    }
    return somaNotas / 3;
}

// Função para verificar se o aluno está aprovado
int estaAprovado(struct Estudante aluno) {
    float media = calcularMedia(aluno);
    return media >= 7;
}

int main() {
    struct Estudante aluno1 = {"Fulano da Silva", 12345, {8.5, 7.0, 9.0}};
    struct Estudante aluno2 = {"Ciclana Souza", 67890, {6.5, 8.0, 7.5}};

    if (estaAprovado(aluno1)) {
        printf("%s está aprovado!\n", aluno1.nome);
    } else {
        printf("%s não está aprovado.\n", aluno1.nome);
    }

    if (estaAprovado(aluno2)) {
        printf("%s está aprovada!\n", aluno2.nome);
    } else {
        printf("%s não está aprovada.\n", aluno2.nome);
    }

    return 0;
}