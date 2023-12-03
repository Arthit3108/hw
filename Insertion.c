#include <stdio.h>

void insertionSort(int arr[], int size) {

    int i, v, j, k;

    for (i = 1; i < size; i++) {
        v = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > v) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = v;
    }

    // for ( k = 0; k < size; k++) {
    //     printf("%d ", arr[k]);
    // }
}

int main() {

    int arr[] = {1, 3, 5, 6, 4, 2, 10, 22, -3};
    insertionSort(arr, sizeof(arr)/sizeof(arr[0]));

    return 0;
}