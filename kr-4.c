#include <stdio.h>

float arrayLogic(float *inpArray, int element_quantity);
void scanArray(float *inpArray, int element_quantity);
void printArray(float *inpArray, int element_quantity);

int main() {
    float inputArray[20];
    int el_quantity = 0;

    printf("Введите количество элементов массива:\n");
    scanf("%d", &el_quantity);

    scanArray(inputArray, el_quantity);
    float elBuffer = arrayLogic(inputArray, el_quantity);
    printf("Вычисленное значение функции обработки массива: %f\n", elBuffer);
    printArray(inputArray, el_quantity);



    return 0;
}

float arrayLogic(float *inpArray, int element_quantity) {

    float elementBuffer = 0;
    int i;

    for(i = 0; i < element_quantity; i++) {
        if(*inpArray > 0) {
            if(elementBuffer == 0) {
                elementBuffer = *inpArray;
            } else {
                elementBuffer *= *inpArray;
            }
        }
        inpArray++;
    }

    return elementBuffer;
}

void scanArray(float *inpArray, int element_quantity) {

    int i;
    for(i = 0; i < element_quantity; i++) {
        int number = i + 1;
        printf("Введите %d элемент массива:\n", number);
        scanf("%f", inpArray);
        printf("\n");

        inpArray++;
    }
}

void printArray(float *inpArray, int element_quantity) {
    printf("\n");
    printf("Вывод элементов массива:\n");

    int i;
    for(i = 0; i < element_quantity; i++) {
        int number = i + 1;
        printf("Элемент массива %d равен %f", number, *inpArray);
        printf("\n");

        inpArray++;
    }

}