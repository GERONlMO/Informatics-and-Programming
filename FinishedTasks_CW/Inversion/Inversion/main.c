#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

int main() {
    char* locale = setlocale(LC_ALL, "");

    int isWork = 1;
    int VariantOfProg, number;

    while (isWork) {
        printf("Выберите вариант программы:\n");
        printf("  Инверсия числа(нажмите 1)\n  Сумма цыфр числа(нажмите 2)\n  Выход из программы(нажмите 0)\n");
        scanf_s("%d", &VariantOfProg);
        int changeMode = 0;
        
        if (VariantOfProg == 0) return exit;

        while (!changeMode) {
            int isError = 0;
            do {
                if (isError)
                    printf("Вы ввели неправильное число, попробуйте еще раз!\n");
                    printf("Введите 0 для возврата к выбору режима.\n");

                printf("Введите положительное число : \n");
                scanf_s("%d", &number);

                if (number == 0) {
                    changeMode = 1;
                    break;
                }
                isError = (number < 0);

            } while (isError);

            if (changeMode || !isWork) break;

            int result = 0;
            switch (VariantOfProg) {
            case 1:
                do {
                    result = result * 10 + number % 10;
                    number = number / 10;
                } while (number);
                break;
            case 2:
                do {
                    result = result + number % 10;
                    number = number / 10;
                } while (number);
                break;
            default:
                break;
            }
            printf("Результат программы: %d\n", result);
        }
    }
}