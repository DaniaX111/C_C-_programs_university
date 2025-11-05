#include <stdio.h>


int main() {
    unsigned long number1 = 0;  // Задаем первое число
    unsigned long number2 = 0;  // Задаем второе число

    printf("Введите первое число\n");
    scanf("%ld", &number1);
    printf("Введите второе число\n");
    scanf("%ld", &number2);
    printf("\n");

    int binaryGrid[32][5];  // Создаем массив 32x5 для хранения результатов
    int mask = 1;
    int bit1, bit2, andResult, orResult, xorResult;

    for (int i = 31; i >= 0; i--) {
        bit1 = (number1 & (mask << i)) ? 1 : 0;
        bit2 = (number2 & (mask << i)) ? 1 : 0;

        andResult = bit1 & bit2;
        orResult = bit1 | bit2;
        xorResult = bit1 ^ bit2;

        binaryGrid[31 - i][0] = bit1;
        binaryGrid[31 - i][1] = bit2;
        binaryGrid[31 - i][2] = andResult;
        binaryGrid[31 - i][3] = orResult;
        binaryGrid[31 - i][4] = xorResult;

    }

    // шапка таблицы
    printf("\n");
    printf("Bit 1 | Bit 2 | AND | OR | XOR\n");
    printf("------------------------------\n");

    for (int j = 0; j <= 31; j++) {
        // Выводим результаты
        printf("  %d   |   %d   |  %d  |  %d |  %d \n", binaryGrid[j][0], binaryGrid[j][1], binaryGrid[j][2], binaryGrid[j][3], binaryGrid[j][4]);
    }
    
    return 0;
}
