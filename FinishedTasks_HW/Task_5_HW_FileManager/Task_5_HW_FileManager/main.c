#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "C:\Users\mrhin\Desktop\Лобач\Инфа ЛАБЫ\Informatics-and-Programming\FinishedTasks_HW\Task_5_HW_FileManager\dirent-master\include\dirent.h"    // для работы с директориями
#include <sys/stat.h>  

char filesName[255][255];
int filesSize[255];
int arrayCount = 0;



int getFileSize(const char* file) {
    struct stat st;
    int full_size = 0;

    if (stat(file, &st) == 0) {
        if ((st.st_mode & S_IFMT) == S_IFDIR)
            return -1;
        else if ((st.st_mode & S_IFMT) == S_IFREG)
            return st.st_size;
        else
            return -2;
    }
}

void getSizesFromDir(char* path) {
    struct dirent* cur_file;
    DIR* dir;

    char full_file_path[200];

    dir = opendir(path);

    if (dir) {
        while ((cur_file = readdir(dir)) != NULL) {
            if (strcmp(".", cur_file->d_name) && strcmp("..", cur_file->d_name)) {
                strcpy(full_file_path, strcat(strcat(strcpy(full_file_path, path), "/"), cur_file->d_name));
                int cur_file_size = getFileSize(full_file_path);
                if (cur_file_size >= 0) {
                    printf("%s - %d B (%d kB)\n", cur_file->d_name, cur_file_size, cur_file_size / 1024);

                    filesSize[arrayCount] = cur_file_size;
                    strncpy(filesName[arrayCount], cur_file->d_name, 254);
                    filesName[arrayCount][254] = '\0';
                    arrayCount++;

                }
                else if (cur_file_size == -1)
                    getSizesFromDir(full_file_path);
            }
        }
        closedir(dir);
    }
}



void sortInsert(int* array, int* indexes, int size) {
    int temparray, tempindex;
    for (int i = 1; i < size; i++)
        for (int j = i; j > 0 && array[j - 1] > array[j]; j--) {
            temparray = array[j - 1];
            array[j - 1] = array[j];
            array[j] = temparray;

            tempindex = indexes[j - 1];
            indexes[j - 1] = indexes[j];
            indexes[j] = tempindex;
        }
}

void sortHoare(int* array, int* indexes, int first, int last) {
    int i = first, j = last, x = array[(first + last) / 2];

    do {
        while (array[i] < x) i++;
        while (array[j] > x) j--;
        if (i <= j) {
            if (array[i] > array[j]) {
                int tmparray = array[j];
                array[j] = array[i];
                array[i] = tmparray;

                int tmpindex = indexes[j];
                indexes[j] = indexes[i];
                indexes[i] = tmpindex;
            }
            i++;
            j--;
        }

    } while (i <= j);

    if (i < last) sortHoare(array, indexes, i, last);
    if (j > first) sortHoare(array, indexes, first, j);

}

void shiftDown(int* array, int* indexes, int root, int bottom) {       // Пирамидальная сортировка
    int maxChildArray, maxChildIndex;
    int done = 0;
    while ((root * 2 <= bottom) && (!done)) {
        if (root * 2 == bottom) {
            maxChildArray = root * 2;
            maxChildIndex = root * 2;
        }
        else if (array[root * 2] > array[root * 2 + 1]) {
            maxChildArray = root * 2;
            maxChildIndex = root * 2;
        }
        else {
            maxChildArray = root * 2 + 1;
            maxChildIndex = root * 2 + 1;
        }
        if (array[root] < array[maxChildArray]) {
            int tempArray = array[root];
            array[root] = array[maxChildArray];
            array[maxChildArray] = tempArray;
            root = maxChildArray;

            int tempIndex = indexes[root];
            indexes[root] = indexes[maxChildIndex];
            indexes[maxChildIndex] = tempIndex;
            root = maxChildIndex;
        }
        else
            done = 1;
    }
}
void sortHeap(int* array, int* indexes, int size) {
    for (int i = (size / 2); i >= 0; i--)
        shiftDown(array, indexes, i, size - 1);
    for (int i = size - 1; i >= 1; i--) {
        int temparray = array[0];
        array[0] = array[i];
        array[i] = temparray;

        int tempindex = indexes[0];
        indexes[0] = indexes[i];
        indexes[i] = tempindex;
        shiftDown(array, indexes, 0, i - 1);
    }
}


void inputIndexArray(int* array, int size) {
    for (int j = 0; j < size; j++) {
        array[j] = j;
    }
}

void copyArray(int* array_1, int* array_2, int size) {
    for (int j = 0; j < size; j++) {
        array_1[j] = array_2[j];
    }
}

int main() {
    char* locale = setlocale(LC_ALL, "");
    char path[200];
    float time;
    int progVar = 0;
    int isWork = 1;

    printf("Введите директорию: ");
    gets(path);

    printf("\n");
    getSizesFromDir(path);
    printf("\nВсего файлов: %d", arrayCount);

    int* allArrayIndex_1 = malloc(sizeof(int) * arrayCount);
    inputIndexArray(allArrayIndex_1, arrayCount);
    int* arrayCopy_1 = malloc(sizeof(int) * arrayCount);
    copyArray(arrayCopy_1, filesSize, arrayCount);

    int* allArrayIndex_2 = malloc(sizeof(int) * arrayCount);
    inputIndexArray(allArrayIndex_2, arrayCount);
    int* arrayCopy_2 = malloc(sizeof(int) * arrayCount);
    copyArray(arrayCopy_2, filesSize, arrayCount);

    int* allArrayIndex_3 = malloc(sizeof(int) * arrayCount);
    inputIndexArray(allArrayIndex_3, arrayCount);
    int* arrayCopy_3 = malloc(sizeof(int) * arrayCount);
    copyArray(arrayCopy_3, filesSize, arrayCount);

    while (isWork) {
        printf("\n\nДля сортировки файлов выберите один из вариантов: \n");
        printf("(1) Сортировка вставкой \n");
        printf("(2) Сортировка Хаора \n");
        printf("(3) Пирамидальная сортировка \n");
        printf("(0) Выход из программы \n\n");
        scanf_s("%d", &progVar);

        switch (progVar) {
        case 1:
            time = clock();
            sortInsert(arrayCopy_1, allArrayIndex_1, arrayCount);
            time = clock() - time;
            for (int j = 0; j < arrayCount; j++) {
                int k = allArrayIndex_1[j];
                printf("%s - %d B (%d kB)\n", filesName[k], arrayCopy_1[j], arrayCopy_1[j] / 100);
            }
            printf("\nВремя исполнения: %.2fs", time / 1000);
            break;
        case 2:
            time = clock();
            sortHoare(arrayCopy_2, allArrayIndex_2, 0, arrayCount - 1);
            time = clock() - time;
            for (int j = 0; j < arrayCount; j++) {
                int k = allArrayIndex_2[j];
                printf("%s - %d B (%d kB)\n", filesName[k], arrayCopy_2[j], arrayCopy_2[j] / 100);
            }
            printf("\nВремя исполнения: %.2fs", time / 1000);
            break;
        case 3:
            time = clock();
            sortHeap(arrayCopy_3, allArrayIndex_3, arrayCount);
            time = clock() - time;
            for (int j = 0; j < arrayCount; j++) {
                int k = allArrayIndex_3[j];
                printf("%s - %d B (%d kB)\n", filesName[k], arrayCopy_3[j], arrayCopy_3[j] / 100);
            }
            printf("\nВремя исполнения: %.2fs", time / 1000);
            break;
        case 0:
            isWork = 0;
            break;
        default:
            break;
        }
    }
    return 0;
}