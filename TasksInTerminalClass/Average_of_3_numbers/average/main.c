#include <stdio.h>
#include <math.h>

int main() {

	float a, b, c;

	printf("Vvedite 3 chisla:\na = ");
	scanf_s("%f", &a);
	printf("b = ");
	scanf_s("%f", &b);
	printf("c = ");
	scanf_s("%f", &c);

	float Result;

	Result = (a + b + c) / 3;

	printf("Resultat = %.2f", Result);

}