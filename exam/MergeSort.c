#include <stdio.h>

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

void copyArr(int arr[], int start, int end, int copy[], int startcopy) {
    while(start <= end) {
        copy[startcopy++] = arr[start++];        
    }
}

void merge(int arr[], int l, int m, int r) {
    int nl = m - l + 1;
    int nr = r - m;
    int i = 0;
    int j = 0;
    int k = 0;
    int copy[64];

    while (i < nl && j < nr) {
        if (arr[l + i] < arr[m + 1 + j]) {
            copy[k] = arr[l + i];
            i = i + 1;
        } else {
            copy[k] = arr[m + 1 + j];
            j = j + 1;
        }
        k = k + 1;
    }
    if  (i == nl) {
        copyArr(arr, m + 1 + j, r, copy, k);
    } else {
        copyArr(arr, l + i, m, copy, k);
    }
    copyArr(copy, 0, nl + nr - 1, arr, l);
}

void mergeSort(int arr[], int l, int r) {
    if (r > l) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
} 

int main() {

    int arr[] = {3, 4, 6, 1, 20, -4};
    int size = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);
    printArr(arr, size);

    return 0;
}