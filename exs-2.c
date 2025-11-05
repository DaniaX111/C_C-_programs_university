#include <stdio.h>
#include <math.h>

int Okruznost(float x, float y, float R) {

    float R1 = sqrt(x * x + y * y);
    
    if(R == R1) {
        return 1;
    }
    return 0;
}

int main() {
    float x = 4;
    float y = 3;
    float R = 5;

    int result = Okruznost(x, y, R);

    if (result) {
        printf("Окружность охватывает начало координат \n");
    } else {
        printf("Окружность не охватывает начало координат \n");
    }

    return 0;
}