#include <stdio.h>
#include <math.h>

int main() {

	int a, b, c;

	printf("Vvedite 3 chisla:\na = ");
	scanf_s("%d", &a);
	printf("b = ");
	scanf_s("%d", &b);
	printf("c = ");
	scanf_s("%d", &c);

	float preResult = (abs(a) + abs(b) + abs(c));

	float Result;
	Result = preResult / 3;

	printf("Resultat = %.2f", Result);

}