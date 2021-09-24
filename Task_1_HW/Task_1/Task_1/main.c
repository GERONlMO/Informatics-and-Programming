#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <string.h>

int main() {

	char* locale = setlocale(LC_ALL, "");

	int CoorX_1, CoorX_2, CoorY_1, CoorY_2, Figure;
	int count_Queen_da = 0, count_King_da = 0, count_Rook_da = 0, count_Bishop_da = 0, count_Knight_da = 0;

	printf("Введите координаты первой клетки(X, Y):\n");
	scanf_s("%d %d", &CoorX_1, &CoorY_1);
	printf("Введите координаты второй клетки(X, Y):\n");
	scanf_s("%d %d", &CoorX_2, &CoorY_2);

	printf("Выберете номер фигуры:\n 1.Ферзь\n 2.Король\n 3.Ладья\n 4.Слон\n 5.Конь\n ");
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
			printf("Ферзь может попасть на первую клетку\n");
		}
		else {
			printf("Ферзь не может попасть на первую клетку\n");
			printf("Могут:\n");
			if (count_King_da > 0) {
				printf("Король\n");
			}
			if (count_Rook_da > 0) {
				printf("Ладья\n");
			}
			if (count_Bishop_da > 0) {
				printf("Слон\n");
			}
			if (count_Knight_da > 0) {
				printf("Конь\n");
			}
		}	
	}
	if (Figure == 2) {
		if (count_King_da) {
			printf("Король может попасть на первую клетку\n");
		}
		else {
			printf("Король не может попасть на первую клетку\n");
			printf("Могут:\n");
			if (count_Queen_da > 0) {
				printf("Ферзь\n");
			}
			if (count_Rook_da > 0) {
				printf("Ладья\n");
			}
			if (count_Bishop_da > 0) {
				printf("Слон\n");
			}
			if (count_Knight_da > 0) {
				printf("Конь\n");
			}
		}
	}
	if (Figure == 3) {
		if (count_Rook_da > 0) {
			printf("Ладья может попасть на первую клетку\n");
		}
		else {
			printf("Ладья не может попасть на первую клетку\n");
			printf("Могут:\n");
			if (count_King_da > 0) {
				printf("Король\n");
			}
			if (count_Queen_da > 0) {
				printf("Ферзь\n");
			}
			if (count_Bishop_da > 0) {
				printf("Слон\n");
			}
			if (count_Knight_da > 0) {
				printf("Конь\n");
			}
		}
	}
	if (Figure == 4) {
		if (count_Bishop_da > 0) {
			printf("Слон может попасть на первую клетку\n");
		}
		else {
			printf("Слон не может попасть на первую клетку\n");
			printf("Могут:\n");
			if (count_King_da > 0) {
				printf("Король\n");
			}
			if (count_Rook_da > 0) {
				printf("Ладья\n");
			}
			if (count_Queen_da > 0) {
				printf("Ферзь\n");
			}
			if (count_Knight_da > 0) {
				printf("Конь\n");
			}
		}
	}
	if (Figure == 5) {
		if (count_Knight_da > 0) {
			printf("Конь может попасть на первую клетку\n");
		}
		else {
			printf("Конь не может попасть на первую клетку\n");
			printf("Могут:\n");
			if (count_King_da > 0) {
				printf("Король\n");
			}
			if (count_Rook_da > 0) {
				printf("Ладья\n");
			}
			if (count_Queen_da > 0) {
				printf("Ферзь\n");
			}
			if (count_Bishop_da > 0) {
				printf("Слон\n");
			}
		}
	}
	return 0;
}