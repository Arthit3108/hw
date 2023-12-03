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
}

void bubbleSort(int arr[], int size) {
    int i, j;
    
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - i; j++) {
            if (arr[j + 1] < arr[j]) {
                swap(&arr[j+1], &arr[j]);
            }
        }
    }
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
        arr[j + 1] = temp;
    }

    printArr(arr, size);
}
int main() {
    int arr[] = {20, 10, 5, 6, 19, 2, 0}; 
    int size = sizeof(arr)/sizeof(int);

    // bubbleSort(arr, size);
    // selectionSort(arr, size);
    insertionSort(arr, size);

    return 0;
}