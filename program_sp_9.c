#include <stdio.h>
#include <stdlib.h>

#define MAX_RECT 100

struct rectangle {
    float x0, x, y0, y;
};

// Ввод данных прямоугольника
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
void findBoundingRect(struct rectangle *arr, int n, struct rectangle *result) {
    result->x0 = 1e9;
    result->x = -1e9;
    result->y0 = 1e9;
    result->y = -1e9;

    for (int i = 0; i < n; i++) {
        if (arr[i].x0 < result->x0) result->x0 = arr[i].x0;
        if (arr[i].x > result->x) result->x = arr[i].x;
        if (arr[i].y0 < result->y0) result->y0 = arr[i].y0;
        if (arr[i].y > result->y) result->y = arr[i].y;
    }
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

// Вставка прямоугольника по индексу
void insertRectangleAtIndex(struct rectangle *arr, int *n, int index) {
    if (*n >= MAX_RECT) {
        printf("Ошибка: превышено максимальное количество прямоугольников.\n");
        return;
    }
    if (index < 0 || index > *n) {
        printf("Ошибка: некорректный индекс.\n");
        return;
    }

    for (int i = *n; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    rectEntry(&arr[index]);
    (*n)++;
}

// Удаление прямоугольника
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

// Сохранение данных в файл
void saveToFile(struct rectangle *arr, int n) {
    char filename[256];
    printf("Введите имя файла для сохранения: ");
    scanf("%255s", filename);

    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Ошибка при открытии файла");
        return;
    }

    fwrite(&n, sizeof(int), 1, file);
    fwrite(arr, sizeof(struct rectangle), n, file);
    fclose(file);
    printf("Данные сохранены в файл %s.\n", filename);
}

// Загрузка данных из файла
void loadFromFile(struct rectangle *arr, int *n) {
    char filename[256];
    printf("Введите имя файла для загрузки: ");
    scanf("%255s", filename);

    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Ошибка при открытии файла");
        return;
    }

    fread(n, sizeof(int), 1, file);
    if (*n > MAX_RECT || *n < 0) {
        printf("Ошибка: некорректное количество данных в файле.\n");
        fclose(file);
        *n = 0;
        return;
    }

    int el_number = fread(arr, sizeof(struct rectangle), *n, file);
    if (el_number != *n) {
        printf("Ошибка: не удалось считать данные.\n");
        fclose(file);
        *n = 0;
        return;
    }
    fclose(file);
    printf("Данные загружены из файла %s.\n", filename);
}

// Уничтожение данных
void clearData(struct rectangle *arr, int *n) {
    *n = 0;
    printf("Все данные уничтожены.\n");
}

int main() {
    struct rectangle rects[MAX_RECT];
    int n = 0, choice;

    do {
        printf("\nМеню:\n");
        printf("1. Добавить прямоугольник\n");
        printf("2. Удалить прямоугольник\n");
        printf("3. Вставить прямоугольник по индексу\n");
        printf("4. Показать все прямоугольники\n");
        printf("5. Найти охватывающий прямоугольник\n");
        printf("6. Проверить точку\n");
        printf("7. Сохранить в файл\n");
        printf("8. Загрузить из файла\n");
        printf("9. Уничтожить данные\n");
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
                }
                break;
            }
            case 3: {
                int index;
                printf("Введите индекс для вставки: ");
                if (scanf("%d", &index) == 1) {
                    insertRectangleAtIndex(rects, &n, index);
                }
                break;
            }
            case 4:
                for (int i = 0; i < n; i++) {
                    printf("[%d]: ", i);
                    rectPrint(&rects[i]);
                }
                break;
            case 5: {
                struct rectangle result;
                findBoundingRect(rects, n, &result);
                rectPrint(&result);
                break;
            }
            case 6: {
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
            case 7:
                saveToFile(rects, n);
                break;
            case 8:
                loadFromFile(rects, &n);
                break;
            case 9:
                clearData(rects, &n);
                break;
            case 0:
                printf("Выход из программы.\n");
                break;
            default:
                printf("Некорректный выбор. Попробуйте снова.\n");
        }
    } while (choice != 0);

    return 0;
}
