#include <iostream>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

using namespace std;

// Функция для получения текущего времени в миллисекундах
unsigned long getCurrentTimeMillis() {
#ifdef _WIN32
    return GetTickCount();
#else
    struct timeval tv;
    gettimeofday(&tv, nullptr);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
#endif
}

// Генерация упорядоченной последовательности (возрастание)
void generateOrdered(int* arr, int size, int minVal, int maxVal) {
    for (int i = 0; i < size; ++i) {
        arr[i] = minVal + i * (maxVal - minVal) / size;
    }
}

// Генерация упорядоченной последовательности (убывание)
void generateReverseOrdered(int* arr, int size, int minVal, int maxVal) {
    for (int i = 0; i < size; ++i) {
        arr[i] = maxVal - i * (maxVal - minVal) / size;
    }
}

// Генерация случайной последовательности целых чисел
void generateRandom(int* arr, int size, int minVal, int maxVal) {
    for (int i = 0; i < size; ++i) {
        arr[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}

// Генерация случайной последовательности чисел с плавающей запятой
void generateRandomFloat(float* arr, int size, float minVal, float maxVal) {
    for (int i = 0; i < size; ++i) {
        arr[i] = minVal + static_cast<float>(rand()) / RAND_MAX * (maxVal - minVal);
    }
}

// Генерация частично упорядоченной последовательности
void generatePartiallyOrdered(int* arr, int size, int minVal, int maxVal, int segmentSize) {
    generateOrdered(arr, size, minVal, maxVal);
    random_device rd;
    mt19937 g(rd());

    for (int i = 0; i < size; i += segmentSize) {
        int end = min(i + segmentSize, size);
        shuffle(arr + i, arr + end, g);
    }
}

// Функция замера времени для функций с 4 аргументами
void measureTime(void (*genFunc)(int*, int, int, int), int* arr, int size, int minVal, int maxVal) {
    unsigned long start = getCurrentTimeMillis();
    genFunc(arr, size, minVal, maxVal);
    unsigned long stop = getCurrentTimeMillis();
    cout << "Время выполнения: " << (stop - start) << " мс" << endl;
}

// Функция замера времени для функций с 5 аргументами
void measureTime(void (*genFunc)(int*, int, int, int, int), int* arr, int size, int minVal, int maxVal, int segmentSize) {
    unsigned long start = getCurrentTimeMillis();
    genFunc(arr, size, minVal, maxVal, segmentSize);
    unsigned long stop = getCurrentTimeMillis();
    cout << "Время выполнения: " << (stop - start) << " мс" << endl;
}

int main() {
    srand(time(nullptr));
    const int sizes[] = {500000, 1000000, 5000000};
    int minVal = 1, maxVal = 1000000;
    
    for (int i = 0; i < 3; ++i) {
        int size = sizes[i];
        int* arr = new int[size];
        float* floatArr = new float[size];
        cout << "Размер: " << size << endl;
        
        cout << "Упорядоченная последовательность (возрастание)" << endl;
        measureTime(generateOrdered, arr, size, minVal, maxVal);
        cout << "Упорядоченная последовательность (убывание)" << endl;
        measureTime(generateReverseOrdered, arr, size, minVal, maxVal);
        cout << "Случайная последовательность" << size << endl;
        measureTime(generateRandom, arr, size, minVal, maxVal);
        
        cout << "Случайная последовательность чисел с плавающей запятой" << endl;
        unsigned long start = getCurrentTimeMillis();
        generateRandomFloat(floatArr, size, static_cast<float>(minVal), static_cast<float>(maxVal));
        unsigned long stop = getCurrentTimeMillis();
        cout << "Время выполнения (float): " << (stop - start) << " мс" << endl;
        
        cout << "Частично упорядоченная последовательность" << endl;
        measureTime(generatePartiallyOrdered, arr, size, minVal, maxVal, size / 10);
        
        delete[] arr;
        delete[] floatArr;
        cout << "--------------------------" << endl;
    }
    return 0;
}
