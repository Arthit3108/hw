#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

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
        if (check == 1)
        {
           bits[index++] = 1;
        }
        else {
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

int decimalBinary(double number, int bits[]) {
    
    double decimalPart = number;
    double integerpart;

    int index = 0; 
    // index < 5
    if (decimalPart == 0)
    {   
        bits[index] = 0;
        return 1;
    }
    
    while (1)
    {
        decimalPart *= 2;
        if (decimalPart < 1) {
            bits[index] = 0;
            // decimalPart *= 2;
        }
        else if (decimalPart > 1) {
            decimalPart = modf(decimalPart, &integerpart);
                // decimalPart *= 2;
            bits[index] = 1;   
        }
        else {
                bits[index] = 1;
                index++;
                break;
        }
        index++;
    }

    return index;
}

void arrToInt(int bits[], unsigned long long *number, int index) {
    unsigned long long temp = 0;
    unsigned long long binary = 0;
    int j = index;
    for (int i = 0; i < index; i++)
    {
        temp = bits[i] * (1 * pow(10, j - 1));
        binary += temp;
        j--;
    }
    *number = binary;
}

void strArrToInt(int bits[], int index, long long *number) {
   
    int temp;
    char bit;
    char str[100];
    for (int i = 0; i < index; i++)
    {
        temp = bits[i];
        bit = temp + '0';  // convert to char
        str[i] = bit;
    }
    str[index] = '\0';  // last character of str
    printf("\nthis is strArrtoint%s ", str);

    *number = strtoll(str, NULL, 10); // convert str to int
}

void strArrTodec(int bits[], int index, long double *number) {
   
    int temp;
    char bit;
    char str[100];
    for (int i = 0; i < index; i++)
    {
        temp = bits[i];
        bit = temp + '0';  // convert to char
        str[i] = bit;
    }
    str[index] = '\0';  // last character of str
    printf("\nthis is strArrtoint%s ", str);

    *number = strtold(str, NULL); // convert str to long double
}

void arrToDec(int bits[], long double *number, int index) {
    
    int temp;
    char bit;
    char str[100] = {'0', '.'};

    int j = index;

    for (int i = 0; i < index; i++)
    {
        temp = bits[i];
        bit = temp + '0';  // convert to char
        str[i+2] = bit;
    }
    str[index+2] = '\0';  // last character of str
    printf("\n%s", str);

    *number = strtold(str, NULL); // convert str to long double
}

int splitPoint(long double *number, int index)
{
    int e;
    index = index - 1;
    *number = *number * (1.0 * pow(10, (-index)));
    // printf("%lf", *number);

    e = index + 1023;
    return e;
}

int checkSign(double *number)
{
    int check = *number;
    if (check < 0)
    {
        *number *= -1;
        return 1;
    }
    else {
        return 0;
    }
}

void doubleToStr(long double bits) {
    char str[54];
    char *mantissa;
    snprintf(str, sizeof(str), "%.52Lf", bits);
    mantissa = strtok(str, ".");
    mantissa = strtok(NULL, ".");
    printf(" %s", mantissa);
}

int main() {

    double number;

    printf("Enter number: ");
    scanf("%lf", &number);

    int sign;

    sign = checkSign(&number);


    double integerPart;
    double decimalPart;

    decimalPart = modf(number, &integerPart);

    int integerBits[100];
    int indexInt; //เก็บจำนวนหลักของ integerpart
    indexInt = binary(integerPart, integerBits);

    int decimalBits[100];
    int indexDec;
    indexDec = decimalBinary(decimalPart, decimalBits);
    printf("integerBits\n");
    for (int i = 0; i < indexInt; i++)
    {
        printf("%d", integerBits[i]);
    }

    printf("\n");
    printf("decimalBits\n");
    for (int i = 0; i < indexDec; i++)
    {
        printf("%d", decimalBits[i]);
    }

    // int Bits;
    long long intBits;
    strArrToInt(integerBits, indexInt, &intBits);

    long double decBits;
    arrToDec(decimalBits, &decBits, indexDec);

    long double allBinary;
    allBinary = intBits + decBits;

    int e;
    int e_index;
    int bitsOfe[100];

    e = splitPoint(&allBinary, indexInt);
    e_index = binary(e, bitsOfe);

    long long exponent;
    strArrToInt(bitsOfe, e_index, &exponent);

    // printf("\nint bit %lld", intBits);
    // printf("\n dec bits %Lf", decBits);
    // printf("\nallBinary %.20Lf", allBinary);
    long double mantissa;
    mantissa = modf(allBinary, &integerPart);
    doubleToStr(mantissa);
    

    printf("\n%d ", sign);
    printf("%lld ", exponent);
    // printf("%Lf", mantissa);
    doubleToStr(mantissa);
    // printf("%d", exponent);
    
    return 0;
}