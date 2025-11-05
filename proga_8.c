#include <stdio.h>

/*
    Вариант 10.
    Смазнов Д. Д. 605-31
    Лабораторная работа №8
*/

struct rectangle {
    float x0;
    float x;
    float y0;
    float y;
};

// ввод величин прямоугольника
struct rectangle rectEntry(struct rectangle *rect);
// сравнение величин прямоугольника
void rectLogic(struct rectangle *rect, float *x0min, float *xmax, float *y0min, float *ymax);
// вывод координат прямоугольника
void rectPrint(float x0min, float xmax, float y0min, float ymax, float *point_x, float *point_y);

// добавление элемента в массив
void rectAdd(struct rectangle *rect, int *number);
// удаление элемента из массива
void rectDelete(struct rectangle *rect, int *number);
// вставка элементов массива
void rectPaste(struct rectangle *rect1, struct rectangle *rect2, int *numberBegin, int *numberEnd);
// вывод всех элементов
void rectPrintArray(struct rectangle *rect, int *number_of_elems);
// вывод одного элемента по номеру
void rectPrintElement(struct rectangle *rect, int *number);

int main() {
    struct rectangle rect[10] = {{}, {}, {}, {}, {}, {}, {}, {}, {}, {}};
    int n = 2;

    // меню ввода
    printf("Введите количество элементов массива:\n");
    scanf("%d", &n);
    if (n < 1) {
        return 1;
    }

    int i;
    struct rectangle rect2[10] = {{0, 6, 0, 7}, {0, 8, 0, 9}, {0, 5, 0, 3}, {0, 6, 0, 10}, {-1, 2, -3, 3}, {0, 1}, {-1, 1}, {0, 0, 0, 0}, {2, 3, 4, 5}, {7, 8, 9, 10}};

    float x0min = 0;
    float xmax = 0;
    float y0min = 0;
    float ymax = 0;

    float point_x = 0;
    float point_y = 0;

    int input = 0;

    while(1) {
        printf("\nСписок команд:\n");
        printf("0-Выйти из программы\n");
        printf("1-Добавить несколько элементов в массив\n");
        printf("2-Добавить 1 элемент в массив\n");
        printf("3-Удалить элемент из массива\n");
        printf("4-Вставить элементы в массив\n");
        printf("5-Вывести 1 элемент массива\n");
        printf("6-Вывести все элементы массива\n");
        printf("7-Произвести обработку данных массива\n");
        printf("8-Вывести результаты обработки данных массива\n");
        printf("\n");
        printf("Введите номер команды:\n");
        scanf("%d", &input);

        int el_num = 0;

        switch( input ) {
            case 1:
                for(i = 0; i < n; i++) {
                    int j = i + 1;
                    printf("Ввод для прямоугольника %d:\n", j);
                    rect[i] = rectEntry(&rect[i]);
                }
                break;
            
            case 2:
                n++;
                rectAdd(&rect, &n);
                break;
            
            case 3:
                rectDelete(&rect, &n);
                if(n > 1) {
                    n--;
                }
                break;
            
            case 4:
                printf("Введите диапозон элементов\n");
                printf("первый и последний элемент:\n");
                int numBegin = 1;
                int numEnd = 2;
                scanf("%d", &numBegin);
                scanf("%d", &numEnd);
                
                rectPaste(&rect, &rect2, &numBegin, &numEnd);
                break;

            case 5:
                printf("Введите номер элемента:\n");
                scanf("%d", &el_num);
                rectPrintElement(&rect, &el_num);
                break;

            case 6:
                rectPrintArray(&rect, &n);
                break;

            case 7:
                x0min = 0;
                xmax = 0;
                y0min = 0;
                ymax = 0;

                for(i = 0; i < n; i++) {
                    rectLogic(&rect[i], &x0min, &xmax, &y0min, &ymax);
                }
                break;
            
            case 8:
                rectPrint(x0min, xmax, y0min, ymax, &point_x, &point_y);
                break;

            default:
                printf("Производится выход из программы\n");
                return 1;

        }

    }
    
    return 0;
}

struct rectangle rectEntry(struct rectangle *rect) {
        float x0 = 0;
        printf("Введите меньшую координату x прямоугольника:\n");
        scanf("%f", &x0);
        rect->x0 = x0;

