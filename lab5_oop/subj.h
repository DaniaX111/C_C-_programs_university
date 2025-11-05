// === subj.h ===
#ifndef SUBJ_H
#define SUBJ_H

#include "list.h"
#include <string>

enum VehicleType { CAR, PLANE, SHIP };

class Transport : public Item {
protected:
    VehicleType vType;
    std::string model, type;
    double fuelConsumption;
    double speed;
    double range;
    int passengers;
    double cargo;

public:
    Transport();
    void input();
    void print() const;

    double getSpeed() const { return speed; }
    double getRange() const { return range; }
    int getPassengers() const;
    double getCargo() const;
};

class Car : public Transport {
private:
    std::string brand, color;

public:
    Car();
    void input();
    void print() const;
};

class Plane : public Transport {
private:
    double maxAltitude;
    int crew;
    int engines;

public:
    Plane();
    int getCrew() const;
    void input();
    void print() const;
};

class Ship : public Transport {
private:
    std::string name, port;
    int crew;
    int engines;

public:
    Ship();
    int getCrew() const;
    void input();
    void print() const;
};

#endif

// Доделать input и output в классах наследниках ---
// getPassenger и getCargo - отдельные методы + 
// унаследовать ListSubj от List 
