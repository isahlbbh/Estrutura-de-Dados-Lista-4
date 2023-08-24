#include <stdio.h>
#include <string.h>
#include <time.h>

// Definindo a struct Funcionario
struct Funcionario {
    char nome[100];
    char cargo[50];
    float salario;
    struct tm dataAdmissao; // Data de admissão
};

// Função para dar um aumento de salário
void darAumento(struct Funcionario *funcionario, float percentual) {
    float aumento = funcionario->salario * (percentual / 100);
    funcionario->salario += aumento;
    printf("%s recebeu um aumento de %.2f%%!\n", funcionario->nome, percentual);
    printf("Novo salário: R$%.2f\n", funcionario->salario);
}

// Função para calcular quanto tempo o funcionário está na empresa
int calcularTempoNaEmpresa(struct Funcionario funcionario) {
    time_t now;
    time(&now);
    double segundos = difftime(now, mktime(&funcionario.dataAdmissao));
    int anos = segundos / (60 * 60 * 24 * 365);
    return anos;
}

int main() {
    struct Funcionario funcionario1 = {"Fulano da Silva", "Desenvolvedor", 3500.0, {2020 - 1900, 8, 15}};
    struct Funcionario funcionario2 = {"Ciclana Souza", "Gerente", 6000.0, {2018 - 1900, 3, 10}};

    printf("Olá, funcionários!\n");

    darAumento(&funcionario1, 10);
    darAumento(&funcionario2, 7);

    printf("Tempo de empresa de %s: %d anos\n", funcionario1.nome, calcularTempoNaEmpresa(funcionario1));
    printf("Tempo de empresa de %s: %d anos\n", funcionario2.nome, calcularTempoNaEmpresa(funcionario2));

    return 0;
}