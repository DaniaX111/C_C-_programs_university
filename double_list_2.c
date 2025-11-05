#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Item {
    struct Item* next;
    struct Item* prev;
};

struct List {
    struct Item* head;
    struct Item* tail;
};

struct List* createList();
void Clear(struct List* list);
void Add(struct List* list, struct Item* item);
int GetIndex(struct List* list, struct Item* item);
struct Item* GetItem(struct List* list, int number);
void popFront(struct List* list);
void popBack(struct List* list);
void print_list(struct List* list);
int Count(struct List* list);
void Insert(struct List* list, struct Item* item, int number);
struct Item* Remove(struct List* list, int number);
struct Item* Delete(struct List* list, int number);
void menu(struct List* list);

int main() {
    struct List* list1 = createList();
    menu(list1);

    return 0;
}

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

// Добавьте меню для вызова функций
void menu(struct List* list) {
    int choice;
    struct Item* item;
    int index;

    while (true) {
        int list_length;

        printf("Меню:\n");
        printf("1. Добавить элемент\n");
        printf("2. Удалить элемент\n");
        printf("3. Исключить элемент\n");
        printf("4. Удалить первый элемент\n");
        printf("5. Удалить последний элемент\n");
        printf("6. Очистить список\n");
        printf("7. Получить индекс элемента\n");
        printf("8. Получить элемент по индексу\n");
        printf("9. Вывод количества элемента списка\n");
        printf("10. Вставка элемента\n");
        printf("11. Печать списка\n");
        printf("12. Выйти\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                item = (struct Item*)malloc(sizeof(struct Item)); // Создание нового элемента
                Add(list, item);
                break;

            case 2:
                printf("Введите индекс элемента для удаления: ");
                scanf("%d", &index);
                item = Delete(list, index);
                printf("Элемент %p был удален\n", item);
                break;

            case 3:
                printf("Введите индекс элемента для исключения: ");
                scanf("%d", &index);
                item = Remove(list, index);
                printf("Элемент %p был исключен\n", item);
                break;

            case 4:
                popFront(list);
                break;
            
            case 5:
                popBack(list);
                break;

            case 6:
                Clear(list);
                break;

            
            case 7:
                printf("Введите адрес элемента для поиска: ");
                scanf("%p", (void**)&item);
                index = GetIndex(list, item);
                printf("Индекс: %d\n", index);
                break;

            case 8:
                printf("Введите номер элемента для поиска: ");
                int index;
                scanf("%d", &index);
                item = GetItem(list, index);
                printf("Элемент: %p\n", item);
                break;

            case 9:
                list_length = Count(list);
                printf("Количество элементов: %d\n", list_length);
                break;

            case 10:
                item = (struct Item*)malloc(sizeof(struct Item));
                printf("Введите номер элемента для вставки: ");
                scanf("%d", &index);
                Insert(list, item, index);
                break;

            case 11:
                print_list(list);
                break;

            case 12:
                Clear(list);
                free(list); // Освобождение памяти списка
                return;

            default:
                printf("Неверный выбор. Попробуйте снова.\n");
        }
    }
}

