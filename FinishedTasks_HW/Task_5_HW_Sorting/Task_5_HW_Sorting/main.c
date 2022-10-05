// Copyright 2021 Novostroev Ivan

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

long int sortInsert(int* array, int size) {           // Сортировка вставками
    int temp;
    long int swaps = 0;
    for (int i = 1; i < size; i++)
        for (int j = i; j > 0 && array[j - 1] > array[j]; j--) {
            temp = array[j - 1];
            array[j - 1] = array[j];
            array[j] = temp;
            swaps++;
        }
    return swaps;
}

int sortHoare(int* array, int first, int last) {       // Сортировка Фоара
    int swaps = 0;
    int i = first, j = last, x = array[(first + last) / 2];
    do {
        while (array[i] < x) i++;
        while (array[j] > x) j--;
        if (i <= j) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                swaps++;
            }
            i++;
            j--;
        }
    } while (i <= j);
    if (i < last)
        sortHoare(array, i, last);
    if (first < j)
        sortHoare(array, first, j);
    return swaps;
}

void shiftDown(int* array, int root, int bottom) {       // Пирамидальная сортировка
    int maxChild;
    int done = 0;
    while ((root * 2 <= bottom) && (!done)) {
        if (root * 2 == bottom)
            maxChild = root * 2;
        else if (array[root * 2] > array[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        if (array[root] < array[maxChild]) {
            int temp = array[root];
            array[root] = array[maxChild];
            array[maxChild] = temp;
            root = maxChild;
        }
        else
            done = 1;
    }
}

int sortHeap(int* array, int size) {
    int swaps = 0;
    for (int i = (size / 2); i >= 0; i--)
        shiftDown(array, i, size - 1);
    for (int i = size - 1; i >= 1; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        swaps++;
        shiftDown(array, 0, i - 1);
    }
    return swaps;
}

void generateRandNumber(int* array, int size, int min, int max) {     // Генерация чисел
    for (int i = 0; i < size; i++)
        array[i] = min + rand() % (max - min + 1);
}

int main() {
    char* locale = setlocale(LC_ALL, "");

    srand(time(NULL));
    
    float time;
    int* array = NULL;
    int size = 0;
    long int swaps = 0;
    int min, max;

    printf("Введите размер массива: ");
    scanf_s("%d", &size);

    array = (int*)malloc(size * sizeof(int));

    printf("Введите минимальное и максимальное допустимое число в составе массива: ");
    scanf_s("%d %d", &min, &max);

    generateRandNumber(array, size, min, max);
    time = clock();
    swaps = sortInsert(array, size);
    time = clock() - time;
    printf("\n  Название сортировки      | Время работы | Количество перестановок\n");
    printf("  Сортировка вставками     |     %.2fs    | %ld\n", time / 1000, swaps);

    generateRandNumber(array, size, min, max);
    time = clock();
    swaps = sortHoare(array, 0, size - 1);
    time = clock() - time;
    printf("  Сортировка Хоара         |     %.2fs    | %d\n", time / 1000, swaps);

    generateRandNumber(array, size, min, max);
    time = clock();
    swaps = sortHeap(array, size);
    time = clock() - time;
    printf("  Пирамидальная сортировка |     %.2fs    | %d\n", time / 1000, swaps);
}