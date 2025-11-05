#include "list.h"
#include "subj.h"
#include <iostream>
#include <iomanip>

// Конструктор списка
List::List() : head(nullptr), tail(nullptr) {
    std::cout << "Список был создан.\n";
}

// Деструктор списка
List::~List() {
    clear();
    std::cout << "Список был уничтожен.\n";
}

// Добавление элемента в конец
void List::add(Item* item) {
    if (!item) return;
    item->setNext(nullptr);
    item->setPrev(tail);
    if (tail) tail->setNext(item);
    else head = item;
    tail = item;
    item->list = this;
}

// Удаление элемента
Item* List::remove(int index) {
    Item* current = getItem(index);
    if (!current) return nullptr;

    if (current == head) {
        head = current->getNext();
        if (head) head->setPrev(nullptr);
        else tail = nullptr;
    } else if (current == tail) {
        tail = current->getPrev();
        if (tail) tail->setNext(nullptr);
        else head = nullptr;
    } else {
        current->getPrev()->setNext(current->getNext());
        current->getNext()->setPrev(current->getPrev());
    }

    current->setNext(nullptr);
    current->setPrev(nullptr);
    current->list = nullptr;
    return current;
}

// Удаление с удалением объекта
void List::Delete(int index) {
    Item* item = remove(index);
    if (item) delete item;
}

// Очистка списка
void List::clear() {
    while (head) {
        Delete(0);
    }
}

// Подсчёт элементов
int List::count() const {
    int count = 0;
    Item* current = head;
    while (current) {
        count++;
        current = current->getNext();
    }
    return count;
}

// Печать списка
void List::print() const {
    Item* current = head;
    int index = 0;
    while (current) {
        std::cout << "Элемент " << index++ << ":\n";
        Transport* t = dynamic_cast<Transport*>(current);
        if (t) t->print();
        else std::cout << "Невозможно отобразить: не Transport.\n";
        current = current->getNext();
    }
}

// Получение индекса
int List::getIndex(Item* item) const {
    Item* current = head;
    int index = 0;
    while (current) {
        if (current == item) return index;
        current = current->getNext();
        index++;
    }
    return -1;
}

// Получение элемента по индексу
Item* List::getItem(int index) const {
    if (index < 0) return nullptr;
    Item* current = head;
    int i = 0;
    while (current) {
        if (i == index) return current;
        current = current->getNext();
        i++;
    }
    return nullptr;
}

// Вставка элемента
void List::insert(Item* item, int index) {
    if (!item) return;

    if (index <= 0) {
        item->setNext(head);
        if (head) head->setPrev(item);
        head = item;
        if (!tail) tail = item;
    } else {
        Item* nextItem = getItem(index);
        if (!nextItem) {
            add(item);
            return;
        }

        Item* prevItem = nextItem->getPrev();
        item->setNext(nextItem);
        item->setPrev(prevItem);
        if (prevItem) prevItem->setNext(item);
        nextItem->setPrev(item);

        if (nextItem == head) head = item;
    }

    item->list = this;
}

// Сортировка по скорости
void List::sortBySpeed() {
    if (!head) return;
    bool swapped;
    do {
        swapped = false;
        Item* curr = head;
        while (curr && curr->getNext()) {
            Transport* t1 = dynamic_cast<Transport*>(curr);
            Transport* t2 = dynamic_cast<Transport*>(curr->getNext());
            if (t1 && t2 && t1->getSpeed() > t2->getSpeed()) {
                std::swap(*t1, *t2);
                swapped = true;
            }
            curr = curr->getNext();
        }
    } while (swapped);
    std::cout << "Сортировка по скорости завершена.\n";
}

// Сортировка по дальности
void List::sortByRange() {
    if (!head) return;
    bool swapped;
    do {
        swapped = false;
        Item* curr = head;
        while (curr && curr->getNext()) {
            Transport* t1 = dynamic_cast<Transport*>(curr);
            Transport* t2 = dynamic_cast<Transport*>(curr->getNext());
            if (t1 && t2 && t1->getRange() > t2->getRange()) {
                std::swap(*t1, *t2);
                swapped = true;
            }
            curr = curr->getNext();
        }
    } while (swapped);
    std::cout << "Сортировка по дальности завершена.\n";
}

// Поиск по пассажирам и грузу
void List::searchByPassengersAndCargo(int minPassengers, double minCargo) const {
    Item* current = head;
    bool found = false;
    while (current) {
        Transport* t = dynamic_cast<Transport*>(current);
        if (t && t->getPassengers() >= minPassengers && t->getCargo() >= minCargo) {
            t->print();
            found = true;
        }
        current = current->getNext();
    }
    if (!found) {
        std::cout << "Не найдено подходящих транспортных средств.\n";
    }
}

// Конструктор и деструктор Item
Item::Item() : next(nullptr), prev(nullptr), list(nullptr) {}
Item::~Item() {
    if (list) {
        list->remove(list->getIndex(this));
    }
}

// Геттеры и сеттеры
Item* Item::getNext() const { return next; }
Item* Item::getPrev() const { return prev; }
void Item::setNext(Item* n) { next = n; }
void Item::setPrev(Item* p) { prev = p; }
