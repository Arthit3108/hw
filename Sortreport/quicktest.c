#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int l, int r) {
    int pivot = arr[l];
    int i = l + 1;
    int j = r;

    while (1) {
        while (i <= j && arr[i] <= pivot) {
            i++;
        }
        while (i <= j && arr[j] > pivot) {
            j--;
        }
        if (j < i) {
            break;
        } else {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    if (arr[j] == arr[l] && j != l) {
        int temp = arr[l];
        arr[l] = arr[j - 1];
        arr[j - 1] = temp;
    } else {
        int temp = arr[l];
        arr[l] = arr[j];
        arr[j] = temp;
    }

    return j;
}

void quickSort(int arr[], int l, int r) {
    int stack[r - l + 1];
    int top = -1;

    stack[++top] = l;
    stack[++top] = r;

    while (top >= 0) {
        r = stack[top--];
        l = stack[top--];

        int p = partition(arr, l, r);

        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        if (p + 1 < r) {
            stack[++top] = p + 1;
            stack[++top] = r;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int array_sizes[] = {600000};
    clock_t start, end;
    double cpu_time_used;

    for (int i = 0; i < (int)(sizeof(array_sizes) / sizeof(array_sizes[0])); i++) {
        int size = array_sizes[i];
        int *arr = (int *)malloc(size * sizeof(int));

        for (int j = 0; j < size; j++) {
            arr[j] = size - j;
        }

        start = clock();
        quickSort(arr, 0, size - 1);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("QuickSort %d: %f seconds\n", size, cpu_time_used);

        if (size == 100000 || size == 200000 || size == 300000 || size == 400000 || size == 500000 || size == 600000) {
            printf("Time taken for sorting %d elements: %f seconds\n", size, cpu_time_used);
        }

        free(arr);
    }

    return 0;
}
