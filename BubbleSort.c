#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int size) {
    int i, j, k;
    for ( i = 0; i < size; i++) {
        for ( j = 0; j < size-i; j++) {
            if (arr[j+1] < arr[j]) {
                swap(&arr[j+1], &arr[j]);
            }
        }
    } 

    for ( k = 0; k < size; k++) {
        printf("%d ", arr[k]);
    }
    
}

int main() {


    int size = sizeof(arr1)/sizeof(arr[0]);
    bubbleSort(arr1, size);

    return 0;
}