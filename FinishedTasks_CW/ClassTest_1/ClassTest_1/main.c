// Copyright 2021 Novostroev Ivan

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int size1 = 0;

void swap(int* array, int indx1, int indx2) {
    int temp = array[indx1];
    array[indx1] = array[indx2];
    array[indx2] = temp;
}

int evenElem(int* array, int size) {
    int k = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            k++;
        }
    }
    int* copy = (int*)malloc(k * sizeof(int));
    k = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            copy[k] = array[i];
            k++;
        }
    }
    size1 = k;
    return copy;
}

int halfSort(int* array, int size) {
    int temp;
    for (int j = 0; j < (size/2 - 1); j++) {
        for (int i = 0; i < (size / 2 - 1); i++) {
            if (array[i] > array[i + 1]) {
                swap(array, i, i + 1);
            }
        }
    }
    return array;
}

int plusMinus(int* array, int size) {
    int k = 0;
    int* copy = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        if (array[i] < 0) {
            copy[k] = array[i];
            k++;
        }
    }
    for (int i = 0; i < size; i++) {
        if (array[i] >= 0) {
            copy[k] = array[i];
            k++;
        }
    }
    return copy;
}

int generateRandNumber(int max, int min) {
    int value = (max - min) * ((float)rand() / RAND_MAX) + min;
    return value;
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
	char* locale = setlocale(LC_ALL, "");

    srand(time(NULL));

    int* array = NULL;
    int* array1 = NULL;
    int* array2 = NULL;
    int* array3 = NULL;
    int size = 0;
    int min, max;

    printf("Введите размер массива: ");
    scanf_s("%d", &size);

    array = (int*)malloc(size * sizeof(int));
    array1 = (int*)malloc(size * sizeof(int));
    array2 = (int*)malloc(size * sizeof(int));
    array3 = (int*)malloc(size * sizeof(int));

    printf("Введите минимальное и максимальное допустимое число в составе массива: ");
    scanf_s("%d %d", &min, &max);

    for (int i = 0; i < size; i++) {
        array[i] = generateRandNumber(max, min);
        array1[i] = array[i]; array2[i] = array[i]; array3[i] = array[i];
    }

    printf(" Изначальный массив:\n");
    printArray(array, size);

    printf(" Массив четных элементов (по значению):\n");
    array1 = evenElem(array1, size);
    printArray(array1, size1);

    printf(" Массив с отсортированной половиной элементов:\n");
    array2 = halfSort(array2, size);
    printArray(array2, size);

    printf(" Массив c отрицательными элементами в начале массива и положительными в конце:\n");
    array3 = plusMinus(array3, size);
    printArray(array3, size);

	return 0;
}