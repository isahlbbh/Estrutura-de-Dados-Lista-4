#include <stdio.h>

// Definindo a struct ContaBancaria
struct ContaBancaria {
    char nomeTitular[50];
    int numeroConta;
    float saldo;
};

// Função para depositar dinheiro
void depositar(struct ContaBancaria *conta, float valor) {
    conta->saldo += valor;
    printf("Depósito de %.2f realizado com sucesso.\n", valor);
}

// Função para sacar dinheiro
void sacar(struct ContaBancaria *conta, float valor) {
    if (conta->saldo >= valor) {
        conta->saldo -= valor;
        printf("Saque de %.2f realizado com sucesso.\n", valor);
    } else {
        printf("Saldo insuficiente.\n");
    }
}

// Função para verificar o saldo
float verificarSaldo(struct ContaBancaria conta) {
    return conta.saldo;
}

int main() {
    struct ContaBancaria minhaConta = {"Fulano da Silva", 12345, 1000.0};

    printf("Saldo atual: %.2f\n", verificarSaldo(minhaConta));

    depositar(&minhaConta, 500.0);
    printf("Saldo atual: %.2f\n", verificarSaldo(minhaConta));

    sacar(&minhaConta, 300.0);
    printf("Saldo atual: %.2f\n", verificarSaldo(minhaConta));

    sacar(&minhaConta, 1500.0); // Tentando sacar mais do que tem
    printf("Saldo atual: %.2f\n", verificarSaldo(minhaConta));

    return 0;
}