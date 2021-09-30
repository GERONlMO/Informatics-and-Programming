#include <stdio.h>
#include <locale.h>

int main() {
    char* locale = setlocale(LC_ALL, "");

    char ch, flag = -1;
    unsigned words = 0;
    unsigned numbers = 0;

    printf("Введите строку для подсчета слов и чисел (для выхода нажмите ENTER):\n");

    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            break;
        }
        if (ch == ' ' || ch == '\t')
            flag = -1;
        else if (flag == -1) {
            if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9'){
                flag = 1;
                numbers++;
            }
            else
            {
                flag = 1;
                words++;
            }
        }
    }
    printf("Слова: %u\n", words);
    printf("Числа: %u\n", numbers);
}