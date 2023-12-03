#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char str[], int l, int r) {
    int p = str[l];
    int j = r;
    int i = l;

    while (1) {   // repeat
        i = i + 1;
        while(str[i] <= p && i <= j  ) {        // repeat untill A[i] >= p
            i++;
        } 
        while (str[j] >= p && j >= i) {         // repeat untill A[j] <= p
            j--; 
        }

        if (j < i) {       // repeat untill i >= j
            break;
        } else {
            printf("swap : %c %c\n", str[i], str[j]);
            swap(&str[i], &str[j]);  //swap(A[i], A[j])
            printf("%s\n", str);
        }
    }
    printf("swap : %c %c\n", str[i], str[j]);
    swap(&str[l], &str[j]);  //swap(A[l], A[j])
    printf("%s\n", str);
    return j;
}

void qiuckSort(char str[], int l, int r) {
    int s;
    if (l < r) {
        s = partition(str, l, r);
        qiuckSort(str, l, s - 1);
        qiuckSort(str, s+1, r);
    }
}

int main() {
    char str[64] = "KINGMONGKUTUNIVERSITY";
    int size = strlen(str);
    printf("%s\n", str);
    qiuckSort(str, 0, size - 1);        // send array to sort;
    printf("---------------------\n Sorted \n---------------------\n");
    printf("%s", str);                  // output

    return 0;
}