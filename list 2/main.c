#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "subj.h"

// Прототипы функций
void SortBySpeed(struct List* list);
void SortByRange(struct List* list);
void SearchByPassengers(struct List* list, int requiredPassengers);
void SearchByWeight(struct List* list, int requiredWeight);


int main() {
    struct List* transportList = createList();
    int choice;
    int transportType;

    while (1) {
        ShowMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct Transport* car = Create(CAR);
                if (car != NULL) {
                    InputCar((struct Car*)car);
                    Add(transportList, (struct Item*)car);
                }
                break;
            }
            case 2: {
                struct Transport* plane = Create(PLANE);
                if (plane != NULL) {
                    InputPlane((struct Plane*)plane);
                    Add(transportList, (struct Item*)plane);
                }
                break;
            }
            case 3: {
                struct Transport* ship = Create(SHIP);
                if (ship != NULL) {
                    InputShip((struct Ship*)ship);
                    Add(transportList, (struct Item*)ship);
                }
                break;
            }
            case 4: {
                printf("\nTransport List:\n");
                struct Item* current = transportList->head;
                while (current != NULL) {
                    struct Transport* transport = (struct Transport*)current;
                    switch (transport->type) {
                        case CAR: PrintCar((struct Car*)transport); break;
                        case PLANE: PrintPlane((struct Plane*)transport); break;
                        case SHIP: PrintShip((struct Ship*)transport); break;
                    }
                    current = current->next;
                }
                break;
            }
            case 5: {
                printf("Enter index to delete: ");
                int index;
                scanf("%d", &index);
                struct Item* removedItem = Remove(transportList, index);
                if (removedItem != NULL) {
                    free(removedItem);
                } else {
                    printf("Invalid index.\n");
                }
                break;
            }
            case 6: {
                SortBySpeed(transportList);
                printf("List sorted by speed and range.\n");
                break;
            }
            case 7: {
                SortByRange(transportList);
                printf("List sorted by speed and range.\n");
                break;
            }
            case 8: {
                printf("Enter required passenger capacity: ");
                int passengers;
                scanf("%d", &passengers);
                SearchByPassengers(transportList, passengers);
                break;
                
            }
            case 9: {
                printf("Enter required cargo weight: ");
                int weight;
                scanf("%d", &weight);
                SearchByWeight(transportList, weight);
                break;
            }
            case 10: {
                Clear(transportList);
                free(transportList);
                printf("Exiting program.\n");
                return 0;
            }

            default: {
                printf("Invalid choice. Try again.\n");
                break;
            }
        }
    }
    return 0;
}

void SortBySpeed(struct List* list) {
    if (list->head == NULL || list->head->next == NULL) return;

    int swapped;
    struct Item *ptr, *prev, *lptr = NULL;

    do {
        swapped = 0;
        ptr = list->head;
        prev = NULL;

        while (ptr->next != lptr) {
            struct Item* next = ptr->next;
            struct Transport* currentTransport = (struct Transport*)ptr;
            struct Transport* nextTransport = (struct Transport*)next;

            if (currentTransport->speed < nextTransport->speed) {
                // Перестановка узлов
                ptr->next = next->next;
                if (next->next) next->next->prev = ptr;

                next->next = ptr;
                next->prev = ptr->prev;

                if (ptr->prev) {
                    ptr->prev->next = next;
                } else {
                    list->head = next;  // Обновляем голову списка
                }

                ptr->prev = next;
                prev = next;
                swapped = 1;
            } else {
                prev = ptr;
                ptr = ptr->next;
            }
        }
        lptr = ptr;
    } while (swapped);

    // Обновляем `tail`
    list->tail = lptr;
}

void SortByRange(struct List* list) {
    if (list->head == NULL || list->head->next == NULL) return;

    int swapped;
    struct Item *ptr, *prev, *lptr = NULL;

    do {
        swapped = 0;
        ptr = list->head;
        prev = NULL;

        while (ptr->next != lptr) {
            struct Item* next = ptr->next;
            struct Transport* currentTransport = (struct Transport*)ptr;
            struct Transport* nextTransport = (struct Transport*)next;

            if (currentTransport->length < nextTransport->length) {
                // Перестановка узлов
                ptr->next = next->next;
                if (next->next) next->next->prev = ptr;

                next->next = ptr;
                next->prev = ptr->prev;

                if (ptr->prev) {
                    ptr->prev->next = next;
                } else {
                    list->head = next;  // Обновляем голову списка
                }

                ptr->prev = next;
                prev = next;
                swapped = 1;
            } else {
                prev = ptr;
                ptr = ptr->next;
            }
        }
        lptr = ptr;
    } while (swapped);

    // Обновляем `tail`
    list->tail = lptr;
}


void SearchByPassengers(struct List* list, int requiredPassengers) {
    if (list->head == NULL) return;

    struct Item* ptr = list->head;
    printf("\nTransports Matching Passenger Capacity:\n");
    
    while (ptr != NULL) {
        struct Transport* transport = (struct Transport*)ptr;
        
        if (transport->passenger >= requiredPassengers) {
            switch (transport->type) {
                case CAR: 
                    PrintCar((struct Car*)transport);
                    break;
                case PLANE: 
                    PrintPlane((struct Plane*)transport);
                    break;
                case SHIP: 
                    PrintShip((struct Ship*)transport);
                    break;
            }
        }
        ptr = ptr->next;
    }
}

void SearchByWeight(struct List* list, int requiredWeight) {
    if (list->head == NULL) return;

    struct Item* ptr = list->head;
    printf("\nTransports Matching Weight Capacity:\n");
    
    while (ptr != NULL) {
        struct Transport* transport = (struct Transport*)ptr;
        
        if (transport->weight >= requiredWeight) {
            switch (transport->type) {
                case CAR: 
                    PrintCar((struct Car*)transport);
                    break;
                case PLANE: 
                    PrintPlane((struct Plane*)transport);
                    break;
                case SHIP: 
                    PrintShip((struct Ship*)transport);
                    break;
            }
        }
        ptr = ptr->next;
    }
}
