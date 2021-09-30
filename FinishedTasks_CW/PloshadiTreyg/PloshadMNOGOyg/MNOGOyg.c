#include <stdio.h>
#include <math.h>

int main() {

	int a, b;
	printf("Vvedite parametr mnogoygol:\n a = ");
	scanf_s("%d", &a);
	printf(" b = ");
	scanf_s("%d", &b);

	int S;
	S = a * b;

	printf("Resultat: S = %d\n", S);

	return 0;
}