#include <stdio.h>

// Função para realizar uma busca sequencial em uma matriz bidimensional
// Retorna 1 se o valor for encontrado e preenche row e col com a posição da primeira ocorrência.
// Retorna 0 se o valor não for encontrado.
int searchMatrix(int matrix[][3], int rows, int cols, int value, int *row, int *col) {
    for (*row = 0; *row < rows; (*row)++) {
        for (*col = 0; *col < cols; (*col)++) {
            if (matrix[*row][*col] == value) {
                return 1; // Valor encontrado
            }
        }
    }
    return 0; // Valor não encontrado
}

int main() {
    int rows, cols;
    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &rows);
    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0) {
        printf("Tamanho de matriz inválido.\n");
        return 1;
    }

    int matrix[rows][cols];

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int searchValue;
    printf("Digite o valor que deseja procurar: ");
    scanf("%d", &searchValue);

    int row, col;
    if (searchMatrix(matrix, rows, cols, searchValue, &row, &col)) {
        printf("Valor encontrado na posição (%d, %d)\n", row, col);
    } else {
        printf("Valor não encontrado na matriz.\n");
    }

    return 0;
}
