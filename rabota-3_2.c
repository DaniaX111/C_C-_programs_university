#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
    int N;

    printf("Введите число:\n");
    scanf("%d", &N);

    if (N <= 2) {
        printf("Простых чисел нет\n");
        return 0;
    } 

    if (N == 3) {
        printf("2\n");
        return 0;
    } 

    int i;
    for (i = 2; i < N; i++) {

        int j;
        int count = 0;
        for(j = i / 2; j > 1; j--) {

            if (i % j == 0) {
                count++;
                break;
            }

        }

        if (count < 1) {
            printf("%d ", i);
        }
    }

    return 0;
}