#include <stdio.h>

void float_to_binary_ieee754(float number) {
     int *bits = (int *)&number;

    printf("IEEE 754 binary representation: ");
    
    for (int i = 31; i >= 0; i--) {
        printf("%d", (*bits >> i) & 1);
        if (i == 31 || i == 23) {
            printf(" ");
        }
    }
    
    printf("\n");
}

int main() {
    float number;
    printf("Enter a floating-point number: ");
    scanf("%f", &number);
    
    float_to_binary_ieee754(number);
    
    return 0;
}
