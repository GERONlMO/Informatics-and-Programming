#include <math.h>
#include <stdio.h>
#include <locale.h>

int main() {
	char* locale = setlocale(LC_ALL, "");

	float coorX_1, coorY_1, r1, coorX_2, coorY_2, r2;
	float d;
	printf("������� ���������� ���������� 1:\nx = ");
	scanf_s("%f", &coorX_1);
	printf("y = ");
	scanf_s("%f", &coorY_1);
	printf("������� ������ ���������� 1:\nr = ");
	scanf_s("%f", &r1);

	printf("������� ���������� ���������� 2:\nx = ");
	scanf_s("%f", &coorX_2);
	printf("y = ");
	scanf_s("%f", &coorY_2);
	printf("������� ������ ���������� 2:\nr = ");
	scanf_s("%f", &r2);

	d = sqrt(pow(coorX_2 - coorX_1, 2) + pow(coorY_2 - coorY_1, 2));

	if (d == r1 + r2) {
		printf("���������� ��������");
	}
	if (d < r1 + r2) {
		if (d == 0 && r1 == r2) {
			printf("���������� ���������");
		}
		else if (d + r1 < r2 || d + r2 < r1) {
			printf("���� ���������� ��������� � ������");
		}
		else {
			printf("���� ���������� ���������� ������");
		}
	}
	if (d > r1 + r2) {
		printf("���������� �� �������");
	}
}