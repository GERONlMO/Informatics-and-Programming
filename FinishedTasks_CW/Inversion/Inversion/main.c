#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

int main() {
    char* locale = setlocale(LC_ALL, "");

    int isWork = 1;
    int VariantOfProg, number;

    while (isWork) {
        printf("�������� ������� ���������:\n");
        printf("  �������� �����(������� 1)\n  ����� ���� �����(������� 2)\n  ����� �� ���������(������� 0)\n");
        scanf_s("%d", &VariantOfProg);
        int changeMode = 0;
        
        if (VariantOfProg == 0) return exit;

        while (!changeMode) {
            int isError = 0;
            do {
                if (isError)
                    printf("�� ����� ������������ �����, ���������� ��� ���!\n");
                    printf("������� 0 ��� �������� � ������ ������.\n");

                printf("������� ������������� ����� : \n");
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
            printf("��������� ���������: %d\n", result);
        }
    }
}