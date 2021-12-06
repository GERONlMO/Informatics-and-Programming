#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>

long long Factorial(int n) {
	return (n < 2) ? 1 : n * Factorial(n - 1);
}

long double sinTalor(double x, int n, double eps, double etalon, int *count) {
	long double res = 0;
	int i;
	*count = 0;
	for (i = 1; i <= n; i++) {
		res += pow(-1, i + 1) * pow(x, 2 * i - 1) / (long double)Factorial(2 * i - 1);
		*count += 1;
		if (fabs(etalon - res) < eps) break;
	}
	return res;
}

long double cosTalor(double x, int n, double eps, double etalon, int* count) {
	long double res = 0;
	int i;
	*count = 0;
	for (i = 0; i <= n; i++) {
		res += pow(-1, i) * pow(x, 2 * i) / (long double)Factorial(2 * i);
		*count += 1;
		if (fabs(etalon - res) < eps) break;
	}
	return res;
}

long double expTalor(double x, int n, double eps, double etalon, int* count) {
	long double res = 1;
	int i;
	*count = 0;
	for (i = 1; i <= n; i++) {
		res += pow(x, i) / (long double)Factorial(i);
		*count += 1;
		if (fabs(etalon - res) < eps) break;
	}
	return res;
}

long double arcctgTalor(double x, int n, double eps, double etalon, int* count) {
	long double res = M_PI_2;
	int i;
	*count = 0;
	for (i = 0; i <= n; i++) {
		res += pow(-1, i + 1) * pow(x, 2 * i + 1) / (long double)(2 * i + 1);
		*count += 1;
		if (fabs(etalon - res) < eps) break;
	}
	return res;
}

void functions(int VariantOfFunction, double x, int n, double *etalon, long double *result, double*difference, double eps, int *count) {
	switch (VariantOfFunction)
	{
	case 1:
		*etalon = sin(x);
		*result = sinTalor(x, n, eps, *etalon, count);
		*difference = fabs((*etalon) - (*result));
		break;
	case 2:
		*etalon = cos(x);
		*result = cosTalor(x, n, eps, *etalon, count);
		*difference = fabs((*etalon) - (*result));
		break;
	case 3:
		*etalon = exp(x);
		*result = expTalor(x, n, eps, *etalon, count);
		*difference = fabs((*etalon) - (*result));
		break;
	case 4:
		*etalon = atan(x);
		*result = arcctgTalor(x, n, eps, *etalon, count);
		*difference = fabs((*etalon) - (*result));
		break;
	default:
		break;
	}
}

int main() {
	int VariantOfProg, VariantOfFunction, n = 0, NMax = 0, count = 0;
	double x = 0, etalon = 0, difference = 0;
	double eps = 0.000001;
	long double result = 0;

	srand(time(NULL));

	void (*func)(int, double, int, double*, long double*, double*, double, int*);
	func = functions;

	printf("Select a program:\n");
	printf("1. One-time calculation of the function at a given point.\n");
	printf("2. Serial experiment.\n");
	scanf_s("%d", &VariantOfProg);

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
		scanf_s("%d", &n);

		func(VariantOfFunction, x, n, &etalon, &result, &difference, eps, &count);

		printf("Etalon value: %lf\n", etalon);
		printf("Taylor function value: %Lf\n", result);
		printf("Difference between Taylor and reference:%lf\n", difference);
		printf("The number of terms that was calculated: %d\n", count);

		break;
	case 2:
		srand(time(NULL));
		printf("Enter the number of experiments (NMax - 1 to 25):\n");
		scanf_s("%d", &NMax);

		for (int i = 1; i <= NMax; i++) {
			n = 1 + rand() % (1000 - 1 + 1);
			func(VariantOfFunction, x, n, &etalon, &result, &difference, eps, &count);
			printf("%2d. Etalon: %lf \t", i, etalon);
			printf("Summand: %d \t", count);
			printf("Result: %Lf \t", result);
			printf("Difference: %lf \n", difference);
		}
		break;
	default:
		break;
	}
	return 0;
}