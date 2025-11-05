#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>

class Item;

class List {
public:
    List();
    ~List();
    void add(Item* item);
    Item* remove(int index); // Изменяем метод для удаления элемента по индексу
    void Delete(int index); // Удаление последнего элемента списка
    void clear();
    int count() const;
    void print() const;
    int getIndex(Item* item) const; // Метод для получения индекса элемента
    Item* getItem(int index) const; // Метод для получения элемента по индексу
    void insert(Item* item, int index); // Прототип метода Insert
    void searchByPassengersAndCargo(int passengers, double cargo); // Возвращаем исходную сигнатуру


    Item* getHead() const { return head; } // Метод доступа для получения указателя на head
    Item* getTail() const { return tail; } // Метод доступа для получения указателя на tail
    void setHead(Item* item) { head = item; }
    void setTail(Item* item) { tail = item; }

private:
    Item* head;
    Item* tail;

    friend class Item; // Делаем класс Item другом, чтобы он мог обращаться к head и tail
};

class Item {
public:
    Item();
    ~Item();

    Item* getNext() const { return next; }
    Item* getPrev() const { return prev; }
    void setNext(Item* item) { next = item; }
    void setPrev(Item* item) { prev = item; }

    void print() const; // Добавляем метод print

    List* list; // Указатель на список, к которому принадлежит элемент

private:
    Item* next;
    Item* prev;
};

#endif // LIST_H