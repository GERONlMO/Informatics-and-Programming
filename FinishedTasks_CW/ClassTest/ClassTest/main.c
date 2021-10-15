#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	char* locale = setlocale(LC_ALL, "");

	int n, a, k, i, *Massive;
	printf("");
	scanf_s("%d", &n);
	printf("");
	scanf_s("%d", &a);

	srand(time(0));
	Massive = malloc(n * sizeof(int));
	printf("");

	for (i = 0; i < n; i++)
	{
		Massive[n] = -a + rand() % a;
	}

	for (i = 0; i < k; i++) {
		int sdvig = Massive[n - 1];
	}
}