#include <stdio.h>

/*
    Вариант 10.
    Смазнов Д. Д. 605-31
*/

// Структура прямоугольника
struct rectangle {
    float x0; // Левая граница
    float x;  // Правая граница
    float y0; // Нижняя граница
    float y;  // Верхняя граница
};

// Ввод величин прямоугольника с проверкой корректности
void rectEntry(struct rectangle *rect) {
    printf("Введите координаты прямоугольника (x0, x, y0, y):\n");

    int check1, check2;
    do {
        do {
            printf("Левая граница (x0): ");
            check1 = scanf("%f", &rect->x0);
            while (getchar() != '\n'); // Очистка буфера ввода
            if (check1 != 1) {
                printf("Ошибка: введены некорректные данные. Повторите ввод.\n");
            }
        } while (check1 != 1);

        do {
            printf("Правая граница (x): ");
            check2 = scanf("%f", &rect->x);
            while (getchar() != '\n'); // Очистка буфера ввода
            if (check2 != 1) {
                printf("Ошибка: введены некорректные данные. Повторите ввод.\n");
            }
        } while (check2 != 1);

        if (rect->x0 > rect->x) {
            printf("Ошибка: левая граница не может быть больше правой. Повторите ввод.\n");
        }
    } while (rect->x0 > rect->x);

    int check3, check4;
    do {
        do {
            printf("Нижняя граница (y0): ");
            check3 = scanf("%f", &rect->y0);
            while (getchar() != '\n'); // Очистка буфера ввода
            if (check3 != 1) {
                printf("Ошибка: введены некорректные данные. Повторите ввод.\n");
            }
        } while (check3 != 1);

        do {
            printf("Верхняя граница (y): ");
            check4 = scanf("%f", &rect->y);
            while (getchar() != '\n'); // Очистка буфера ввода
            if (check4 != 1) {
                printf("Ошибка: введены некорректные данные. Повторите ввод.\n");
            }
        } while (check4 != 1);

        if (rect->y0 > rect->y) {
            printf("Ошибка: нижняя граница не может быть больше верхней. Повторите ввод.\n");
        }
    } while (rect->y0 > rect->y);
}

// Сравнение и обновление границ результирующего прямоугольника
void rectLogic(const struct rectangle *rect, struct rectangle *result) {
    if (rect->x0 < result->x0) {
        result->x0 = rect->x0;
    }
    if (rect->x > result->x) {
        result->x = rect->x;
    }
    if (rect->y0 < result->y0) {
        result->y0 = rect->y0;
    }
    if (rect->y > result->y) {
        result->y = rect->y;
    }
}

// Вывод координат прямоугольника
void rectPrint(const struct rectangle *rect) {
    printf("Прямоугольник: [%.2f, %.2f] x [%.2f, %.2f]\n", rect->x0, rect->x, rect->y0, rect->y);
    printf("Размеры: ширина = %.2f, высота = %.2f\n", rect->x - rect->x0, rect->y - rect->y0);
}

// Проверка, охватывает ли прямоугольник заданную точку
int isPointInside(const struct rectangle *rect, float point_x, float point_y) {
    return (point_x >= rect->x0 && point_x <= rect->x && point_y >= rect->y0 && point_y <= rect->y);
}

int main() {
    struct rectangle rect;
    struct rectangle result = {1e9, -1e9, 1e9, -1e9}; // Инициализация крайними значениями

    int n = 0;

    // Ввод количества прямоугольников с проверкой
    while (1) {
        printf("Введите количество прямоугольников: ");
        if (scanf("%d", &n) == 1 && n > 0) {
            while (getchar() != '\n'); // Очистка буфера
            break;
        }
        printf("Ошибка: необходимо ввести корректное целое положительное число.\n");
        while (getchar() != '\n'); // Очистка буфера
    }

    for (int i = 0; i < n; i++) {
        printf("Ввод для прямоугольника %d:\n", i + 1);
        rectEntry(&rect);
        rectLogic(&rect, &result);
    }

    float point_x, point_y;
    int checkX, checkY;

    // Ввод координат точки с проверкой
    do {
        printf("Введите координаты точки (x, y):\n");
        printf("x: ");
        checkX = scanf("%f", &point_x);
        while (getchar() != '\n'); // Очистка буфера
        if (checkX != 1) {
            printf("Ошибка: некорректный ввод. Повторите попытку.\n");
        }
    } while (checkX != 1);

    do {
        printf("y: ");
        checkY = scanf("%f", &point_y);
        while (getchar() != '\n'); // Очистка буфера
        if (checkY != 1) {
            printf("Ошибка: некорректный ввод. Повторите попытку.\n");
        }
    } while (checkY != 1);

    printf("\nРезультирующий прямоугольник:\n");
    rectPrint(&result);

    if (isPointInside(&result, point_x, point_y)) {
        printf("Точка (%.2f, %.2f) находится внутри результирующего прямоугольника.\n", point_x, point_y);
    } else {
        printf("Точка (%.2f, %.2f) находится ВНЕ результирующего прямоугольника.\n", point_x, point_y);
    }

    return 0;
}
