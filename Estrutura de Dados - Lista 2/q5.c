#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void insertionSortMatrix(int matrix[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        insertionSort(matrix[i], cols);
    }
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

    // Chame a função insertionSortMatrix para ordenar a matriz
    insertionSortMatrix(matrix, rows, cols);

    printf("Matriz ordenada:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
