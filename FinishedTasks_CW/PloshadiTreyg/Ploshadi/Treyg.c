#include <stdio.h>
#include <math.h>

int main() {

	int a, h;
	printf("Vvedite parametr treygolnika:\n a = ");
	scanf_s("%d", &a);
	printf(" h = ");
	scanf_s("%d", &h);

	float S;
	S = 0.5 * a * h;

	printf("Resultat: S = %.2f\n", S);

	return 0;
}