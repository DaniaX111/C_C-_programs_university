#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "./menu.h"

// Меню для вызова функций
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

