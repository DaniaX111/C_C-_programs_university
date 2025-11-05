#include <stdio.h>
#include <stdlib.h>

#define MAX_RECT 10

struct rectangle {
    float x0, x, y0, y; // Координаты прямоугольника
};

// Ввод данных прямоугольника с проверкой
void rectEntry(struct rectangle *rect) {
    do {
        printf("Введите координаты прямоугольника (x0, x, y0, y): ");
        if (scanf("%f %f %f %f", &rect->x0, &rect->x, &rect->y0, &rect->y) != 4) {
            printf("Ошибка ввода. Повторите попытку.\n");
            while (getchar() != '\n');
            continue;
        }
        if (rect->x0 > rect->x || rect->y0 > rect->y) {
            printf("Ошибка: левая граница должна быть меньше правой, а нижняя меньше верхней.\n");
        }
    } while (rect->x0 > rect->x || rect->y0 > rect->y);
}

// Вывод данных прямоугольника
void rectPrint(const struct rectangle *rect) {
    printf("Прямоугольник: [%.2f, %.2f] x [%.2f, %.2f]\n", rect->x0, rect->x, rect->y0, rect->y);
}

// Определение минимального охватывающего прямоугольника
struct rectangle findBoundingRect(struct rectangle *arr, int n) {
    struct rectangle result = {1e9, -1e9, 1e9, -1e9};

    for (int i = 0; i < n; i++) {
        if (arr[i].x0 < result.x0) result.x0 = arr[i].x0;
        if (arr[i].x > result.x) result.x = arr[i].x;
        if (arr[i].y0 < result.y0) result.y0 = arr[i].y0;
        if (arr[i].y > result.y) result.y = arr[i].y;
    }
    return result;
}

// Проверка, охватывает ли прямоугольник точку
int isPointInside(const struct rectangle *rect, float px, float py) {
    return (px >= rect->x0 && px <= rect->x && py >= rect->y0 && py <= rect->y);
}

// Вставка прямоугольника в массив
void insertRectangle(struct rectangle *arr, int *n) {
    if (*n >= MAX_RECT) {
        printf("Ошибка: превышено максимальное количество прямоугольников.\n");
        return;
    }
    rectEntry(&arr[*n]);
    (*n)++;
}

// Удаление прямоугольника по индексу
void deleteRectangle(struct rectangle *arr, int *n, int index) {
    if (index < 0 || index >= *n) {
        printf("Ошибка: некорректный индекс.\n");
        return;
    }
    for (int i = index; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

int main() {
    struct rectangle rects[MAX_RECT];
    int n = 0, choice;

    do {
        printf("\nМеню:\n");
        printf("1. Добавить прямоугольник\n");
        printf("2. Удалить прямоугольник\n");
        printf("3. Показать все прямоугольники\n");
        printf("4. Найти охватывающий прямоугольник\n");
        printf("5. Проверить точку\n");
        printf("0. Выход\n");
        printf("Выберите действие: ");

        if (scanf("%d", &choice) != 1) {
            printf("Некорректный ввод. Попробуйте снова.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                insertRectangle(rects, &n);
                break;

            case 2: {
                int index;
                printf("Введите индекс для удаления: ");
                if (scanf("%d", &index) == 1) {
                    deleteRectangle(rects, &n, index);
                } else {
                    printf("Некорректный ввод.\n");
                    while (getchar() != '\n');
                }
                break;
            }

            case 3:
                for (int i = 0; i < n; i++) {
                    printf("[%d]: ", i);
                    rectPrint(&rects[i]);
                }
                break;

            case 4: {
                if (n == 0) {
                    printf("Нет прямоугольников для анализа.\n");
                    break;
                }
                struct rectangle result = findBoundingRect(rects, n);
                printf("Минимальный охватывающий прямоугольник: ");
                rectPrint(&result);
                break;
            }

            case 5: {
                float px, py;
                printf("Введите координаты точки (x, y): ");
                if (scanf("%f %f", &px, &py) != 2) {
                    printf("Ошибка ввода.\n");
                    while (getchar() != '\n');
                    break;
                }
                for (int i = 0; i < n; i++) {
                    if (isPointInside(&rects[i], px, py)) {
                        printf("Точка внутри прямоугольника %d\n", i);
                    }
                }
                break;
            }

            case 0:
                printf("Выход из программы.\n");
                break;

            default:
                printf("Некорректный выбор. Попробуйте снова.\n");
        }
    } while (choice != 0);

    return 0;
}
