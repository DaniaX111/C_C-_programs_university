#pragma once

#include "./list.h"

enum machines {
    CAR,
    PLANE,
    SHIP
};

struct Transport {
    struct Item* next;
    struct Item* prev;
    
    enum machines type;
    char model[20];
    int fuel;
    int speed;
    int length;
    int passenger;
    int weight;
};

struct Car {
    struct Item* next;
    struct Item* prev;
    
    enum machines type;
    char model[20];
    int fuel;
    int speed;
    int length;
    int passenger;
    int weight;

    char name[20];
    int color;
};

struct Plane {
    struct Item* next;
    struct Item* prev;
    
    enum machines type;
    char model[20];
    int fuel;
    int speed;
    int length;
    int passenger;
    int weight;

    int max_height;
    int crew_number;
    int engines;
};

struct Ship {
    struct Item* next;
    struct Item* prev;
    
    enum machines type;
    char model[20];
    int fuel;
    int speed;
    int length;
    int passenger;
    int weight;
    
    char port_name[20];
    int crew_number;
    int engines;
};

void ShowMenu();
struct Transport* Create(const enum machines type);
void InputBase(struct Transport* transport);
void InputCar(struct Car* car);
void PrintCar(const struct Car* car);
void DeleteCar(struct Car* car);
void InputPlane(struct Plane* plane);
void PrintPlane(const struct Plane* plane);
void DeletePlane(struct Plane* plane);
void InputShip(struct Ship* ship);
void PrintShip(const struct Ship* ship);
void DeleteShip(struct Ship* ship);


