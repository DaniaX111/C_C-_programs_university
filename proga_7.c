#include <stdio.h>

/*
    Вариант 10.
    Смазнов Д. Д. 605-31
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
void rectPrint(float x0min, float xmax, float y0min, float ymax, float point_x, float point_y);

int main() {
    struct rectangle rect[10] = {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}};
    int n = 0;

    printf("Введите размер массива:\n");
    scanf("%d", &n);

    int i;
    for(i = 0; i < n; i++) {
        int j = i + 1;
        printf("Ввод для прямоугольника %d:\n", j);
        rect[i] = rectEntry(&rect[i]);
    }
    
    float x0min = 0;
    float xmax = 0;
    float y0min = 0;
    float ymax = 0;

    float point_x;
    float point_y;

    printf("Введите координаты точки x и y:\n");
    scanf("%f", &point_x);
    scanf("%f", &point_y);

    for(i = 0; i < n; i++) {

        rectLogic(&rect[i], &x0min, &xmax, &y0min, &ymax);
    }

    rectPrint(x0min, xmax, y0min, ymax, point_x, point_y);
    
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

void rectPrint(float x0min, float xmax, float y0min, float ymax, float point_x, float point_y) {

    printf("%f\n", x0min);
    printf("%f\n", xmax);
    printf("%f\n", y0min);
    printf("%f\n", ymax);

    float xsize = xmax - x0min;
    float ysize = ymax - y0min;

    printf("rect sizes: %f x %f \n", xsize, ysize);

    if(xmax >= point_x && ymax >= point_y) {
        printf("Прямоугольник охватывает точку\n");
    } else {
        printf("Прямоугольник не охватывает точку\n");
    }
}