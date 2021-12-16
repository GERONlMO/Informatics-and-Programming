#include "functions.h"

typedef struct Answer(*funtionsType) (double, double, int, int);
funtionsType functions[4];

int main() {
	int VariantOfProg, VariantOfFunction, N = 0, NMax = 0, i = 0;
	double x = 0, etalon = 0, difference = 0;
	double eps = 0.000001;

	printf("Select a program:\n");
	printf("1. One-time calculation of the function at a given point.\n");
	printf("2. Serial experiment.\n");
	scanf_s("%d", &VariantOfProg);
		
	functions[0] = sinTalor;
	functions[1] = cosTalor;
	functions[2] = expTalor;
	functions[3] = arcctgTalor;

	printf("Select function:\n");
	printf("1. sin(x)\n");
	printf("2. cos(x)\n");
	printf("3. exp(x)\n");
	printf("4. arcctg(x), |x| <= 1\n");
	scanf_s("%d", &VariantOfFunction);
	printf("Enter point x:\n");
	scanf_s("%lf", &x);

	switch (VariantOfProg)
	{
	case 1:
		printf("Enter the precision of the calculation (from 0.000001 and more):\n");
		scanf_s("%lf", &eps);
		printf("Enter the number of elements to calculate (N - from 1 to 1000):\n");
		scanf_s("%d", &N);

		finalResult = functions[VariantOfFunction - 1](x, eps, N, i);

		printf("Etalon value: %lf\n", finalResult.etalon);
		printf("Taylor function value: %lf\n", finalResult.result);
		printf("Difference between Taylor and reference:%lf\n", finalResult.difference);
		printf("The number of terms that was calculated: %d\n", finalResult.count);

		break;
	case 2:
		srand(time(NULL));
		printf("Enter the number of experiments (NMax - 1 to 25):\n");
		scanf_s("%d", &NMax);

		for (int i = 1; i <= NMax; i++) {
			N = 1 + rand() % (1000 - 1 + 1);
			finalResult = functions[VariantOfFunction - 1](x, eps, N, i);
			printf("%2d. Etalon: %lf \t", i, finalResult.etalon);
			printf("Summand: %d \t", N);
			printf("Result: %Lf \t", finalResult.result);
			printf("Difference: %lf \n", finalResult.difference);
		}
		break;
	default:
		break;
	}
	return 0;
}