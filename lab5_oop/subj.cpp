#include "subj.h"
#include <iostream>

using namespace std;

// --- Transport ---
Transport::Transport()
    : fuelConsumption(0), speed(0), range(0), passengers(0), cargo(0) {}

void Transport::input() {
    cout << "Введите модель, тип, расход, скорость, дальность, пассажиров, груз:\n";
    cin >> model >> type >> fuelConsumption >> speed >> range >> passengers >> cargo;
}

void Transport::print() const {
    cout << model << " " << type
         << ", speed: " << speed << " km/h"
         << ", range: " << range << " km"
         << ", passengers: " << passengers
         << ", cargo: " << cargo << "\n";
}

int Transport::getPassengers() const {
    switch(vType) {
        case CAR: return passengers;
        case PLANE: return passengers + dynamic_cast<const Plane*>(this)->getCrew();
        case SHIP: return passengers + dynamic_cast<const Ship*>(this)->getCrew();
    }
    return 0;
}

double Transport::getCargo() const {
    switch(vType) {
        case CAR: return cargo;
        case PLANE: return cargo * 1000; // т -> кг
        case SHIP: return cargo * 1000;
    }
    return 0;
}

// --- Car ---
Car::Car() { vType = CAR; }

void Car::input() {
    Transport::input();  // базовые поля
    cout << "Введите марку, цвет:\n";
    cin >> brand >> color;
}

void Car::print() const {
    cout << "Car: " << brand << " " << color << " " 
         << model << " " << type << " "
         << speed << "km/h " << range << "km, "
         << passengers << " pax, " << cargo << "kg\n";
}

// --- Plane ---
Plane::Plane() { vType = PLANE; }

int Plane::getCrew() const { return crew; }

void Plane::input() {
    Transport::input();
    cout << "Введите высоту, экипаж, двигатели:\n";
    cin >> maxAltitude >> crew >> engines;
}

void Plane::print() const {
    cout << "Plane: " << model << " " << type
         << ", speed: " << speed << "km/h, range: " << range << "km, "
         << passengers << " pax, cargo: " << cargo << "t, "
         << "crew: " << crew << ", engines: " << engines << "\n";
}

// --- Ship ---
Ship::Ship() { vType = SHIP; }

int Ship::getCrew() const { return crew; }

void Ship::input() {
    Transport::input();
    cout << "Введите название, порт, экипаж, двигатели:\n";
    cin >> name >> port >> crew >> engines;
}

void Ship::print() const {
    cout << "Ship: " << name << " from " << port << ", "
         << model << " " << type << ", "
         << speed << "km/h, range: " << range << "km, "
         << passengers << " pax, cargo: " << cargo << "t\n";
}
