#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "subj.h"

void ShowMenu() {
    printf("\nMenu:\n");
    printf("1. Create Car\n");
    printf("2. Create Plane\n");
    printf("3. Create Ship\n");
    printf("4. Print Details\n");
    printf("5. Delete Transport\n");
    printf("6. Sort by speed\n");
    printf("7. Sort by range\n");
    printf("8. Search by passenger capacity\n");
    printf("9. Search by weight\n");
    printf("10. Exit\n");
    printf("Enter your choice: ");
}

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
    InputBase((struct Transport*)car);
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

    printf("Model: %s\n", car->model);
    printf("Fuel: %d\n", car->fuel);
    printf("Speed: %d\n", car->speed);
    printf("Length: %d\n", car->length);
    printf("Passenger capacity: %d\n", car->passenger);
}

void DeleteCar(struct Car* car) {
    free(car);
}

void InputPlane(struct Plane* plane) {
    InputBase((struct Transport*)plane);
    printf("Enter max flight height:\n");
    scanf("%d", &plane->max_height);

    printf("Enter number of crew members:\n");
    scanf("%d", &plane->crew_number);

    printf("Enter number of engines:\n");
    scanf("%d", &plane->engines);
}

void PrintPlane(const struct Plane* plane) {
    printf("\nPlane Information:\n");
    printf("Max flight height: %d\n", plane->max_height);
    printf("Crew members: %d\n", plane->crew_number);
    printf("Engines: %d\n", plane->engines);

    printf("Model: %s\n", plane->model);
    printf("Fuel: %d\n", plane->fuel);
    printf("Speed: %d\n", plane->speed);
    printf("Length: %d\n", plane->length);
    printf("Passenger capacity: %d\n", plane->passenger);
}

void DeletePlane(struct Plane* plane) {
    free(plane);
}

void InputShip(struct Ship* ship) {
    InputBase((struct Transport*)ship);
    printf("Enter port name:\n");
    scanf("%s", ship->port_name);

    printf("Enter number of crew members:\n");
    scanf("%d", &ship->crew_number);

    printf("Enter number of engines:\n");
    scanf("%d", &ship->engines);
}

void PrintShip(const struct Ship* ship) {
    printf("\nShip Information:\n");
    printf("Port name: %s\n", ship->port_name);
    printf("Crew members: %d\n", ship->crew_number);
    printf("Engines: %d\n", ship->engines);

    printf("Model: %s\n", ship->model);
    printf("Fuel: %d\n", ship->fuel);
    printf("Speed: %d\n", ship->speed);
    printf("Length: %d\n", ship->length);
    printf("Passenger capacity: %d\n", ship->passenger);
}

void DeleteShip(struct Ship* ship) {
    free(ship);
}

// int main() {
//     struct Transport* transport = NULL;
//     int choice;
//     int transportType = -1;

//     while (1) {
//         ShowMenu();
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 transport = Create(CAR);
//                 if (transport != NULL) {
//                     InputCar((struct Car*)transport);
//                     transportType = CAR;
//                 }
//                 break;
//             case 2:
//                 transport = Create(PLANE);
//                 if (transport != NULL) {
//                     InputPlane((struct Plane*)transport);
//                     transportType = PLANE;
//                 }
//                 break;
//             case 3:
//                 transport = Create(SHIP);
//                 if (transport != NULL) {
//                     InputShip((struct Ship*)transport);
//                     transportType = SHIP;
//                 }
//                 break;
//             case 4:
//                 if (transport == NULL) {
//                     printf("No transport created yet.\n");
//                 } else if (transportType == CAR) {
//                     PrintCar((struct Car*)transport);
//                 } else if (transportType == PLANE) {
//                     PrintPlane((struct Plane*)transport);
//                 } else if (transportType == SHIP) {
//                     PrintShip((struct Ship*)transport);
//                 }
//                 break;
//             case 5:
//                 if (transport == NULL) {
//                     printf("No transport to delete.\n");
//                 } else if (transportType == CAR) {
//                     DeleteCar((struct Car*)transport);
//                 } else if (transportType == PLANE) {
//                     DeletePlane((struct Plane*)transport);
//                 } else if (transportType == SHIP) {
//                     DeleteShip((struct Ship*)transport);
//                 }
//                 transport = NULL;
//                 transportType = -1;
//                 printf("Transport deleted.\n");
//                 break;
//             case 6:
//                 if (transport != NULL) {
//                     if (transportType == CAR) DeleteCar((struct Car*)transport);
//                     else if (transportType == PLANE) DeletePlane((struct Plane*)transport);
//                     else if (transportType == SHIP) DeleteShip((struct Ship*)transport);
//                 }
//                 printf("Exiting program.\n");
//                 return 0;
//             default:
//                 printf("Invalid choice. Try again.\n");
//                 break;
//         }
//     }
// }
