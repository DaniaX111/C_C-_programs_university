// === main.cpp ===
#include "list.h"
#include "subj.h"
#include <iostream>

void menu(List& list, SubjList& subjlist) {
    int choice;
    while (true) {
        std::cout << "\n1. Добавить автомобиль\n2. Добавить самолет\n3. Добавить корабль\n4. Печать списка\n5. Сортировать по скорости\n6. Сортировать по дальности\n7. Поиск по пассажирам\n8. Поиск по грузу\n9. Очистить\n10. Выйти\nВаш выбор: ";
        std::cin >> choice;
        switch (choice) {
            case 1: list.add(new Car()); break;
            case 2: list.add(new Plane()); break;
            case 3: list.add(new Ship()); break;
            case 4: list.print(); break;
            case 5: subjlist.sortBySpeed(); break;
            case 6: subjlist.sortByRange(); break;
            case 7: {
                int minP;
                std::cout << "Мин. пассажиров: "; std::cin >> minP;
                subjlist.searchByPassengers(minP);
                break;
            }
            case 8: {
                double minC;
                std::cout << "Мин. груз (т/кг): "; std::cin >> minC;
                subjlist.searchByCargo(minC);
                break;
            }
            case 9: {
                list.clear();
                subjlist.clear();
                break;
            }
            case 10: return;
            default: std::cout << "Неверный выбор\n";
        }
    }
}

int main() {
    List list;
    SubjList subjlist;
    menu(list, subjlist);
    return 0;
}
