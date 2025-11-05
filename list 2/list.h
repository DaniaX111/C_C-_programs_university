#pragma once

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