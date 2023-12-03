#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int binary(int number, char bits[]) {
    // char bits[];
    int index = 0;
    int check;
    char str[12];

    if (number == 0) {
        printf("%d\n", number);
        return;
    }
    
    while (number > 0) {
        check = number % 2;
        if (check == 1)
        {
           str[index++] = '1';
        }
        else {
           str[index++] = '0';
        }
        
        number /= 2;    
    }

    int length = strlen(str);

    // Reverse the string
    for (int i = 0; i < length; i++) {
        bits[i] = str[length - 1 - i];
    }

    printf("%s", bits);
    printf("\n");
    return index;
}

void decimalBinary(double number, char bits[]) {
    int index = 0; 
    // int bits[54];
    int checkRepeat = 0;
    double check[54];
    double decimalPart = number;
    double integerpart;
    int count = 0;

   
    check[0] = number;

    // index < 5
    while (checkRepeat != 1)
    {
         for (int i = 0; i < count; i++) {
            if (fabs(check[i] - decimalPart) < 1e-10) { // Using a tolerance-based comparison
                checkRepeat = 1;
                break;
            }
        }
        
        decimalPart *= 2;
        if (decimalPart < 1) {
            bits[index] = '0';
            // decimalPart *= 2;
            check[index+1] = decimalPart;
        }
        else if (decimalPart > 1) {
            decimalPart = modf(decimalPart, &integerpart);
            check[index+1] = decimalPart;
                // decimalPart *= 2;
            bits[index] = '1';   
        }
        else {
                bits[index] = '1';
                index++;
                break;
        }
        index++;
        count++;
    }

    printf("%s", bits);
    
}

double splitPoint(double *number, int index)
{
    int e;
    index = index - 1;
    *number = *number * (1.0 * pow(10, (-index)));
    // printf("%lf", *number);

    e = index + 1023;
    return e;
}

void checkSign(double *number, char sign[])
{
    int check = *number;
    if (check < 0)
    {
        sign[0] = '1';
        *number *= -1;
    }
    else {
        sign[0] = '0';
    }
}

void fillZero(int blank)
{
    for (int i = 0; i < 52-blank; i++)
    {
        printf("0");
    }
    printf("\n");
}

int main() {
    // double number = 12.45;
    double decimalPart;
    double integerPart;
    double number;

    double binaryBits;

    int index;
    int e;

    // int position; 

    char integerBits[11+1];
    char decimalBits[32];

    char compoundBits[64];

    char exponent[11+1];
    char token[52+1];   // stored mantissa
    char sign[1+1];
    char *mantissa;

    // int arraySize = sizeof(bits) / sizeof(char);

    printf("Enter Float Number: ");
    scanf("%lf", &number);

    checkSign(&number, sign);
    decimalPart = modf(number, &integerPart);

    index = binary(integerPart, integerBits);

    decimalBinary(decimalPart, decimalBits);

    printf("\n");
    printf("Integer part: %.0lf\n", integerPart);
    printf("Decimal part: %.2lf\n", decimalPart);

    // strcat(compoundBits, integerBits)
    // strcat(compoundBits, ".");
    // strcat(compoundBits, decimalBits);

    sprintf(compoundBits, "%s%s%s", integerBits, ".", decimalBits);

    binaryBits = strtod(compoundBits, NULL);

    // fabs(binaryBits) < 1e-10;

    e = splitPoint(&binaryBits, index);

    binary(e, exponent);
    sprintf (token, "%lf", binaryBits);

    mantissa = strtok (token, ".");
    mantissa = strtok(NULL, ".");

    
    int blank = strlen(mantissa);
    

    printf("%s\n", integerBits);
    printf("%s\n", decimalBits);

    printf("%s", sign);
    printf(" %s", exponent);
    printf(" %s", mantissa);
    fillZero(blank);



 
    
    return 0;

}
