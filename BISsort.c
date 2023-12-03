#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - i; j++) {
            if (arr[j+1] < arr[j]) {
                swap(&arr[j+1], &arr[j]);
            }
        }
    }
    printf("Bubble Sort\n");
    printArr(arr, size);
}

void selectionSort(int arr[], int size) {
    int i, j, min;
    for (i = 0; i < size; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
    }

    printf("Selection Sort\n");
    printArr(arr, size);
}

void insertionSort(int arr[], int size) {
    int i, j, temp;
    for (i = 1; i < size; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = temp; 
    }
    printf("Insertion Sort\n");
    printArr(arr, size);
}

int main() {
    int arr[] = {2, 4, 1, 10, 40, -49, -2, 7};
    int arr1[] = {2, 4, 1, 10, 40, -49, -2, 7};
    int arr2[] = {2, 4, 1, 10, 40, -49, -2, 7};
    int size = sizeof(arr) / sizeof(int);

    bubbleSort(arr, size);
    selectionSort(arr1, size);
    insertionSort(arr2, size);

    return 0;
}