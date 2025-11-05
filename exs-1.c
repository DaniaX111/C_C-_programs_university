#include <stdio.h>
#include <math.h>

void Yi(double inputArray[], int n, double k, double a, double d) {
    int i;
    for (i = 0; i <= n; i++) {
        double yi = k * sin(a + d * i) * sin(a + d * i);
        inputArray[i] = yi;
    }

    int j;
    for (j = 0; j <= n; j++) {
        printf("%lf\n", inputArray[j]);
    }
}

int main() {
    double inputArray[20];
    double k;
    double a;
    double d;
    int n;

    k = 5;
    a = 6;
    d = 4;
    n = 5;

    Yi(inputArray, n, k, a, d);

    return 0;
}