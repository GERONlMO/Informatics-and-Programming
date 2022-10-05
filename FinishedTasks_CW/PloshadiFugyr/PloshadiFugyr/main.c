#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <locale.h>

int main() {
	char* locale = setlocale(LC_ALL, "");

	int a_3x, a_4x, b, h, r;
	float S_1;
	int S_2;
	double S_3;

	printf("Считаем площади 3 фигур:\n");
	printf("Для площади треугольника введите основание и высоту:\na = ");
	scanf_s("%d", &a_3x);
	printf("h = ");
	scanf_s("%d", &h);
	printf("Для площади прямоугольника введите две стороны:\na = ");
	scanf_s("%d", &a_4x);
	printf("b = ");
	scanf_s("%d", &b);
	printf("Для площади круга введите радиус:\nr = ");
	scanf_s("%d", &r);

	S_1 = 0.5 * a_3x * h;
	S_2 = a_4x * b;
	S_3 = M_PI * (r*r);

	printf("Площадь треугольника: S = %.2f\n", S_1);
	printf("Площадь прямоугольника: S = %d\n", S_2);
	printf("Площадь круга: S = %.2lf\n", S_3);

	return 0;
}