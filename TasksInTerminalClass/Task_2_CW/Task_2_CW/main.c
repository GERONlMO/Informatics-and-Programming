#include <stdio.h>
#include <locale.h>

int main() {

	char* locale = setlocale(LC_ALL, "");

	int m1 = 25, m2 = 10, m3 = 5, m4 = 1, i = 0, k1 = 0, k2 = 0, k3 = 0, k4 = 0;
	int price;

	printf("Введите цену заказа:\n");
	scanf_s("%d", &price);

	while (price > 0) {
		while (price >= m1) {
			price = price - m1;
			k1++;
			i++;
		}
		while (price >= m2) {
			price = price - m2;
			k2++;
			i++;
		}
		while (price >= m3) {
			price = price - m3;
			k3++;
			i++;
		}
		while (price >= m4) {
			price = price - m4;
			k4++;
			i++;
		}
	}
	printf("Минимальное количество монет: %d\n", i);
	printf("Монеты по наминалу:\n");
	printf("25 = %d, 10 = %d, 5 = %d, 1 = %d\n", k1, k2, k3, k4);

	return 0;
}
