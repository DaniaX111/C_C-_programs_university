#include <stdlib.h>
#include <stdio.h>

#include "./list.h"
#include "./subj.h"

int main() {
    struct List* list = createList();
    struct Transport* car = Create(CAR);
    struct Transport* plane = Create(PLANE);
    struct Transport* ship = Create(SHIP);

    if (car != NULL) {
        printf("Создание автомобиля:\n");
        Input(car);
        Add(list, (struct Item*)car);
    }

    if (plane != NULL) {
        printf("Создание самолёта:\n");
        Input(plane);
        Add(list, (struct Item*)plane);
    }

    if (ship != NULL) {
        printf("Создание корабля:\n");
        Input(ship);
        Add(list, (struct Item*)ship);
    }

    printf("Список транспортных средств:\n");
    print_list(list);

    Clear(list);
    free(list);

    return 0;
}