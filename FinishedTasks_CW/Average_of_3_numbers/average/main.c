#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	char* locale = setlocale(LC_ALL, "");

	float a, b, c;
	float Result_1, Result_2, Result_3, Result_4;

	printf("������� 3 �����:\na = ");
	scanf_s("%f", &a);
	printf("b = ");
	scanf_s("%f", &b);
	printf("c = ");
	scanf_s("%f", &c);

	Result_1 = (a + b + c) / 3;
	Result_2 = (pow(a, 2) + pow(b, 2) + pow(c, 2)) / 3;
	Result_3 = (abs(a) + abs(b) + abs(c)) / 3;
	Result_4 = (sqrt(a) + sqrt(b) + sqrt(c)) / 3;

	printf("C������ �������������� = %.2f\n\n", Result_1);
	printf("C������ ��������� ���� ����� = %.2f\n\n", Result_2);
	printf("C������ ������� (���������� ��������) ���� ����� = %.2f\n\n", Result_3);
	printf("C������ ������ ���� ����� = %.2f\n\n", Result_4);
}