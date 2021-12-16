#include "functions.h"

long long Factorial(int N) {
	return (N < 2) ? 1 : N * Factorial(N - 1);
}

struct Answer sinTalor(double x, double eps, int N, int i) {
	struct Answer result;
	result.etalon = sin(x);
	result.result = 0;
	for (i = 1; i <= N; i++) {
		result.result += pow(-1, i + 1) * pow(x, 2 * i - 1) / (long double)Factorial(2 * i - 1);
		if (fabs(result.etalon - result.result) < eps) break;
	}
	result.difference = fabs(result.etalon - result.result);
	result.count = i - 1;
	return result;
}

struct Answer cosTalor(double x, double eps, int N, int i) {
	struct Answer result;
	result.etalon = cos(x);
	result.result = 0;
	for (i = 0; i < N; i++) {
		result.result += pow(-1, i) * pow(x, 2 * i) / (long double)Factorial(2 * i);
		if (fabs(result.etalon - result.result) < eps) break;
	}
	result.difference = fabs(result.etalon - result.result);
	result.count = i;
	return result;
}

struct Answer expTalor(double x, double eps, int N, int i) {
	struct Answer result;
	result.etalon = exp(x);
	result.result = 0;
	for (i = 0; i < N; i++) {
		result.result += pow(x, i) / (long double)Factorial(i);
		if (fabs(result.etalon - result.result) < eps) break;
	}
	result.difference = fabs(result.etalon - result.result);
	result.count = i;
	return result;
}

struct Answer arcctgTalor(double x, double eps, int N, int i) {
	struct Answer result;
	result.etalon = exp(x);
	result.result = M_PI_2;
	for (i = 0; i < N; i++) {
		result.result += pow(-1, i + 1) * pow(x, 2 * i + 1) / (long double)(2 * i + 1);;
		if (fabs(result.etalon - result.result) < eps) break;
	}
	result.difference = fabs(result.etalon - result.result);
	result.count = i;
	return result;
}