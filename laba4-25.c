#include <stdio.h>
#include <math.h>

int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {

    float inputArray[20];
    float result[32];
    float group[15];

    int arraySize = 10;  // Размер исходного массива
    printf("Введите размер исходного массива (максимум 20)\n");
    scanf("%d", &arraySize);
    int groupSize = 3; // Размер группы
    printf("Введите размер группы (от 2 до 15)");
    printf("\n");
    scanf("%d", &groupSize);

    // Проверка на корректность вводимых данных
    if (arraySize > 20) {
        arraySize = 20;
        printf("Некорректная размерность массива\n");
        printf("Размер массива был приведен к 20\n");
    }
    if (arraySize < 1) {
        printf("Введите корректный размер массива\n");
        return 1;
    }
    if (groupSize > 15) {
        groupSize = 15;
        printf("Некорректный размер группы\n");
        printf("Размер группы был приведен к 15\n");
    }
    if (groupSize < 2) {
        groupSize = 2;
        printf("Некорректный размер группы\n");
        printf("Размер группы был приведен к 2\n");
    }

    if (groupSize >= arraySize) {
        printf("Размер массива меньше или равен размеру группы\n");
        return 1;
    }

    int i;
    for (i = 0; i < arraySize; i++) {
        int k = i + 1;

        float arrayElement;
        printf("Введите %d число\n", k);
        scanf("%f", &arrayElement);
        inputArray[i] = arrayElement;
    }

    // Проверка на кратность кол-ва элементов массива и кол-ва элементов группы
    float partRes = (float)arraySize / (float)groupSize;
    float c = 0;
    float res;
    res = modff(partRes, &c);

    // Размер итогового массива
    // В соответствии с кратностью или некратностью кол-ва элементов массива и кол-ва элементов группы
    int resultSize;
    if (res != 0) {
        resultSize = (groupSize + 1) * (arraySize / groupSize + 1);
    } else {
        resultSize = (groupSize + 1) * (arraySize / groupSize);
    }

    printf("resSize: %d\n", resultSize);
      // Создаем массив для хранения результата
    int resultIndex = 0;
    
    for (int i = 0; i < arraySize; i += groupSize) {
        // массив группы элементов для удобного нахождения НОК
        for (int j = 0; j < groupSize; j++) {
            if (i + j < arraySize) {
                group[j] = inputArray[i + j];
            } else {
                group[j] = 0;  // Дополняем нулями в случае неполной группы
            }
        }
        
        // Находим НОК для группы и добавляем в итоговый массив
        float groupLcm = group[0];
        for (int j = 1; j < groupSize; j++) {
            groupLcm = lcm(groupLcm, group[j]);
        }
        // Заполняем итоговый массив
        for (int j = 0; j < groupSize + 1; j++) {
            if (j < groupSize) {
                result[resultIndex] = group[j];
                resultIndex++;
            } else {
                result[resultIndex] = groupLcm;
                resultIndex++;
            }
        }
    }
    
    // Выводим итоговый массив
    for (int i = 0; i < resultSize; i++) {
        printf("%f ", result[i]);
    }

    return 0;
}
