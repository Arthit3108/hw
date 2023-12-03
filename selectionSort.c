#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int size) {
    int min, i, j, k;

    for (i = 0; i < size; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }   
        }
        swap(&arr[i], &arr[min]);
    }

    for (k = 0; k < size; k++) {
        printf("%d ", arr[k]);
    } 
}

int main() {

    int arr[] = {1, 3, 5, 6, 4, 2, 10, 22, -3};
    int size = sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr, size);

    return 0;
}