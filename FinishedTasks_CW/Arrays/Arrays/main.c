// Copyright 2021 Ivan Novostroev

/*
������� �������� ��� ���������

���������� ������:
	1. ��������� ��������� ������� (������� � ��������)
	2. ��������� ��������� �������
	3. ����������� ��������� ������� ������� ��� ���������:
		����� ������������ �������� ��������� �������;
		����� ������������ ��������� ������� � ��������� ���������;
		����� ������������ ��������� ������� �������� �� ��������;
		�������� ������� �������� � ��������� ���������;
		�������� ������� ������ � ����� �������� ������� (��);
			������: 1 2 3 4 5 6 7 8 ---> 5 6 7 8 1 2 3 4;
			1. C ��� ��������.
			2. ��� ��� �������.
*/

#include <stdio.h>
#define SIZE 10
#include <malloc.h>

int main() {
	// �������

	//constant int SizeOfMassive_1 = 10;
	//int massive_1[SizeOfMassive_1];  ������ ������� (�� ��������)

	float massive_2[SIZE] = { 0 }; // ������ ������� (��������)

	int massive_3[] = { 1, 2, 3, 4, 5 }; // ������������ ������

	printf("%f", massive_2[0]);

	printf("%d", massive_3[2]);

	// ��������

	int* mass; // ��������� �� ������ �������������� �������
	int size;
	printf("Vvedite pazmer massiva: \n");
	scanf_s("%d", &size);

	mass = (int*)malloc(size * sizeof(int));

	float* massF = (float*)malloc(size * sizeof(float));

	// �������������
	int i;
	for (i = 0; i < size; i++) {
		mass[i] = 5;
	}
	// ��������
	mass[size / 2] = 0;
	// �����
	


	/*
	i = 0;
	while (i < size) {
		mass[i] = 5;

		i++;
	}
	*/
	free(mass); // �������� ������
	free(massF);
	return 0;
}