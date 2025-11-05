#include <stdio.h>

void Volume_rect(int *x, int *y, int *z, int *Volume) {
    printf("Введите значение числа x:\n");
    scanf("%d", x);
    printf("Введите значение числа y:\n");
    scanf("%d", y);
    printf("Введите значение числа z:\n");
    scanf("%d", z);
    printf("\n");

    *Volume = *x * *y * *z;
    printf("Объем равен: %d\n", *Volume);
}

void Square_rect(int *x, int *y, int *Square) {
    printf("Введите значение числа x:\n");
    scanf("%d", x);
    printf("Введите значение числа y:\n");
    scanf("%d", y);

    *Square = *x * *y;
    printf("Площадь равна: %d\n", *Square);
}

int main() {
    int x;
    int y;
    int z;
    int r;

    const float Pi = 3.1416;

    int Volume;
    int Square;
    int C;
    
    Volume_rect(&x, &y, &z, &Volume);
    Square_rect(&x, &y, &Square);


    printf("Введите значение числа r:\n");
    scanf("%d", &r);
    printf("\n");

    C = 2 * Pi * r;
    printf("Длина окружности равнв: %d\n", C);
    Square = Pi * r * r;
    printf("Площадь равна: %d\n", Square);
    
    return 0;
}