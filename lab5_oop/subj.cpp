// === subj.cpp ===
#include "subj.h"
#include <iostream>

Transport::Transport() : fuelConsumption(0), speed(0), range(0), passengers(0), cargo(0) {}

void Transport::input() {
        std::cout << "Введите модель, тип, расход, скорость, дальность, пассажиров, груз, марку, цвет:\n";
        std::cin >> model >> type >> fuelConsumption >> speed >> range >> passengers >> cargo;

    switch(vType) {
        case CAR:
            dynamic_cast<Car*>(this)->input();
            break;
        case PLANE:
            dynamic_cast<Plane*>(this)->input();
            break;
        case SHIP:
            dynamic_cast<Ship*>(this)->input();
            break;
    }
}

void Transport::print() const{
    std::cout << "Transport: " << model << " " << type
              << ", speed: " << speed << " km/h"
              << ", range: " << range << " km"
              << ", passengers: " << passengers
              << ", cargo: " << cargo << "\n";
    
    switch(vType) {
        case CAR:
            dynamic_cast<const Car*>(this)->print();
            break;
        case PLANE:
            dynamic_cast<const Plane*>(this)->print();
            break;
        case SHIP:
            dynamic_cast<const Ship*>(this)->print();
            break;
    }
}

int Transport::getPassengers() const {
    switch(vType) {
    case CAR: {
        return passengers;
        break;
        }
    case PLANE: {
        const Plane* p = dynamic_cast<const Plane*>(this);
        return passengers + p->getCrew();
        break;
        }
    case SHIP: {
        const Ship* s = dynamic_cast<const Ship*>(this);
        return passengers + s->getCrew();;
        break;
        }
    }
}

double Transport::getCargo() const { 
    switch(vType) {
    case CAR:
        return cargo;
        break;
    case PLANE:
        return cargo * 1000; // convert tons to kg
        break;
    case SHIP:
        return cargo * 1000; // convert tons to kg
        break;
    }
}

Car::Car() {
    vType = CAR;

}

void Car::input() {
    std::cout << "Введите марку, цвет:\n";
    std::cin >> brand >> color;
}

void Car::print() const {
    std::cout << "Car: " << brand << " " << color << " " << model << " " << type << " " << speed << "km/h " << range << "km, " << passengers << " pax, " << cargo << "kg\n";
}

Plane::Plane() {
    vType = PLANE;
}

int Plane::getCrew() const {
    return crew;
}

void Plane::input() {
    std::cout << "Введите высоту, экипаж, двигатели:\n";
    std::cin >> maxAltitude >> crew >> engines;
}

void Plane::print() const {
    std::cout << "Plane: " << model << " " << type << ", speed: " << speed << "km/h, range: " << range << "km, " << passengers << " pax, cargo: " << cargo << "t, crew: " << crew << ", engines: " << engines << "\n";
}

Ship::Ship() {
    vType = SHIP;
}

int Ship::getCrew() const {
    return crew;
}

void Ship::input() {
    std::cout << "Введите название, порт, экипаж, двигатели:\n";
    std::cin >> name >> port >> crew >> engines;
}

void Ship::print() const {
    std::cout << "Ship: " << name << " from " << port << ", " << model << " " << type << ", " << speed << "km/h, range: " << range << "km, " << passengers << " pax, cargo: " << cargo << "t\n";
}
