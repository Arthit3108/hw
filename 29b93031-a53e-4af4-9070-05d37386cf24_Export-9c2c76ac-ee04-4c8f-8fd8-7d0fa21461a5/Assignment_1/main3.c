#include <stdio.h>
#include <math.h>

int checkSign(double *number)
{
    int check = *number;
    if (check < 0) {
        *number *= -1;
        return 1;
    } else {
        return 0;
    }
}

int binary(int number, int reversedBits[]) {
    // char bits[];
    int index = 0;
    int check;
    int bits[100];

    if (number == 0) {
        printf("%d\n", number);
        return 1;
    }
    
    while (number > 0) {
        check = number % 2;
        if (check == 1) {
           bits[index++] = 1;
        } else {
           bits[index++] = 0;
        }
        
        number /= 2;    
    }
    
    // Reverse the bits
    for (int i = 0; i < index; i++) {
        reversedBits[i] = bits[(index - 1 ) - i];
    }

    return index;
}

int decimalBinary(double number, int bits[], int start) {
    
    double decimalPart = number;
    double integerpart;

    int index = start-1; 

    if (decimalPart == 0) {   
        bits[index] = 0;
        return 1;
    }
    
    while (1) {
        decimalPart *= 2;
        if (decimalPart < 1) {
            bits[index] = 0;
        } else if (decimalPart > 1) {
            decimalPart = modf(decimalPart, &integerpart);
            bits[index] = 1;   
        } else {
            bits[index] = 1;
            index++;
            break;
        }
        index++;
    }

    return index;
}

void setArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}

void putBit(int integerBit[], int decimalBit[], int indexInt) {
    int token = indexInt;
    for (int i = 0; i < indexInt-1; i++) {
        decimalBit[i] = integerBit[(i+1)];
        token--;
    }
}

int main() {

    double number;

    printf("Enter numbr : ");
    scanf("%lf", &number);

    int sign;

    sign = checkSign(&number);

    double integerPart;
    double decimalPart;

    decimalPart = modf(number, &integerPart);

    int e;
    int integerBits[100];
    int indexInt; //เก็บจำนวนหลักของ integerpart
    indexInt = binary(integerPart, integerBits);

    int mantissa[52] = {0};
    // int size = sizeof(mantissa)/sizeof(int);
    // setArray(mantissa, size);
    putBit(integerBits, mantissa, indexInt);
    decimalBinary(decimalPart, mantissa, indexInt);

    e = (indexInt - 1) + 1023;
    int exponent[11];
    binary(e, exponent);

    printf("%d ", sign);

    for (int i = 0; i < 11; i++) {
        printf("%d", exponent[i]);
    }
    printf(" ");

    for (int i = 0; i < 52; i++) {
        printf("%d", mantissa[i]);
    }

    return 0;
}