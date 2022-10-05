#include <locale.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

vector<vector<int>> matrixFiller(int row, int col) {
    int premenNull = 0;
    vector<vector<int> > matrix(row);
    for (int i = 0; i < row; i++)
    {
        matrix[i].resize(col);
        for (int j = 0; j < col; j++) {
            if (j < premenNull) 
                matrix[i][j] = 0;
            else matrix[i][j] = rand() % 66;
        }
        premenNull += 1;
    }
    return matrix;
}

vector<vector<int>> matrixMulter(vector<vector<int>> matrix1, vector<vector<int>> matrix2, int row1, int col2, int col1) {
    vector<vector<int> > result (matrixFiller(row1, col2));
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (int l = 0; l < col1; l++) {
                result[i][j] += matrix1[i][l] * matrix2[l][j];
            }
        }
    }
    return result;
}

vector<vector<int>> matrixTransposition(vector<vector<int>> matrix, int col1, int row1) {
    vector<vector<int> > result(matrixFiller(col1, row1));
    for (int i = 0; i < col1; i++) {
        for (int j = 0; j < row1; j++) {
            result[i][j] = matrix[j][i];
        }
    }
    return result;
}

vector<vector<int>> matrixPlus(vector<vector<int>> matrix1, vector<vector<int>> matrix2, int row1, int col1) {
    vector<vector<int> > result(matrixFiller(row1, col1));
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

vector<vector<int>> matrixMinus(vector<vector<int>> matrix1, vector<vector<int>> matrix2, int row1, int col1) {
    vector<vector<int> > result(matrixFiller(row1, col1));
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
}

void matrixPrinter(vector<vector<int>> matrix) {
    for (int i = 0; i < matrix.size(); ++i)
    {
        matrix[i].resize(matrix.size());
        for (int j = 0; j < matrix.size(); ++j) {
            cout << matrix[i][j] << "\t ";
        }
        cout << endl;
    }
}

int main() {
    char* locale = setlocale(LC_ALL, "");
    srand(time(0));

    int rowFirstMatrix, colFirstMitrix;
    cout << "Введите колво строк:" << endl;
    cin >> rowFirstMatrix;
    cout << "Введите колво столбцов:" << endl;
    cin >> colFirstMitrix;

    cout << endl << "Итоговая матрица 1:" << endl;
    vector<vector<int> > firstMatrix = matrixFiller(rowFirstMatrix, colFirstMitrix);
    matrixPrinter(firstMatrix);

    int rowSecondMatrix, colSecondMitrix;
    cout << endl << "Введите колво строк:" << endl;
    cin >> rowSecondMatrix;
    cout << "Введите колво столбцов:" << endl;
    cin >> colSecondMitrix;

    cout << endl << "Итоговая матрица 2:" << endl;
    vector<vector<int> > secondMatrix = matrixFiller(rowSecondMatrix, colSecondMitrix);
    matrixPrinter(secondMatrix);

    cout << endl << "Умножение матриц:" << endl;
    matrixPrinter(matrixMulter(firstMatrix, secondMatrix, rowFirstMatrix, colSecondMitrix, colFirstMitrix));

    cout << endl << "Транспонирование матрицы:" << endl;
    matrixPrinter(matrixTransposition(firstMatrix, colFirstMitrix, rowFirstMatrix));

    cout << endl << "Сложение матриц:" << endl;
    matrixPrinter(matrixPlus(firstMatrix, secondMatrix, rowFirstMatrix, colFirstMitrix));

    cout << endl << "Вычитание матриц:" << endl;
    matrixPrinter(matrixMinus(firstMatrix, secondMatrix, rowFirstMatrix, colFirstMitrix));

    return 0;
}