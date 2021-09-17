#include <math.h>
#include <stdio.h>

int main() {

	float coorX_1, coorY_1, r1, coorX_2, coorY_2, r2;
	float d;
	printf("Vvedite coordinat okryz 1:\nx = ");
	scanf_s("%f", &coorX_1);
	printf("y = ");
	scanf_s("%f", &coorY_1);
	printf("Vvedite radius okryz 1:\nr = ");
	scanf_s("%f", &r1);

	printf("Vvedite coordinat okryz 2:\nx = ");
	scanf_s("%f", &coorX_2);
	printf("y = ");
	scanf_s("%f", &coorY_2);
	printf("Vvedite radius okryz 2:\nr = ");
	scanf_s("%f", &r2);

	d = sqrt(pow(coorX_2 - coorX_1, 2) + pow(coorY_2 - coorY_1, 2));

	if (d == r1 + r2) {
		printf("Kasaetsy");
	}
	if (d < r1 + r2) {
		if (d == 0 && r1 == r2) {
			printf("Covpadaet");
		}
		else if (d + r1 < r2 || d + r2 < r1) {
			printf("Odna v drygoi");
		}
		else {
			printf("Peresekaet");
		}
	}
	if (d > r1 + r2) {
		printf("Nnesvyzan");
	}
}