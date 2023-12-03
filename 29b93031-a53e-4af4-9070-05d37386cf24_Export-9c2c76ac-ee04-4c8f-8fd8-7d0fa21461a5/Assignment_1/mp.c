    #include <stdio.h>

    int checksign(double *number) {
        int check = *number;
    if (*number < 0) {
        *number *= -1;
        return 1;
    } else {
        return 0;
    }
    }

    int countNum(int number, int binaryNum[]) {
    int bit = 0;
    int check;

    if (number == 0) {
        return 1;
    }
    while (number > 0) {
        binaryNum[bit] = number % 2;
        number /= 2;
        bit++;
    }
    return bit;
    }

    int decimalpoint(double number, int binary[], int index) {
    int bit = 0;
    int bipoint = 0;

    number *= 2;
    if (number == 0) {
        return 1;
    } else if (number == 1) {
        binary[bit] = 1;
        return 1;
    } else { 
        while (bit < 60) {
        bipoint = number;
        binary[bit + (index - 1)] = bipoint;
        number -= bipoint;
        number *= 2;
        bit++;
        }
    }
    return bit;
    }

    void reversearray(int binary[], int bits) {

    int j = bits - 1;
    int temp[bits];
    for (int i = 0; i < bits; i++) {
        temp[i] = binary[i];
    }
    for (int i = 0; i < bits; i++) {
        binary[i] = temp[j];
        j--;
    }
    }

    void display(int exponent[], int sign, int mantissa[], int indexOne) {
    int check, count;

    printf("%d ", sign);

    for (int i = 0; i < 11; i++) {
        printf("%d", exponent[i]);
    }
    printf(" ");

    for (int i = indexOne; i < 52 + indexOne; i++) {
        printf("%d", mantissa[i]);
    }
    }
    
int searchBits(int decimalbit[]) {
    int index = 0;
    while (1) {
        if (decimalbit[index] == 1){
            index++;
            return index;
        }
        index++;
    }
    return index;
}

void insertBit(int binary, int mantissa,int index) {
    index -= 1;
    for (int i = 0; i < index; i++) {
        mantissa[i] = binary[i+1];
    }
    
}
    int main(void) {
    double number, point;
    int biint[11];
    int bits;

    int exponent[12] = {0};
    int mantissa[60] = {0};
    int sign, e, sizeex, sizema;

    printf("Enter number : ");
    scanf("%lf", &number);
    sign = checksign(&number);

    int copyNumber = number; 
    point = number - (int)number;

    bits = countNum(number, biint);
    reversearray(biint, bits);

    insertBit()

    // if (sign == 0) {
    //     e = 1023 + (bits - 1);
    // } else {
    //     e = 1023 + (bits -1) ;
    // }
    sizema = decimalpoint(point, mantissa);

    int oneBits = 0;
    oneBits = searchBits(mantissa);
    if (copyNumber > 0)
    {
        e = 1023 + (bits - 1);
        sizeex = countNum(e, exponent);
        reversearray(exponent, sizeex);
    } else {
        e = (oneBits * -1) + 1023;
        sizeex = countNum(e, exponent);
        reversearray(exponent, (sizeex + oneBits));
    }



    display(exponent, sign, mantissa, oneBits);
    
    return 0;
    
    }