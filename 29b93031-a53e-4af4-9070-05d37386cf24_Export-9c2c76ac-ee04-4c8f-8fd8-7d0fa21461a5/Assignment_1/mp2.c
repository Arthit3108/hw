#include <stdio.h>

int assignzero(int array[], int size) {
  for (int i = 0; i < size; i++) {
    array[i] = 0;
  }
  return 0;
}

int checksign(int number) {

  if (number < 0) {
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
  while (number != 0 && bit < 53) {
    binaryNum[bit] = number % 2;
    number /= 2;
    bit++;
  }
  return bit;
}

int decimalpoint(double number, int binary[]) {
  int bit = 0;

  if (number == 0) {
    return 1;
  } else if (number == 1) {
    binary[bit] = 1;
    return 1;
  } else {
    while (number != 1 && bit < 64) {
      number *= 2;
      binary[bit] = (int)number;
      bit++;
      if (number >= 1) {
        number -= 1;
      }
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

int checkdecimalpoint(int maniissa[], int biint[], int bit, int size) {

  for (int i = 0; i < bit; i++) {
    if (biint[i] == 1) {
      return i;
    }
  }
  for (int i = 0; i < size; i++) {
    if (maniissa[i] == 1) {
      return i;
    }
  }
}

void display(int exponent[], int bits, int sign, int mantissa[], int size,
             int biint[], int sizeex, int indexone) {

  printf("%d ", sign);
  if (sizeex < 11) {
    for (int i = sizeex; i < 11; i++) {
      printf("0");
    }
  }
  for (int i = 0; i < sizeex; i++) {
    printf("%d", exponent[i]);
  }
  printf(" ");
  int j = 0;
  int i = 0;
  if (biint[0] == 1) {
    for (i = 1; i < bits; i++) {
      printf("%d", biint[i]);
    }
    bits = bits - 1;
    int index = 52 - bits;
    for (j = 0; j < index; j++) {
      printf("%d", mantissa[j]);
    }
  } else {
    for (j = indexone + 1; j < size; j++) {
      printf("%d", mantissa[j]);
    }
  }  
}

int main(void){
  double number, point;
  int biint[11];
  int bits;

  int exponent[11], mantissa[64];
  int sign, e, sizeex, sizema, indexone;

  printf("Enter number : ");
  scanf("%lf", &number);
  point = number - (int)number;
  assignzero(biint, 11);
  assignzero(exponent, 11);
  assignzero(mantissa, 64);

  sign = checksign(number);
  if (sign == 1)
    point = point * -1;
  bits = countNum(number, biint);
  reversearray(biint, bits);
  sizema = decimalpoint(point, mantissa);

  indexone = checkdecimalpoint(mantissa, biint, bits, sizema);

  printf("\n");
  if ((int)number == 0) {
    e = 1023 - (indexone + 1);
  } else {
    e = 1023 + (bits - (indexone + 1));
  }
  // printf("%d\n", e);

  sizeex = countNum(e, exponent);
  reversearray(exponent, sizeex);

  display(exponent, bits, sign, mantissa, sizema, biint, sizeex, indexone);

  return 0;

}