#include <stdlib.h>
#include <stdio.h>

#include "./list.h"

struct List* createList() {
    struct List* tmp = (struct List*)malloc(sizeof(struct List));
    tmp->head = tmp->tail = NULL;

    printf("Двусвязный список был создан\n");
    return tmp;
}

void Clear(struct List* list) {
    struct Item* current = list->head;
    struct Item* next;

    while (current != NULL) {
        next = current->next;
        free(current); // Освобождение памяти исключенного элемента
        current = next;
    }

    list->head = list->tail = NULL;
    printf("Двусвязный список был очищен\n");
}

// добавить в конец
void Add(struct List* list, struct Item* item) {
    if (item == NULL) {
        return;
    }

    item->next = NULL;
    item->prev = list->tail;
    if (list->tail) {
        list->tail->next = item;
    }
    list->tail = item;
 
    if (list->head == NULL) {
        list->head = item;
    }
}

int GetIndex(struct List* list, struct Item* item) {

    struct Item* tmp = list->head;
    int i = 0;

    while (tmp != NULL) {
        if (tmp == item) {
            return i;
        }
        tmp = tmp->next;
        i++;
    }

    return -1; // Если элемент не найден
}


struct Item* GetItem(struct List* list, int number) {
    struct Item* tmp = list->head;
    int i = 0;
    int check = 0;

    while (tmp != NULL) {
        if(i == number) {
            break;
        }
        else {
            tmp = tmp->next;
            i++;
        }

    }

    return tmp;
}

// удалить первый элемент
void popFront(struct List* list) {
    struct Item* prev;
    if (list->head == NULL) {
        return;
    }
 
    prev = list->head;
    list->head = list->head->next;
    if (list->head) {
        list->head->prev = NULL;
    }
    if (prev == list->tail) {
        list->tail = NULL;
    }
}

// удалить последний элемент
void popBack(struct List* list) {
    struct Item* next;
    if (list->tail == NULL) {
        return;
    }
 
    next = list->tail;
    list->tail = list->tail->prev;
    if (list->tail) {
        list->tail->next = NULL;
    }
    if (next == list->head) {
        list->head = NULL;
    }

}


void print_list(struct List* list) {
    struct Item* current = list->head;

    while (current != NULL) {
        printf("Элемент: %p, Предыдущий: %p, Следующий: %p\n", current, current->prev, current->next);
        current = current->next;
    }

    printf("\n");
}

int Count(struct List* list) {

    struct Item* tmp = list->head;
    int i = 0;

    while (tmp != list->tail->next) {
        tmp = tmp->next;
        i++;
    }

    return i;
}

// Функция для вставки узла в произвольную позицию
void Insert(struct List* list, struct Item* item, int number) {
    struct Item* tmp;
    tmp = GetItem(list, number);

    if(tmp == NULL) {
        Add(list, item);
    }
    else if (tmp == list->head) {
        item->next = tmp;
        tmp->prev = item;
        item->prev = NULL;

        list->head = item;
    }
    else {
        struct Item* tmp2 = tmp->prev;

        // Связи вставляемого элемента
        item->next = tmp;
        item->prev = tmp2;

        tmp->prev = item;
        tmp2->next = item;
    }
}

struct Item* Remove(struct List* list, int number) {
    struct Item* tmp = GetItem(list, number);

    if(tmp == NULL) {
        return NULL;
    }
    else if(list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    }
    else if(tmp == list->head) {
        list->head = list->head->next;
        list->head->prev = NULL;
        tmp->next = NULL;

    }
    else if(tmp == list->tail) {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
        tmp->prev = NULL;

    }
    else {
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        tmp->next = NULL;
        tmp->prev = NULL;
    }

    return tmp;
}

struct Item* Delete(struct List* list, int number) {
    struct Item* tmp = Remove(list, number);

    if (tmp != NULL) {
        free(tmp); // Освобождение памяти исключенного элемента
        printf("Элемент с индексом %d был удален\n", number);
    } else {
        printf("Элемент с индексом %d не найден\n", number);
    }
    
    return tmp;
}
