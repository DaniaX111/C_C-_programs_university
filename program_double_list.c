#include <stdlib.h>
#include <stdio.h>

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

int main() {
    struct List list;
    struct Item item;
    list = *createList();

    struct Item item1;
    Add(&list, &item1);
    struct Item item2;
    Add(&list, &item2);
    print_list(&list);
    
    int index1 = GetIndex(&list, &item1);
    printf("Index: %d\n", index1);
    int index2 = GetIndex(&list, &item2);
    printf("Index: %d\n", index2);


    struct Item item3;
    Add(&list, &item3);
    print_list(&list);

    struct Item item4;
    Insert(&list, &item4, 2);
    print_list(&list);

    struct Item* item5 = Remove(&list, 0);
    print_list(&list);
    printf("%p\n", item5);

    int i = Count(&list);
    printf("%d\n", i);

    popBack(&list);
    print_list(&list);
    int j = Count(&list);
    printf("%d\n", j);

    popFront(&list);
    print_list(&list);
    struct Item* find_item = GetItem(&list, 0);
    printf("%p\n", find_item);
    Clear(&list);

    return 0;
}

struct List* createList() {
    struct List* tmp = (struct List*)malloc(sizeof(struct List));
    tmp->head = tmp->tail = NULL;

    printf("Двусвязный список был создан\n");
    return tmp;
}

void Clear(struct List* list) {
    list->head = list->tail = NULL;

    printf("Двусвязный список был очищен\n");
}

// добавить в конец
void Add(struct List* list, struct Item* item) {
    if (item == NULL) {
        exit(3);
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
    int check = 0;

    while (tmp != item) {

        if(tmp->next == list->tail->next) {
            check = 1;
            break;
        }
        else {
            tmp = tmp->next;
            i++;
        }

    }

    if(check == 0) {
        return i;
    }
    else {
        return 10000000;
    }
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
        exit(2);
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
        exit(4);
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


// вывод всех элементов списка
void print_list(struct List* list) {
    struct Item* current = list->head;

    while (current != NULL) {
        printf("%p\n", current);
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
