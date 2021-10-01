#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	char* locale = setlocale(LC_ALL, "");

	int number;
	int isWork_Programm = 1;
	int isWork_Inversion = 1;
	int isWork_SummOfNumbers = 1;
	int VariantOfProg = 0;

	while (isWork_Programm) {
		printf("�������� ������� ���������:\n");
		printf("  �������� �����(������� 1)\n  ����� ���� �����(������� 2)\n  ����� �� ���������(������� 0)\n");
		scanf_s("%d", &VariantOfProg);

		if (VariantOfProg == 1) {
			isWork_Inversion = 1;
			isWork_SummOfNumbers = 0;
		}
		if (VariantOfProg == 2) {
			isWork_SummOfNumbers = 1;
			isWork_Inversion = 0;
		}
		if (VariantOfProg == 0) {
			isWork_Programm = 0;
			printf("�� ������ �������!\n");
			break;
		}

		while (isWork_Inversion) {
			printf("����������� �����!\n");
			printf("��� ������ � ������� ���� ������� 0\n");

			int isError = 0;
			do {
				if (isError)
					printf("�� ����� ������������ �����, ���������� ��� ���!\n");

				printf("������� ������������� �����: \n");
				scanf_s("%d", &number);

				if (number == 0) {
					isWork_Inversion = 0;
					printf("�� ������� � ������� ����\n\n");
					break;
				}

				isError = (number < 0);

			} while (isError);

			if (isWork_Inversion) {
				int result = 0;
				printf("���� �����: %d\n", number);

				do {
					result = result * 10 + number % 10;
					number = number / 10;
				} while (number);

				printf("��������� �������� : %d\n", result);
			}
		}

		while (isWork_SummOfNumbers) {
			printf("��������� ����� �����!\n");
			printf("��� ������ � ������� ���� ������� 0\n");

			int isError = 0;
			do {
				if (isError)
					printf("�� ����� ������������ �����, ���������� ��� ���!\n");

				printf("������� ������������� �����:\n");
				scanf_s("%d", &number);

				if (number == 0) {
					isWork_SummOfNumbers = 0;
					printf("�� ������� � ������� ����\n\n");
					break;
				}

				isError = (number < 0);

			} while (isError);

			if (isWork_SummOfNumbers) {
				int result = 0;
				printf("���� �����: %d\n", number);

				do {
					result = result + number % 10;
					number = number / 10;
				} while (number);

				printf("����� ����: %d\n", result);
			}
		}
	}
	return 0;
}