#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
    int N;
    printf("Введите число:\n");
    scanf("%d", &N);
    printf("\n");

    int primes[N+1];
    for (int a = 0; a <= N; a++) {
        primes[a] = a;
    }

    primes[1] = 0;
    int i = 2;

    while (i <= N) {
        if (primes[i] != 0) {
            int j = i + i;
            while (j <= N) {
                primes[j] = 0;
                j = j + i;
            }
        }
        i++;
    }

    printf("Список простых чисел:\n");
    for (int k = 0; k <= N; k++) {
        if (primes[k] != 0) {
            int m = primes[k];
            printf("%d ", m);
        }
    }
    printf("\n");
    return 0;
}