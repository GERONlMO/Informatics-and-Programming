#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    char* locale = setlocale(LC_ALL, "");
    int j, try_number, n, * computerNumber_massive;
    int i = 0;

    printf("Играем в игру \"Быки и коровы\"\n");
    printf("Введите размер числа (от 2 до 5): \n");
    scanf_s("%d", &n);

    srand(time(0));
    computerNumber_massive = malloc(n * sizeof(int));

    while (i < n) {
        if (i == 0) {
            computerNumber_massive[i] = 1 + rand() % 9;
            i++;
        }
        else
        {
            try_number = rand() % 9;
            int ok = 1;
            for (j = 0; ok && j != i; j++) {
                ok &= (try_number != computerNumber_massive[j]);
            }
            if (ok) {
                computerNumber_massive[i] = try_number;
                i++;
            }
        }
    }

    int userNumber, numbers_OF_userNumber, * userNumber_massive;
    while (1) {

        printf("\nУгадайте число размером %d (цыфры в числе не должны повторяться): \n", n);
        scanf_s("%d", &userNumber);

        userNumber_massive = malloc(n * sizeof(int));
        int k = n;
        while (k > 0) {
            numbers_OF_userNumber = userNumber % 10;
            userNumber_massive[k - 1] = numbers_OF_userNumber;
            userNumber = userNumber / 10;
            k--;
        }
        int bull = 0;
        int cow = 0;
        for (int t1 = 0; t1 < n; t1++) {
            for (int t2 = 0; t2 < n; t2++) {
                if (userNumber_massive[t1] == computerNumber_massive[t2] && t1 == t2) {
                    bull++;
                    if (bull == n) {
                        printf("У вас все быки, вы ВЫЙГРАЛИ!!!\n");
                        return exit;
                    }
                }
                else if (userNumber_massive[t1] == computerNumber_massive[t2] && t1 != t2) {
                    cow++;
                }
            }
        }
        printf("Количество коров: %d\nКолличество быков: %d\n", cow, bull);
    }

    free(userNumber_massive);
    free(computerNumber_massive);
    return 0;
}