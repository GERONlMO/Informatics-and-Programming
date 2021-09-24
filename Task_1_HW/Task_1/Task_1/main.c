#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <string.h>

int main() {

	char* locale = setlocale(LC_ALL, "");

	int CoorX_1, CoorX_2, CoorY_1, CoorY_2, Figure;
	int count_Queen_da = 0, count_King_da = 0, count_Rook_da = 0, count_Bishop_da = 0, count_Knight_da = 0;

	printf("������� ���������� ������ ������(X, Y):\n");
	scanf_s("%d %d", &CoorX_1, &CoorY_1);
	printf("������� ���������� ������ ������(X, Y):\n");
	scanf_s("%d %d", &CoorX_2, &CoorY_2);

	printf("�������� ����� ������:\n 1.�����\n 2.������\n 3.�����\n 4.����\n 5.����\n ");
	scanf_s("%d", &Figure);


	if ((CoorX_1 == CoorX_2 || CoorY_1 == CoorY_2) || (abs(CoorX_2 - CoorX_1) == abs(CoorY_2 - CoorY_1))) {
		count_Queen_da++;
	}
	if ((abs(CoorX_2 - CoorX_1) == 1 && abs(CoorY_2 - CoorY_1) <= 1) || (abs(CoorY_2 - CoorY_1) == 1 && abs(CoorX_2 - CoorX_1) <= 1)) {
		count_King_da++;
	}
	if (abs(CoorX_2 - CoorX_1) == abs(CoorY_2 - CoorY_1)) {
		count_Rook_da++;
	}
	if (CoorX_1 == CoorX_2 || CoorY_1 == CoorY_2) {
		count_Bishop_da++;
	}
	if (((abs(CoorX_2 - CoorX_1) == 3) && (abs(CoorY_2 - CoorY_1) == 1)) || ((abs(CoorY_2 - CoorY_1) == 3) && (abs(CoorX_2 - CoorX_1) == 1))) {
		count_Knight_da++;
	}

	if (Figure == 1) {
		if (count_Queen_da > 0) {
			printf("����� ����� ������� �� ������ ������\n");
		}
		else {
			printf("����� �� ����� ������� �� ������ ������\n");
			printf("�����:\n");
			if (count_King_da > 0) {
				printf("������\n");
			}
			if (count_Rook_da > 0) {
				printf("�����\n");
			}
			if (count_Bishop_da > 0) {
				printf("����\n");
			}
			if (count_Knight_da > 0) {
				printf("����\n");
			}
		}	
	}
	if (Figure == 2) {
		if (count_King_da) {
			printf("������ ����� ������� �� ������ ������\n");
		}
		else {
			printf("������ �� ����� ������� �� ������ ������\n");
			printf("�����:\n");
			if (count_Queen_da > 0) {
				printf("�����\n");
			}
			if (count_Rook_da > 0) {
				printf("�����\n");
			}
			if (count_Bishop_da > 0) {
				printf("����\n");
			}
			if (count_Knight_da > 0) {
				printf("����\n");
			}
		}
	}
	if (Figure == 3) {
		if (count_Rook_da > 0) {
			printf("����� ����� ������� �� ������ ������\n");
		}
		else {
			printf("����� �� ����� ������� �� ������ ������\n");
			printf("�����:\n");
			if (count_King_da > 0) {
				printf("������\n");
			}
			if (count_Queen_da > 0) {
				printf("�����\n");
			}
			if (count_Bishop_da > 0) {
				printf("����\n");
			}
			if (count_Knight_da > 0) {
				printf("����\n");
			}
		}
	}
	if (Figure == 4) {
		if (count_Bishop_da > 0) {
			printf("���� ����� ������� �� ������ ������\n");
		}
		else {
			printf("���� �� ����� ������� �� ������ ������\n");
			printf("�����:\n");
			if (count_King_da > 0) {
				printf("������\n");
			}
			if (count_Rook_da > 0) {
				printf("�����\n");
			}
			if (count_Queen_da > 0) {
				printf("�����\n");
			}
			if (count_Knight_da > 0) {
				printf("����\n");
			}
		}
	}
	if (Figure == 5) {
		if (count_Knight_da > 0) {
			printf("���� ����� ������� �� ������ ������\n");
		}
		else {
			printf("���� �� ����� ������� �� ������ ������\n");
			printf("�����:\n");
			if (count_King_da > 0) {
				printf("������\n");
			}
			if (count_Rook_da > 0) {
				printf("�����\n");
			}
			if (count_Queen_da > 0) {
				printf("�����\n");
			}
			if (count_Bishop_da > 0) {
				printf("����\n");
			}
		}
	}
	return 0;
}