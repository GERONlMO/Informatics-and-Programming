#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <malloc.h>

#define size 10

char products[size][40] = { {"Samsung Galaxy S8+ 64GB"}, {"Xiaomi Mi8 6/64GB"}, {"ASUS ZenFone 5 ZE620KL 4/64GB"}, {"Xiaomi Redmi Note 5 4/64GB"}, {"Samsung Galaxy J8 (2018) 32GB"}, {"Huawei P20 Lite"}, {"Huawei P smart 32GB"}, {"Xiaomi Redmi 6 3/32GB"}, {"Xiaomi Redmi 6A 2/16GB"}, {"Xiaomi Redmi S2 3/32GB"} };
int barcode[size][4];
int price[size] = { 40000, 25000, 21000, 18000, 15999, 14500, 12300, 12450, 11550, 11111 };
int discount[size];

int generateRandNumber(int max, int min) {  // �����������
    int value = min + rand() % (max - min + 1);
    return value;
}

void printInformation_Barcode(int number) {  // ����� ���������� �� ������
    printf("����� ���: ");
    for (int j = 0; j < 4; j++)
        printf("%d", barcode[number][j]);
    printf(" | ��������: %s | ", products[number]);
    printf("����: %d ������ | ", price[number]);
    printf("������: %d%% |\n", discount[number]);
}

int main() {
    char* locale = setlocale(LC_ALL, "");

    int isTotalWork = 1;
    int VariantOfProg;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 4; j++) {
            barcode[i][j] = generateRandNumber(9, 0);
        }
    }
    for (int i = 0; i < size; i++)
        discount[i] = generateRandNumber(50, 1);

    while (isTotalWork) {
    printf("����� ����������!\n\n");
    printf("��� ������ ������ ��������� ������� (1)\n");
    printf("��� ������ ���������� �� ��������� ������� (2)\n");
    printf("����� �������� ����� � ��� ������� (3)\n");
    printf("��� ��������� ���������� � ������� � ���� �� ������ ������ ������� (4)\n");
    printf("����� ������� �������� ��� ������� (5)\n");
    printf("��� ������ �� ��������� ������� (0)\n");
    printf("\n��� ��������� ���������� � ���� ������� -1\n");

    int isWork = 1;

    int checkProducts_index[size];
    int checkPrice[size];
    int numberOfProducts[size];
    int schetchik = 0;

    while (isWork) {
        printf("\n������� ������� ���������: ");
        scanf_s("%d", &VariantOfProg);
        printf("\n");

        int scanOfBarcode[4];
        int shtrix;
        int isWorkScanOfBarcode = 1;

        if (VariantOfProg == 0) return exit;

        switch (VariantOfProg) {
        case 1:
            printf("������ � �������:\n");
            for (int i = 0; i < size; i++) {
                printInformation_Barcode(i);
            }
            break;
        case 2:
            printf("��� ��������� ���������� � ������ ������� ����� ���: ");
            scanf_s("%d", &shtrix);
            int scanOfBarcode[4];
            for (int i = 3; i >= 0; i--) {
                scanOfBarcode[i] = shtrix % 10;
                shtrix = shtrix / 10;
            }
            int flag_2 = 1;
            for (int i = 0; i < size; i++) {
                if (scanOfBarcode[0] == barcode[i][0] && scanOfBarcode[1] == barcode[i][1] && scanOfBarcode[2] == barcode[i][2] && scanOfBarcode[3] == barcode[i][3]) {
                    printInformation_Barcode(i);
                    flag_2 = 0;
                    break;
                }
            }
            if (flag_2)
                printf("������ ������ �� ����������! ���������� ������ ������ ����� ���!\n");
            break;
        case 3:
            while (isWorkScanOfBarcode) {
                printf("\n������� ����� ��� (��� ����������� ����� ������� ������� -1): ");
                scanf_s("%d", &shtrix);
                if (shtrix == -1)
                    break;
                for (int i = 3; i >= 0; i--) {
                    scanOfBarcode[i] = shtrix % 10;
                    shtrix = shtrix / 10;
                }
                int flag_3 = 1;
                int ok_new = 1;
                for (int i = 0; i < size; i++) {
                    if (scanOfBarcode[0] == barcode[i][0] && scanOfBarcode[1] == barcode[i][1] && scanOfBarcode[2] == barcode[i][2] && scanOfBarcode[3] == barcode[i][3]) {
                        for (int j = 0; j < size; j++) {
                            if (checkProducts_index[j] == i) {
                                numberOfProducts[j] += 1;
                                checkPrice[j] += price[i];
                                ok_new = 0;
                                break;
                            }
                        }
                        if (ok_new) {
                            checkProducts_index[schetchik] = i;
                            numberOfProducts[schetchik] = 1;
                            checkPrice[schetchik] = price[i];
                            schetchik += 1;
                        }
                        printf("\n����� �������� � ���!\n");
                        flag_3 = 0;
                    }
                }
                if (flag_3)
                    printf("\n������ ������ �� ����������! ���������� ������ ������ ����� ���!\n");
            }
            break;
        case 4:
            printf("��������� ���� �� ������ ������:\n\n");
            int flag_4 = 1;
            int notTotalPrice = 0;
            int totalDiscount;
            float totalPrice = 0;
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++){
                    if (checkProducts_index[i] == j) {
                        printf("��������: %s | ", products[j]);
                        printf("����������: %d | ", numberOfProducts[i]);
                        printf("����� ����: %d ������ | ", checkPrice[i]);
                        printf("������: %d%%\n", discount[j]);
                        totalPrice += checkPrice[i] - ((checkPrice[i] * discount[j]) / 100);
                        notTotalPrice += checkPrice[i];
                        flag_4 = 0;
                    }
                }
            }
            if (!flag_4) {
                totalDiscount = 100 - ((totalPrice / notTotalPrice) * 100);
                printf("\n����� ��������� ������� ��� ������: %d ������\n", notTotalPrice);
                printf("����� ��������� ������� �� �������: %.2f ������\n", totalPrice);
                printf("����� ������: %d%%\n", totalDiscount);
            }
            if (flag_4)
                printf("��� ����!\n");
                break;
            case 5:
                printf("������� ���:\n\n");
                int flag_5 = 1;
                int last_notTotalPrice = 0;
                int last_totalDiscount;
                float last_totalPrice = 0;
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size; j++) {
                        if (checkProducts_index[i] == j) {
                            printf("��������: %s | ", products[j]);
                            printf("����������: %d | ", numberOfProducts[i]);
                            printf("����� ����: %d ������ | ", checkPrice[i]);
                            printf("������: %d%%\n", discount[j]);
                            last_totalPrice += checkPrice[i] - ((checkPrice[i] * discount[j]) / 100);
                            last_notTotalPrice += checkPrice[i];
                            flag_5 = 0;
                        }
                    }
                }
                if (!flag_5) {
                    last_totalDiscount = 100 - ((last_totalPrice / last_notTotalPrice) * 100);
                    printf("\n����� ��������� ������� ��� ������: %d ������\n", last_notTotalPrice);
                    printf("����� ��������� ������� �� �������: %.2f ������\n", last_totalPrice);
                    printf("����� ������: %d%%\n", last_totalDiscount);
                }
                if (flag_5)
                    printf("�������� ��� ����!\n");
                printf("\n������� �� �������, ��������� ���!\n");
                return exit;
            case -1:
                isWork = 0;
                break;
            default:
                break;
            }
        }
    }
}