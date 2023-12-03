#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j + 1] < arr[j]) {
                swap(&arr[j + 1], &arr[j]);
            }
        }
    }
}

int main() {
    int array_sizes[] = {100000, 200000, 300000, 400000, 500000, 600000};
    clock_t start, end;
    double cpu_time_used;

    for (int i = 0; i < sizeof(array_sizes) / sizeof(array_sizes[0]); i++) {
        int size = array_sizes[i];
        int *arr = (int *)malloc(size * sizeof(int));

        for (int j = 0; j < size; j++) {
            arr[j] = size - j;
        }

        start = clock();
        bubbleSort(arr, size - 1);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("bubble sort %d: %f seconds\n", size, cpu_time_used);

        if (size == 100000 || size == 200000 || size == 300000 || size == 400000 || size == 500000 || size == 600000) {
            printf("Time taken for sorting %d elements: %f seconds\n", size, cpu_time_used);
        }

        free(arr);
    }

    return 0;
}
