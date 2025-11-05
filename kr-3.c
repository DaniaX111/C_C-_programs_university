#include <stdio.h>
#include <math.h>

/*
    Смазнов Даниил Дмитриевич гр. 605-31
    Вариант: 15
*/

float Vichislenie(float x, float y) {
    float part1 = x * log(x);
    float part2 = y / (cos(x) - x / 3);
    float Result = part1 + part2;

    return Result;

}

void Vivod(float xmin, float xmax, float h, float y) {
    float Result = 0;
    float x = xmin;

    printf("x        f(x) \n");

    while(xmax >= x) {
        Result = Vichislenie(x, y);
        printf("%f %f", x, Result);
        printf("\n");

        x += h;
    }
  

}

int main() {
    float xmin;
    float xmax;
    float y;
    float h;

    printf("Введите xmin:\n");
    scanf("%f", &xmin);
    printf("Введите xmax:\n");
    scanf("%f", &xmax);
    printf("Введите шаг:\n");
    scanf("%f", &h);

    printf("Введите y:\n");
    scanf("%f", &y);

    printf("\n");

    if (xmax <= xmin) {
        printf("Ошибка! Введены некорректные значения xmin и xmax \n");
        return 1;
    }

    if (h > xmax) {
        printf("Ошибка! Введены некорректные значения h и xmax \n");
        return 1;
    }

    Vivod(xmin, xmax, h, y);

    return 0;
}