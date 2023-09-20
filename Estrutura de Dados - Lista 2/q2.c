#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Função para preencher um array com números aleatórios
void fillArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
}

// Função para fazer uma cópia de um array
void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

// Função de ordenação por bolha
void bubbleSort(int arr[], int n) {
    // Implementação do Bubble Sort (conforme fornecida anteriormente)
    // ...
}

// Função de ordenação Quick Sort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Função de ordenação Merge Sort
void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int leftArray[n1], rightArray[n2];

    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int main() {
    srand(time(NULL));

    int sizes[] = {1000, 5000, 10000, 50000, 100000}; // Tamanhos dos arrays
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int arr[n];
        int arr_copy[n];

        // Preenche o array com números aleatórios
        fillArray(arr, n);
        copyArray(arr, arr_copy, n); // Faz uma cópia do array para manter os dados originais

        // Mede o tempo de execução do Bubble Sort
        clock_t start_time = clock();
        bubbleSort(arr, n);
        clock_t end_time = clock();
        double bubbleSortTime = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        // Faz a mesma coisa para o Quick Sort
        copyArray(arr_copy, arr, n);
        start_time = clock();
        qsort(arr, n, sizeof(int), compare);
        end_time = clock();
        double quickSortTime = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        // Faz a mesma coisa para o Merge Sort
        copyArray(arr_copy, arr, n);
        start_time = clock();
        mergeSort(arr, 0, n - 1);
        end_time = clock();
        double mergeSortTime = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        printf("Tamanho do array: %d\n", n);
        printf("Tempo de execução do Bubble Sort: %.6f segundos\n", bubbleSortTime);
        printf("Tempo de execução do Quick Sort: %.6f segundos\n", quickSortTime);
        printf("Tempo de execução do Merge Sort: %.6f segundos\n", mergeSortTime);
        printf("\n");
    }

    return 0;
}