        float x = 0;
        printf("Введите большую координату x прямоугольника:\n");
        scanf("%f", &x);
        rect->x = x;

        float y0 = 0;
        printf("Введите меньшую координату y прямоугольника:\n");
        scanf("%f", &y0);
        rect->y0 = y0;

        float y = 0;
        printf("Введите большую координату y прямоугольника:\n");
        scanf("%f", &y);
        rect->y = y;

        printf("\n");

        return *rect;
}

void rectLogic(struct rectangle *rect, float *x0min, float *xmax, float *y0min, float *ymax) {


    if (rect->x0 < *x0min) {
        *x0min = rect->x0;
    }
    if (rect->x > *xmax) {  
        *xmax = rect->x;

    }
    if (rect->y0 < *y0min) {
        *y0min = rect->y0;
    }
    if (rect->y > *ymax) {
        *ymax = rect->y;
    }

    

}

void rectPrint(float x0min, float xmax, float y0min, float ymax, float *point_x, float *point_y) {

    printf("Введите координаты точки x и y:\n");
    scanf("%f", point_x);
    scanf("%f", point_y);

    printf("%f\n", x0min);
    printf("%f\n", xmax);
    printf("%f\n", y0min);
    printf("%f\n", ymax);

    float xsize = xmax - x0min;
    float ysize = ymax - y0min;

    printf("rect sizes: %f x %f \n", xsize, ysize);
    
    if(xmax >= *point_x && ymax >= *point_y) {
        printf("Прямоугольник охватывает точку\n");
    } else {
        printf("Прямоугольник не охватывает точку\n");
    }
}

void rectAdd(struct rectangle *rect, int *number) {
    int counter = 0;
    while (counter < (*number - 1)) {
        counter++;
        rect++;
    }

    printf("counter: %d\n", counter);

    printf("Ввод значений для %d элемента массива:\n", *number);

    float x0 = 0;
        printf("Введите меньшую координату x прямоугольника:\n");
        scanf("%f", &x0);
        rect->x0 = x0;

        float x = 0;
        printf("Введите большую координату x прямоугольника:\n");
        scanf("%f", &x);
        rect->x = x;

        float y0 = 0;
        printf("Введите меньшую координату y прямоугольника:\n");
        scanf("%f", &y0);
        rect->y0 = y0;

        float y = 0;
        printf("Введите большую координату y прямоугольника:\n");
        scanf("%f", &y);
        rect->y = y;

        printf("\n");

}

void rectDelete(struct rectangle *rect, int *number) {
    int counter = 0;
    while (counter < (*number - 1)) {
        counter++;
        rect++;
    }

    printf("Выполняется удаление элемента массива %d\n", *number);

    rect->x0 = 0;
    rect->x = 0;
    rect->y0 = 0;
    rect->y = 0;

    printf("Удаление выполнено успешно\n\n");
}

void rectPaste(struct rectangle *rect1, struct rectangle *rect2, int *numberBegin, int *numberEnd) {
    // выставление указателя на начальный элемент 
    int counter = 0;
    while (counter < (*numberBegin - 1)) {
        counter++;
        rect1++;
    }

    for(counter; counter < *numberEnd; counter++) {

        rect1->x0 = rect2->x0;
        rect1->x = rect2->x;
        rect1->y0 = rect2->y0;
        rect1->y = rect2->y;

        rect1++;
        rect2++;

    }

}

void rectPrintArray(struct rectangle *rect, int *number_of_elems) {

    printf("Вывод элементов массива:\n\n");


    int i = 0;
    for(i; i < *number_of_elems; i++){
        int j = i + 1;
        printf("%d элемент массива:\n", j);
        printf("%f ", rect->x0);
        printf("%f ", rect->x);
        printf("%f ", rect->y0);
        printf("%f\n", rect->y);

        rect++;
    }

    printf("Вывод окончен\n");
}

void rectPrintElement(struct rectangle *rect, int *number) {
    int counter = 0;
    while (counter < (*number - 1)) {
        counter++;
        rect++;
    }

    int j = counter + 1;
    printf("Вывод элемента массива %d:\n", j);
    printf("%f ", rect->x0);
    printf("%f ", rect->x);
    printf("%f ", rect->y0);
    printf("%f\n", rect->y);


}