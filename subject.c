#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum machines { CAR, PLANE, SHIP };

struct Item {
    struct Item* next;
    struct Item* prev;
};

struct Transport {
    struct Item* item;
    enum machines type;
    char model[20];
    int fuel;
    int speed;
    int length;
    int passenger;
};

struct Car {
    struct Transport base;
    char name[20];
    int color;
    int weight;
};

struct Plane {
    struct Transport base;
    int max_height;
    int crew_number;
    int engines;
};

struct Ship {
    struct Transport base;
    char port_name[20];
    int crew_number;
    int engines;
};

struct Transport* Create(const enum machines type) {
    struct Transport* base = NULL;
    switch (type) {
        case CAR:
            base = (struct Transport*)calloc(1, sizeof(struct Car));
            break;
        case PLANE:
            base = (struct Transport*)calloc(1, sizeof(struct Plane));
            break;
        case SHIP:
            base = (struct Transport*)calloc(1, sizeof(struct Ship));
            break;
        default:
            printf("Unknown transport type.\n");
            return NULL;
    }
    if (base != NULL) {
        base->type = type;
    }
    return base;
}

void InputBase(struct Transport* transport) {
    printf("Enter model:\n");
    scanf("%s", transport->model);

    printf("Enter fuel consumption:\n");
    scanf("%d", &transport->fuel);

    printf("Enter max speed:\n");
    scanf("%d", &transport->speed);

    printf("Enter max range:\n");
    scanf("%d", &transport->length);

    printf("Enter passenger capacity:\n");
    scanf("%d", &transport->passenger);
}

void InputCar(struct Car* car) {
    InputBase(&car->base);
    printf("Enter brand:\n");
    scanf("%s", car->name);

    printf("Enter color code:\n");
    scanf("%d", &car->color);

    printf("Enter cargo weight:\n");
    scanf("%d", &car->weight);
}

void PrintCar(const struct Car* car) {
    printf("\nCar Information:\n");
    printf("Brand: %s\n", car->name);
    printf("Color code: %d\n", car->color);
    printf("Cargo weight: %d\n", car->weight);

    printf("Model: %s\n", car->base.model);
    printf("Fuel: %d\n", car->base.fuel);
    printf("Speed: %d\n", car->base.speed);
    printf("Length: %d\n", car->base.length);
    printf("Passenger capacity: %d\n", car->base.passenger);
}

void DeleteCar(struct Car* car) {
    free(car);
}

int main() {
    struct Transport* transport = Create(CAR);
    if (transport == NULL) {
        return 1;
    }

    struct Car* car = (struct Car*)transport;
    InputCar(car);
    PrintCar(car);
    DeleteCar(car);

    return 0;
}
