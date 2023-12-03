#include <stdio.h>

int main() {
    double x = 0.2;
    for (int i = 0; i < 2; i++) { // ทำการ double x 2 ครั้ง
        x *= 2;
    }

    char formattedOutput[7]; // สร้าง buffer สำหรับเก็บค่าที่จัดรูปแบบแล้ว

    // จัดรูปแบบและเก็บลง buffer โดยกำหนดให้มีทั้งหมด 7 ตำแหน่งทศนิยม
    snprintf(formattedOutput, sizeof(formattedOutput), "%.7f", x);

    double formattedValue; // ตัวแปรที่เก็บค่าที่จัดรูปแบบแล้ว

    // อ่านค่าที่จัดรูปแบบแล้วจาก buffer และเก็บในตัวแปร formattedValue
    sscanf(formattedOutput, "%lf", &formattedValue);

    // ทำการคูณต่อกันได้เริ่มจากค่า formattedValue
    double result = formattedValue * 2;

    // จัดรูปแบบผลลัพธ์เพื่อให้มีทศนิยม 6 หลัก
    snprintf(formattedOutput, sizeof(formattedOutput), "%.6f", result);

    printf("%s\n", formattedOutput); // แสดงผลลัพธ์ที่คำนวณและจัดรูปแบบแล้ว
    return 0;
}
