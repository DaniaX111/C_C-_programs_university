#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//#include <locale.h>

int main() {
	float x1, x2, y1, y2, x3, y3, ab, bc, ac, ad, ae, ed;
	float tgA, tgB, cosA, cosB;
	
	//char *locale = setlocale(LC_ALL, "");
	
	printf("Введите x начала:\n");
	scanf("%f", &x1);
	printf("Введите y начала:\n");
	scanf("%f", &y1);
	printf("Введите x конца:\n");
	scanf("%f", &x2);
	printf("Введите y конца:\n");
	scanf("%f", &y2);
	printf("Введите x точки:\n");
	scanf("%f", &x3);
	printf("Введите y точки:\n");
	scanf("%f", &y3);

	ab = x2 - x1; // длина вектора по x
	bc = y2 - y1; // длина вектора по y
	ae = x3 - x1; // длина от точки по x
	ed = y3 - y1; // длина от точки по y

	float arctanA = atan2(bc, ab);
	printf("Арктангенс A равен: %f\n", arctanA);
	float arctanB = atan2(ed, ae);
	printf("Арктангенс B равен: %f\n", arctanB);

	if (arctanB < 0 && arctanA > 0 || arctanA < 0 && arctanB > 0) {

		// проверка позади
		if (arctanA > arctanB) {
			float sumArc = arctanA + fabsf(arctanB);
			printf("Сумма равна: %f\n", sumArc);
			if (sumArc >= 3.13 && sumArc <= 3.15) {
				printf("Позади\n");
			}
			if (sumArc > 3.15) {
				printf("Слева\n");
			}
			if (sumArc < 3.13) {
				printf("Справа\n");
			}
		}

		if (arctanB > arctanA) {
			float sumArc = arctanB + fabsf(arctanA);
			printf("Сумма равна: %f\n", sumArc);
			if (sumArc >= 3.13 && sumArc <= 3.15) {
				printf("Позади\n");
			}
			if (sumArc > 3.15) {
				printf("Справа\n");
			}
			if (sumArc < 3.13) {
				printf("Слева\n");
			}
		}
	}

	// если все координаты положительные
	if (arctanB >= 0 && arctanA >= 0) {
		// проверка слева / справа
		if (arctanB > arctanA) {
			printf("Слева\n");
		}
		if (arctanB < arctanA) {
			printf("Справа\n");
		}

		if (arctanA == arctanB) {
			if(ab >= ae && bc >= ed) {
				printf("Принадлежит\n");
			} else {
				printf("Впереди\n");
			}
		} 
	}

	// если все координаты отрицательные
	if (arctanB < 0 && arctanA < 0) {
		// проверка слева / справа
		arctanB = -1 * arctanB;
		arctanA = -1 * arctanA;
		if (arctanB > arctanA) {
			printf("Справа\n");
		}
		if (arctanB < arctanA) {
			printf("Слева\n");
		}

		if (arctanA == arctanB) {
			if(ab <= ae && bc <= ed) {
				printf("Принадлежит\n");
			} else {
				printf("Впереди\n");
			}
		} 
	}

	return 0;
}
