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

int partition(int arr[], int l, int r) {
    int p = arr[l];
    int j = r;
    int i = l;

    while (1) {
        i = i + 1;
        while (arr[i] <= p && i <= j) {
            i++;
        }
        while (arr[j] >= p && j >= i) {
            j--;
        }
        
        if (j < i) {
            break;
        } else {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[l], &arr[j]);
    return j;
}

void quickSort(int arr[], int l, int r) {
    int s; 
    if (l < r) {
        s = partition(arr, l, r);
        quickSort(arr, l, s-1);
        quickSort(arr, s+1, r);
    }
    
}


int main() {

    int arr[] = {3, 4, 6, 1, 20, -4};
    int size = sizeof(arr)/sizeof(int);

    quickSort(arr, 0, size - 1);
    printArr(arr, size);

    return 0;
}