#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <malloc.h>

int main() {

	char* locale = setlocale(LC_ALL, "");

	int n, a1, a2, k;
	int* massive;

	printf("������� ������ �������: \n");
	scanf_s("%d", &n);
	printf("������� ��������: \n");
	scanf_s("%d", &a1);

	srand(time(0));
	massive = malloc(n * sizeof(int));;
	printf("��������� ������: \n");

	for (int i = 0; i < n; i++) {
		massive[i] = rand() % (2 * a1 - 1) - a1;
		printf(" %d ", massive[i]);
	}

	printf("\n������� ������ ������� � �����: \n");
	scanf_s("%d", &k);

	for (int i = 0; i < k; i++) {
		int sdvig = massive[n - 1];
		for (int h = n - 1; h > -1; h--) {
			massive[h] = massive[h - 1];
		}
		massive[0] = sdvig;
	}

	printf("��������� ������: \n");
	for (int i = 0; i < n; i++) {
		printf(" %d ", massive[i]);
	}

	for (int i = 0; i < n / 2; i++) {
		int per = massive[i];
		massive[i] = massive[n - i - 1];
		massive[n - i - 1] = per;
	}

	printf("\n�������� ���������: \n");
	for (int i = 0; i < n; i++) {
		printf(" %d ", massive[i]);
	}

	return 0;
}