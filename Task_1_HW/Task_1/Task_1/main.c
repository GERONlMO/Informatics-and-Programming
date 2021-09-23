#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <string.h>

int main() {

	char* locale = setlocale(LC_ALL, "");

	int CoorX_1, CoorX_2, CoorY_1, CoorY_2, Figure;

	printf("������� ���������� ������ ������(X, Y): ");
	scanf_s("%d %d", &CoorX_1, &CoorY_1);
	printf("������� ���������� ������ ������(X, Y): ");
	scanf_s("%d %d", &CoorX_2, &CoorY_2);

	printf("�������� ����� ������:\n 1.�����\n 2.������\n 3.�����\n 4.����\n 5.����\n ");
	scanf_s("%d", &Figure);

	if (Figure == 1) {
		printf("�� ������� �����\n");

		if ((CoorX_1 == CoorX_2 || CoorY_1 == CoorY_2) || (abs(CoorX_2 - CoorX_1) == abs(CoorY_2 - CoorY_1))) {
			printf("����� ����� ������� �� ������ ������\n");
		}
		else {
			printf("����� �� ����� ������� �� ������ ������\n");
		}
	}
	else if (Figure == 2) {
		printf("�� ������� ������\n");

		if ((abs(CoorX_2 - CoorX_1) == 1 && abs(CoorY_2 - CoorY_1) <= 1) || (abs(CoorY_2 - CoorY_1) == 1 && abs(CoorX_2 - CoorX_1) <= 1)) {
			printf("������ ����� ������� �� ������ ������\n");
		}
		else {
			printf("������ �� ����� ������� �� ������ ������\n");
		}
	}
	else if (Figure == 3) {
		printf("�� ������� �����\n");

		if (abs(CoorX_2 - CoorX_1) == abs(CoorY_2 - CoorY_1)) {
			printf("����� ����� ������� �� ������ ������\n");
		}
		else {
			printf("����� �� ����� ������� �� ������ ������\n");
		}

	}
	else if (Figure == 4) {
		printf("�� ������� �����\n");

		if (CoorX_1 == CoorX_2 || CoorY_1 == CoorY_2) {
			printf("���� ����� ������� �� ������ ������\n");
		}
		else {
			printf("���� �� ����� ������� �� ������ ������\n");
		}
	}
	else if (Figure == 5) {
		printf("�� ������� ������\n");

		if (((abs(CoorX_2 - CoorX_1) == 3) && (abs(CoorY_2 - CoorY_1) == 1)) || ((abs(CoorY_2 - CoorY_1) == 3) && (abs(CoorX_2 - CoorX_1) == 1))) {
			printf("������ ����� ������� �� ������ ������\n");
		}
		else {
			printf("������ �� ����� ������� �� ������ ������\n");
		}
	}
	return 0;
}