#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int size) {
    int i, j;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j+1] < arr[j]) {
                swap(&arr[j+1], &arr[j]);
            }
        }
    }
}

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}


int main() {

    int arr[] = {5, 8, 6, 1, 7, 9, 2, 0, 3, 4};
    int size = sizeof(arr)/sizeof(int);

    printf("ID : 65070501061\n");
    printf("BubbleSort : ");
    bubbleSort(arr, size);
    printArr(arr, size);

    return 0;
}
