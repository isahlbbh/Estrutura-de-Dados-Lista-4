#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[][3], int low, int high) {
    int pivot = arr[high][0];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j][0] >= pivot) {
            i++;
            for (int k = 0; k < 3; k++) {
                swap(&arr[i][k], &arr[j][k]);
            }
        }
    }
    for (int k = 0; k < 3; k++) {
        swap(&arr[i + 1][k], &arr[high][k]);
    }
    return (i + 1);
}

void quickSort(int arr[][3], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    // Chame a função quickSort para ordenar a matriz com base na primeira coluna
    quickSort(matrix, 0, rows - 1);

    printf("Matriz ordenada:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
