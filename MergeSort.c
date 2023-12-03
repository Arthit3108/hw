#include <stdio.h>
#include <string.h>
#include <math.h>

void copyStr(char arr[], int indexArr, int endArr, char str[], int indexStr, int endStr) {
    while (indexArr <= endArr) {
        str[indexStr] = arr[indexArr];
        indexArr++;
        indexStr++;   
    }
}

void merge(char arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int i = 0;
    int j = 0;
    int k = 0;
    char str[64];

    while (i < n1 && j < n2) {
        if (arr[l + i] < arr[m + 1 + j]) {
            str[k] = arr[l + i];
            i = i + 1;
        } else {
            str[k] = arr[m + 1 + j];
            j = j + 1;
        }
        k = k + 1;
    }
    if (i == n1) {
        copyStr(arr, m + 1 + j, r, str, k, n1+n2-1);
    } else {
        copyStr(arr, l + i, m, str, k, n1+n2-1);
    }
    copyStr(str, 0, n1 + n2 - 1, arr, l, r);
}

void mergeSort(char str[], int l, int r) {
    
   if (r > l) {
        int m = (l + r) / 2;
        mergeSort(str, l, m);
        mergeSort(str, m+1, r);
        merge(str, l, m, r);
        printf("l = %d r = %d %s\n", l, r, str);
   }
   
}

int main() {
    char str[64] = "KINGMONGKUTUNIVERSITY";
    int size = strlen(str);
    mergeSort(str, 0, size-1);

    printf("---------------------\n Sorted \n---------------------\n");
    printf("%s", str);                  // output

    return 0;
}