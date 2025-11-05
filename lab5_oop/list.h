#ifndef LIST_H
#define LIST_H

#include <iostream>

class Transport;  // forward declaration

class Item {
protected:
    Item* next;
    Item* prev;

public:
    class List* list;

    Item();
    virtual ~Item();

    Item* getNext() const { return next; }
    Item* getPrev() const { return prev; }
    void setNext(Item* n) { next = n; }
    void setPrev(Item* p) { prev = p; }
    virtual void print() const = 0;  // если хотите, чтобы List знал про print()
};

class List {
protected:
    Item* head;
    Item* tail;

public:
    List();
    ~List();

    void add(Item* item);
    Item* remove(int index);
    void Delete(int index);
    void clear();
    int count() const;
    void print() const;
    int getIndex(Item* item) const;
    Item* getItem(int index) const;
    void insert(Item* item, int index);

    // void sortBySpeed();
    // void sortByRange();
    // void searchByPassengers(int minP);
    // void searchByCargo(double minC);
};

class SubjList : public List {
    public:
        void sortBySpeed();
        void sortByRange();
        void searchByPassengers(int minP);
        void searchByCargo(double minC);
};

#endif
