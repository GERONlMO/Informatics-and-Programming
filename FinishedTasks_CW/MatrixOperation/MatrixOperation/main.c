// Copyright 2021 Novostroev Ivan

/*
Постановка задачи.

Реализована некоторая программа, работающая с матричными операциями.

Программист начал работать над ней и понял, что в ней много дублирования кода.
Он посмотрел свой код и не увидел проблем в самом коде. Чтобы исправить
проблему дублирования он решил вынести часть кода в функции.
Помогите ему в этом, а также допишите функционал, который он не успел.
*/

#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

/// <summary>
/// генерация рандомного числа из указанного диапозона
/// </summary>
/// <param name="maximum">максимальное допустимое значение рандома</param>
/// <param name="minimun">минимальное допустимое значение рандома</param>
/// <returns>сгенерированное случайное значение</returns>
int generateRandNumber(int max, int min) {
    int value = min + rand() % (max - min + 1);
    return value;
}

/// <summary>
/// выделение указаного размера памяти
/// </summary>
/// <param name="matrix">матрица</param>
/// <param name="n">количество строк</param>
/// <param name="m">количество столбцов</param>
int** setMemory(int** matrix, int n, int m) {
    matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        matrix[i] = (int*)malloc(m * sizeof(int));
    return matrix;
}

/// <summary>
/// вывод матрицы на экран
/// </summary>
/// <param name="matrix">матрица</param>
/// <param name="n">количество строк</param>
/// <param name="m">количество столбцов</param>
void printMatrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/// <summary>
/// вывод вектора на экран
/// </summary>
/// <param name="x">координата вектора по x</param>
/// <param name="y">координата вектора по y</param>
void printVector(int x, int y) {
    printf("(%d, %d)\n", x, y);
}

/// <summary>
/// умножение матрицы на число
/// </summary>
/// <param name="matrix">исходная матрица</param>
/// <param name="n">количество строк для новой матрицы</param>
/// <param name="m">количество столбцов для новой матрицы</param>
/// <param name="number">число на которое умножаем</param>
/// <returns></returns>
int** multMatrixOnNumber(int** matrix, int n, int m, int* number) {
    int** res = NULL;                       // nullptr
    res = setMemory(res, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = matrix[i][j] * (*number);
        }
    }
    return res;
}

int** multMatrixOnMatrix(int** matrixA, int** matrixB, int n, int k, int m) {
    int** res = NULL;                       // nullptr
    res = setMemory(res, n, k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            res[i][j] = 0;
            for (int l = 0; l < m; l++) {
                res[i][j] += matrixA[i][l] * matrixB[l][j];
            }
        }
    }
    return res;
}

int** additionMatrix(int** matrixA, int** matrixB, int n, int m) {
    int** res = NULL;                       // nullptr
    res = setMemory(res, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return res;
}

int** matrixTransposition(int** matrix, int m, int n) {
    int** res = NULL;                       // nullptr
    res = setMemory(res, m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = matrix[j][i];
        }
    }
    return res;
}

void multVectorOnNumber(int x, int y, int value) {
    int resx = x * value;
    int resy = y * value;
    printVector(resx, resy);
}

void multVectorOnVector(int ax, int ay, int bx, int by) {
    int resx = ax * bx;
    int resy = ay * by;
    printVector(resx, resy);
}

void additionVectors(int ax, int ay, int bx, int by) {
    int resx = ax + bx;
    int resy = ay + by;
    printVector(resx, resy);
}

void fillArrayRandValues(int** matrix, int n, int m, int max, int min) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = generateRandNumber(max, min);
        }
    }
}

void freeMemory(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) free(matrix[i]);
    free(matrix);
}

int** createMatrix(int** matrix, int n, int m, int max, int min, char name) {
    matrix = setMemory(matrix, n, m);
    fillArrayRandValues(matrix, n, m, max, min);
    printf("\nМатрица %c =\n", name);
    printMatrix(matrix, n, m);
    return matrix;
}

int main() {
    char* locale = setlocale(LC_ALL, "");

    int** matrixA = NULL, ** matrixB = NULL, ** result = NULL;
    int N = 0, M = 0, K = 0;
    int max = 0, min = 0, value = 0;

    srand(time(0));

    printf("Введите размеры матриц ( A[N,M] B[M,K] ): ");
    scanf_s("%d %d %d", &N, &M, &K);
    printf("Введите минимальное и максимальное значение матриц: ");
    scanf_s("%d %d", &min, &max);

    matrixA = createMatrix(matrixA, N, M, max, min, 'A');
    matrixB = createMatrix(matrixB, M, K, max, min, 'B');
    value = generateRandNumber(max, min);

    // Умножение матрицы на число
    result = setMemory(result, N, M);
    result = multMatrixOnNumber(matrixA, N, M, &value);
    printf("\nA * %d =\n", value);
    printMatrix(result, N, M);
    freeMemory(result, N, M);

    // Транспонирование матрицы
    result = setMemory(result, M, N);
    result = matrixTransposition(matrixA, M, N);
    printf("\nТранспонированная матрица A =\n");
    printMatrix(result, M, N);

    freeMemory(result, M, N);

    // Умножение двух матриц
    result = setMemory(result, N, K);
    result = multMatrixOnMatrix(matrixA, matrixB, N, K, M);
    printf("\nA * B =\n");
    printMatrix(result, N, K);

    freeMemory(result, N, K);

    // Сложение двух матриц
    if (N == M && M == K) {
        result = setMemory(result, N, M);
        result = additionMatrix(matrixA, matrixB, N, M);
        printf("\nA + B =\n");
        printMatrix(result, N, M);
        freeMemory(result, N, K);
    }
    else printf("\nНельзя перемножить матрицы, матрицы разного размера\n");

    int ax = 0, ay = 0, bx = 0, by = 0;
    int valueVector = generateRandNumber(max, min);

    printf("\nВведите вектор a ( x, y ) : ");
    scanf_s("%d %d", &ax, &ay);
    printf("\nВведите вектор b ( x, y ) : ");
    scanf_s("%d %d", &bx, &by);

    // Умножение вектора на число
    printf("\nВектор a * %d = ", valueVector);
    multVectorOnNumber(ax, ay, valueVector);

    // Сложение двух векторов
    printf("\nВектор a + b = ");
    additionVectors(ax, ay, bx, by);

    // Умножение двух векторов
    printf("\nВектор a * b = ");
    multVectorOnVector(ax, ay, bx, by);

    // Очищение всей выделенной памяти
    freeMemory(matrixA, N, M);
    freeMemory(matrixB, M, K);

    return 0;
}