#include <iostream>
#include <string>
#include <iomanip>
#include "list.h"

void menu(List& list) {
    int choice;
    Item* item = nullptr;

    while (true) {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить элемент\n";
        std::cout << "2. Удалить элемент по индексу\n";
        std::cout << "3. Удалить последний элемент\n";
        std::cout << "4. Очистить список\n";
        std::cout << "5. Получить количество элементов\n";
        std::cout << "6. Печать списка\n";
        std::cout << "7. Вставить элемент в произвольную позицию\n"; // Новый пункт меню
        std::cout << "8. Найти индекс элемента\n";
        std::cout << "9. Получить элемент по индексу\n"; // Новый пункт меню
        std::cout << "10. Выйти\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                item = new Item();
                list.add(item);
                break;
            case 2: {
                int index;
                std::cout << "Введите индекс элемента для удаления: ";
                std::cin >> index;
                list.remove(index);
                break;
            }
            case 3:
                int index;
                std::cout << "Введите индекс элемента для удаления: ";
                std::cin >> index;
                list.Delete(index);
                break;
            case 4:
                list.clear();
                break;
            case 5:
                std::cout << "Количество элементов: " << list.count() << "\n";
                break;
            case 6:
                list.print();
                break;
            case 7: {
                item = new Item();

                int index;
                std::cout << "Введите индекс для вставки: ";
                std::cin >> index;

                list.insert(item, index);
                break;
            }
            case 8: {
                Item* locItem = nullptr;
                intptr_t& item = reinterpret_cast<intptr_t&>(locItem);
                std::cout << "Введите адрес элемента для поиска: ";
                std::cin >> std::hex >> item;
                int index = list.getIndex(locItem);
                std::cout << "Индекс элемента : " << index << "\n";
                break;

            }
            case 9: {
                int index;
                std::cout << "Введите индекс элемента для получения: ";
                std::cin >> index;

                Item* result = list.getItem(index);
                if (result != nullptr) {
                    std::cout << "Элемент с индексом " << index << ": " << result << "\n";
                } else {
                    std::cout << "Элемент с индексом " << index << " не найден.\n";
                }
                break;
            }
            case 10:
                list.clear();
                return;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }
}

int main() {
    List list;
    menu(list);
    return 0;
}