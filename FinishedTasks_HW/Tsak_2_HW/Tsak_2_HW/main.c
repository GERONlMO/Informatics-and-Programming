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
            if (48 <= ch && ch <= 57){
                flag = 1;
                numbers++;
            }
            if ((-128 <= ch && ch <= -17) || ((65 <= ch && ch <= 90) || (97 <= ch && ch <= 122))) {
                flag = 1;
                words++;
            }
        }
    }
    printf("Слова: %u\n", words);
    printf("Числа: %u\n", numbers);
}