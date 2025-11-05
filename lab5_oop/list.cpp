// === list.cpp ===
#include "list.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "subj.h"

Item::Item() : next(nullptr), prev(nullptr), list(nullptr) {}
Item::~Item() = default;// реализовать

List::List() : head(nullptr), tail(nullptr) {}
List::~List() { clear(); }

void List::add(Item* item) {
    if (!item) return;
    item->setNext(nullptr);
    item->setPrev(tail);
    if (tail) tail->setNext(item);
    tail = item;
    if (!head) head = item;
    item->list = this;
}

Item* List::remove(int index) {
    if (index < 0) return nullptr;
    Item* current = getItem(index);
    if (!current) return nullptr;
    if (current == head) head = current->getNext();
    if (current == tail) tail = current->getPrev();
    if (current->getPrev()) current->getPrev()->setNext(current->getNext());
    if (current->getNext()) current->getNext()->setPrev(current->getPrev());
    current->setNext(nullptr);
    current->setPrev(nullptr);
    current->list = nullptr;
    return current;
}

void List::Delete(int index) {
    Item* item = remove(index);
    delete item;
}

void List::clear() {
    while (head) Delete(0);
    head = tail = nullptr;
}

int List::count() const {
    int cnt = 0;
    for (Item* it = head; it; it = it->getNext()) ++cnt;
    return cnt;
}

void List::print() const {
    int i = 0;
    for (Item* it = head; it; it = it->getNext()) {
        std::cout << i++ << ": ";
        // получаем указатель из итератора
        dynamic_cast<Transport*> (it)->print();  
    }
}

int List::getIndex(Item* item) const {
    int i = 0;
    for (Item* it = head; it; it = it->getNext(), ++i) {
        if (it == item) return i;
    }
    return -1;
}

Item* List::getItem(int index) const {
    int i = 0;
    for (Item* it = head; it; it = it->getNext(), ++i) {
        if (i == index) return it;
    }
    return nullptr;
}

void List::insert(Item* item, int index) {
    if (!item) return;
    Item* tmp = getItem(index);
    if (!tmp) add(item);
    else if (tmp == head) {
        item->setNext(head);
        item->setPrev(nullptr);
        head->setPrev(item);
        head = item;
    } else {
        Item* prev = tmp->getPrev();
        item->setNext(tmp);
        item->setPrev(prev);
        if (prev) prev->setNext(item);
        tmp->setPrev(item);
    }
    item->list = this;
}

void SubjList::sortBySpeed() {
    std::vector<Item*> items;
    for (Item* it = head; it; it = it->getNext()) {
        items.push_back(it);
    }

    std::sort(items.begin(), items.end(), [](Item* a, Item* b) {
        Transport* ta = dynamic_cast<Transport*>(a);
        Transport* tb = dynamic_cast<Transport*>(b);
        if (!ta && !tb) return false; // Оба не Transport — порядок не меняем
        if (!ta) return false;        // a не Transport — b "больше"
        if (!tb) return true;         // b не Transport — a "больше"
        return ta->getSpeed() > tb->getSpeed();
    });

    // Перестраиваем связи между элементами
    head = items.empty() ? nullptr : items[0];
    tail = items.empty() ? nullptr : items.back();

    for (size_t i = 0; i < items.size(); ++i) {
        items[i]->setPrev(i > 0 ? items[i - 1] : nullptr);
        items[i]->setNext(i < items.size() - 1 ? items[i + 1] : nullptr);
    }
}

void SubjList::sortByRange() {
    std::vector<Item*> items;
    for (Item* it = head; it; it = it->getNext()) {
        items.push_back(it);
    }

    std::sort(items.begin(), items.end(), [](Item* a, Item* b) {
        Transport* ta = dynamic_cast<Transport*>(a);
        Transport* tb = dynamic_cast<Transport*>(b);
        if (!ta && !tb) return false; // Оба не Transport — порядок не меняем
        if (!ta) return false;        // a не Transport — b "больше"
        if (!tb) return true;         // b не Transport — a "больше"
        return ta->getRange() > tb->getRange();
    });

    // Перестраиваем связи между элементами
    head = items.empty() ? nullptr : items[0];
    tail = items.empty() ? nullptr : items.back();

    for (size_t i = 0; i < items.size(); ++i) {
        items[i]->setPrev(i > 0 ? items[i - 1] : nullptr);
        items[i]->setNext(i < items.size() - 1 ? items[i + 1] : nullptr);
    }
}

void SubjList::searchByPassengers(int minP) {
    std::vector<Item*> items;
    for (Item* it = head; it; it = it->getNext()) {
        Transport* t = dynamic_cast<Transport*>(it);
        if (t && t->getPassengers() >= minP) {
            items.push_back(t);
        }
    }

    // Сортировка по пассажирам (по убыванию)
    std::sort(items.begin(), items.end(), [](Item* a, Item* b) {
        Transport* ta = dynamic_cast<Transport*>(a);
        Transport* tb = dynamic_cast<Transport*>(b);
        return ta->getPassengers() > tb->getPassengers();
    });

    // Перестройка связей в списке
    head = items.empty() ? nullptr : items[0];
    tail = items.empty() ? nullptr : items.back();
    for (size_t i = 0; i < items.size(); ++i) {
        items[i]->setPrev(i > 0 ? items[i - 1] : nullptr);
        items[i]->setNext(i < items.size() - 1 ? items[i + 1] : nullptr);
    }
}

void SubjList::searchByCargo(double minC) {
    std::vector<Item*> items;
    for (Item* it = head; it; it = it->getNext()) {
        Transport* t = dynamic_cast<Transport*>(it);
        if (t && t->getCargo() >= minC) {
            items.push_back(t);
        }
    }

    // Сортировка по грузоподъемности (по убыванию)
    std::sort(items.begin(), items.end(), [](Item* a, Item* b) {
        Transport* ta = dynamic_cast<Transport*>(a);
        Transport* tb = dynamic_cast<Transport*>(b);
        return ta->getCargo() > tb->getCargo();
    });

    // Перестройка связей в списке
    head = items.empty() ? nullptr : items[0];
    tail = items.empty() ? nullptr : items.back();
    for (size_t i = 0; i < items.size(); ++i) {
        items[i]->setPrev(i > 0 ? items[i - 1] : nullptr);
        items[i]->setNext(i < items.size() - 1 ? items[i + 1] : nullptr);
    }
}