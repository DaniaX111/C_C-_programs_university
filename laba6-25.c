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

// Заполнение массива элементами
void fillArray(float result[], int *resultIndex, float group[], int groupSize, int groupLcm) {
    for (int j = 0; j < groupSize + 1; j++) {
        if (j < groupSize) {
            result[(*resultIndex)] = group[j];
            (*resultIndex)++;
        } else {
            result[(*resultIndex)] = groupLcm;
            (*resultIndex)++;
        }
    }
}


// заполнение группы элементами
void fillGroup(float inputArray[], int arraySize, int groupSize, float result[], int resultIndex) { 
    float group[15];
    for (int i = 0; i < arraySize; i += groupSize) {
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
        fillArray(result, &resultIndex, group, groupSize, groupLcm);
    }
}

void printArray(float result[], int resultSize) {
    printf("resSize: %d \n", resultSize);
    // Выводим итоговый массив
    for (int i = 0; i < resultSize; i++) {
        printf("%f ", result[i]);
    }
}

void processArray(float inputArray[], int arraySize, int groupSize, float *result, int *resultSize) {

    // Проверка на кратность кол-ва элементов массива и кол-ва элементов группы
    float partRes = (float)arraySize / (float)groupSize;
    float c = 0;
    float res;
    res = modff(partRes, &c);

    // Размер итогового массива
    // В соответствии с кратностью или некратностью кол-ва элементов массива и кол-ва элементов группы
    
    if (res != 0) {
        *resultSize = (groupSize + 1) * (arraySize / groupSize + 1);
    } else {
        *resultSize = (groupSize + 1) * (arraySize / groupSize);
    }

      
    int resultIndex = 0;
    
    fillGroup(inputArray, arraySize, groupSize, result, resultIndex);
   
}

void scanArray(int *arraySize, int *groupSize, float *inputArray) {
    printf("Введите размер исходного массива (максимум 20)\n");
    scanf("%d", arraySize);
    printf("Введите размер группы (от 2 до 15)");
    printf("\n");
    scanf("%d", groupSize);

    // Проверка на корректность вводимых данных
    if (*arraySize > 20) {
        *arraySize = 20;
        printf("Некорректная размерность массива\n");
        printf("Размер массива был приведен к 20\n");
    }
    if (*arraySize < 1) {
        printf("Введите корректный размер массива\n");
        return;
    }
    if (*groupSize > 15) {
        *groupSize = 15;
        printf("Некорректный размер группы\n");
        printf("Размер группы был приведен к 15\n");
    }
    if (*groupSize < 2) {
        *groupSize = 2;
        printf("Некорректный размер группы\n");
        printf("Размер группы был приведен к 2\n");
    }

    if (*groupSize >= *arraySize) {
        printf("Размер массива меньше или равен размеру группы\n");
        return;
    }

    // заполнение массива элементами
    int i;
    for (i = 0; i < *arraySize; i++) {
        int k = i + 1;

        printf("Введите %d число\n", k);
        scanf("%f", &inputArray[i]);
    }

}

int main() {
    int arraySize;  // Размер исходного массива
    int groupSize;  // Количество элементов в группе
    float inputArray[20];  // Исходный массив 

    // Создаем массив для хранения результата
    float result[32];
    int resultSize;

    scanArray(&arraySize, &groupSize, inputArray);
    processArray(inputArray, arraySize, groupSize, result, &resultSize);
    printArray(result, resultSize); // Выводим итоговый массив
    return 0;
}
