#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <string.h>

int main() {

	char* locale = setlocale(LC_ALL, "");

	int CoorX_1, CoorX_2, CoorY_1, CoorY_2, Figure;

	printf("Введите координаты первой клетки(X, Y): ");
	scanf_s("%d %d", &CoorX_1, &CoorY_1);
	printf("Введите координаты второй клетки(X, Y): ");
	scanf_s("%d %d", &CoorX_2, &CoorY_2);

	printf("Выберете номер фигуры:\n 1.Ферзь\n 2.Король\n 3.Ладья\n 4.Слон\n 5.Конь\n ");
	scanf_s("%d", &Figure);

	if (Figure == 1) {
		printf("Вы выбрали ферзя\n");

		if ((CoorX_1 == CoorX_2 || CoorY_1 == CoorY_2) || (abs(CoorX_2 - CoorX_1) == abs(CoorY_2 - CoorY_1))) {
			printf("Ферзь может попасть на первую клетку\n");
		}
		else {
			printf("Ферзь не может попасть на первую клетку\n");
		}
	}
	else if (Figure == 2) {
		printf("Вы выбрали короля\n");

		if ((abs(CoorX_2 - CoorX_1) == 1 && abs(CoorY_2 - CoorY_1) <= 1) || (abs(CoorY_2 - CoorY_1) == 1 && abs(CoorX_2 - CoorX_1) <= 1)) {
			printf("Король может попасть на первую клетку\n");
		}
		else {
			printf("Король не может попасть на первую клетку\n");
		}
	}
	else if (Figure == 3) {
		printf("Вы выбрали ладью\n");

		if (abs(CoorX_2 - CoorX_1) == abs(CoorY_2 - CoorY_1)) {
			printf("Ладья может попасть на первую клетку\n");
		}
		else {
			printf("Ладья не может попасть на первую клетку\n");
		}

	}
	else if (Figure == 4) {
		printf("Вы выбрали слона\n");

		if (CoorX_1 == CoorX_2 || CoorY_1 == CoorY_2) {
			printf("Слон может попасть на первую клетку\n");
		}
		else {
			printf("Слон не может попасть на первую клетку\n");
		}
	}
	else if (Figure == 5) {
		printf("Вы выбрали лошадь\n");

		if (((abs(CoorX_2 - CoorX_1) == 3) && (abs(CoorY_2 - CoorY_1) == 1)) || ((abs(CoorY_2 - CoorY_1) == 3) && (abs(CoorX_2 - CoorX_1) == 1))) {
			printf("Лошадь может попасть на первую клетку\n");
		}
		else {
			printf("Лошадь не может попасть на первую клетку\n");
		}
	}
	return 0;
}