#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
    // емкости
    float condOne, condTwo, condThree;
    // соединения
    float parallel, sequential;
    float mixed1, mixed2, mixed3, mixed4, mixed5, mixed6;

    printf("Введите ёмкость 1-го конденсатора:\n");
    scanf("%f", &condOne);
    printf("Введите ёмкость 2-го конденсатора:\n");
    scanf("%f", &condTwo);
    printf("Введите ёмкость 3-го конденсатора:\n");
    scanf("%f", &condThree);

    parallel = condOne + condTwo + condThree;
    sequential = 1 / ((1 / condOne) + (1 / condTwo) + (1 / condThree));

    mixed1 = 1 / (1 / condOne + 1 / (condTwo + condThree));
    mixed2 = 1 / (1 / condTwo + 1 / (condOne + condThree));
    mixed3 = 1 / (1 / condThree + 1 / (condTwo + condTwo));
    mixed4 = condOne + 1 / (1 / condTwo + 1 / condThree);
    mixed5 = condTwo + 1 / (1 / condOne + 1 / condThree);
    mixed6 = condThree + 1 / (1 / condOne + 1 / condTwo);


    printf("Возможные варианты ёмкости:\n");
    printf("Параллельное соединение: %f\n", parallel);
    printf("Последовательное соединение: %f\n", sequential);
    printf("Варианты смешанных соединений:\n");
    printf("Вариант 1: %f\n", mixed1);
    printf("Вариант 2: %f\n", mixed2);
    printf("Вариант 3: %f\n", mixed3);
    printf("Вариант 4: %f\n", mixed4);
    printf("Вариант 5: %f\n", mixed5);
    printf("Вариант 6: %f\n", mixed6);

    system("pause");

    return 0;
}
