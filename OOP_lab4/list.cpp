#include "list.h"

// Конструктор списка
List::List() : head(nullptr), tail(nullptr) {
    std::cout << "Список был создан.\n";
}

// Деструктор списка (освобождает память)
List::~List() {
    clear();
    std::cout << "Список был уничтожен.\n";
}

// Добавление элемента в конец списка
void List::add(Item* item) {
    if (item == nullptr) return;

    // Проверка, что элемент не принадлежит другому списку
    if (item->getNext() != nullptr || item->getPrev() != nullptr) {
        std::cerr << "Ошибка: элемент уже принадлежит другому списку.\n";
        return;
    }

    item->setNext(nullptr);
    item->setPrev(tail);
    if (tail) {
        tail->setNext(item);
    }
    tail = item;

    if (head == nullptr) {
        head = item;
    }

    item->list = this; // Устанавливаем указатель на текущий список
}

// Удаление элемента из списка по индексу
Item* List::remove(int index) {
    if (index < 0 || head == nullptr) {
        std::cerr << "Ошибка: неверный индекс или список пуст.\n";
        return nullptr;
    }

    std::cout << "Удаление элемента с индексом " << index << std::endl;

    Item* current = getItem(index); // Получаем элемент по индексу

    if (current == nullptr) {
        std::cerr << "Ошибка: элемент с индексом " << index << " не найден.\n";
        return nullptr;
    }

    std::cout << "Удаляемый элемент: " << current << "\n";

    // Удаление головы списка
    if (current == getHead()) {
        setHead(current->getNext());
        if (getHead()) {
            getHead()->setPrev(nullptr);
        } else {
            setTail(nullptr);
        }
    }

    // Удаление хвоста списка
    if (current == getTail()) {
        setTail(current->getPrev());
        if (getTail()) {
            getTail()->setNext(nullptr);
        } else {
            setHead(nullptr);
        }
    }

    // Удаление элемента из середины списка
    if (current->getPrev()) {
        current->getPrev()->setNext(current->getNext());
    }
    if (current->getNext()) {
        current->getNext()->setPrev(current->getPrev());
    }

    current->setNext(nullptr);
    current->setPrev(nullptr);
    current->list = nullptr;

    return current;
    std::cout << "Элемент удалён.\n";
}

void List::Delete(int index) {

    delete getItem(index);
    std::cout << "Элемент с индексом " << index << " был удалён.\n";
}

// Очистка списка
void List::clear() {
    Item* current = head;
    while (head) {
        Delete(0); // Удаляем первый элемент
    }
    head = tail = nullptr;
    std::cout << "Список был очищен.\n";
}

// Подсчет элементов в списке
int List::count() const {
    int count = 0;
    Item* current = head;
    while (current != nullptr) {
        count++;
        current = current->getNext();
    }
    return count;
}

// Печать списка
void List::print() const {
    Item* current = head;
    int i = 0;
    while (current != nullptr) {
        std::cout << "Элемент " << i++ << ": " << current->getPrev() << '\t' << current << '\t' << current->getNext() << "\n";
        current = current->getNext();
    }
}

int List::getIndex(Item* item) const {
    if (item == nullptr) {
        std::cerr << "Ошибка: передан пустой указатель на элемент.\n";
        return -1;
    }

    Item* tmp = head; // Начинаем с головы списка
    int i = 0;

    while (tmp != nullptr) {
        if (tmp == item) {
            return i; // Возвращаем индекс, если элемент найден
        }
        tmp = tmp->getNext(); // Переходим к следующему элементу
        i++;
    }

    return -1; // Если элемент не найден
}

Item* List::getItem(int index) const {
    if (index < 0) {
        std::cerr << "Ошибка: индекс не может быть отрицательным.\n";
        return nullptr;
    }

    Item* tmp = head; // Начинаем с головы списка
    int i = 0;

    while (tmp != nullptr) {
        if (i == index) {
            return tmp; // Возвращаем элемент, если индекс совпадает
        }
        tmp = tmp->getNext(); // Переходим к следующему элементу
        i++;
    }

    std::cerr << "Ошибка: элемент с индексом " << index << " не найден.\n";
    return nullptr; // Если элемент не найден
}

void List::insert(Item* item, int index) {
    if (item == nullptr) {
        std::cerr << "Ошибка: передан пустой указатель на элемент.\n";
        return;
    }

    Item* tmp = getItem(index);

    if (tmp == nullptr) { // Если индекс выходит за пределы списка, добавляем в конец
        add(item);
    } else if (tmp == head) { // Вставка в начало списка
        item->setNext(tmp);
        tmp->setPrev(item);
        item->setPrev(nullptr);
        head = item;
    } else { // Вставка в середину списка
        Item* tmpPrev = tmp->getPrev();

        item->setNext(tmp);
        item->setPrev(tmpPrev);

        tmp->setPrev(item);
        if (tmpPrev) {
            tmpPrev->setNext(item);
        }
    }

    item->list = this; // Устанавливаем указатель на текущий список
    std::cout << "Элемент вставлен на позицию " << index << ".\n";
}

// Конструктор элемента
Item::Item() : next(nullptr), prev(nullptr), list(nullptr) {}

// Деструктор элемента
Item::~Item() {
    if (list != nullptr) {
        list->remove(list->getIndex(this)); // Удаляем элемент из списка
    }

}