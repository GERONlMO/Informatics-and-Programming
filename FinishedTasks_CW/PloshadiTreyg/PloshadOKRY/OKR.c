#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main() {

	int r;
	printf("Vvedite parametr kryga:\n r = ");
	scanf_s("%d", &r);

	double S;
	S = M_PI*(r*r);

	printf("Resultat: S = %.2lf\n", S);

	return 0;
}