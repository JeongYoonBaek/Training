#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// #define ARR1_ROW_D 3 // ��ó����
// ��� 2) ���� �Ȱ��� �ؼ� ����غ��� 

void show_arr_comm(int arr[][3], int row, int col);
// ���� ũ�Ⱑ �Ȱ����� ���� ������ �����ϰ� ���� ũ�⸦ �����.

int main()
{
	// ���������� �ϵ��ڵ��� ����!
	// �ϵ��ڵ��� ������ ��� ����(const) �Ǵ� #define�� ���
	// const int (Constant) ��� ������ ��κ� �빮�ڷ� ǥ��
	// const int ARR1_ROW = 3;
	// const int ARR1_COL = 3;
	int arr1[2][3] = { // 2�� 4�� // arr1 �迭 ���
		{1, 2, 3},
		{4, 5, 6},
	};
	show_arr_comm(arr1, 2, 3); // ���� ���� �ڵ� : hard coding

	int arr2[3][3] = {
		{10},
		{20, 30},
		{40, 50, 60}
	};
	show_arr_comm(arr2, 3, 3);

	int arr3[2][3] = { 100, 200, 300, 400 };
	show_arr_comm(arr3, 2 ,3 ); // �迭�ּ�, ��, ���� ����
}

/* ������ �ڵ�� �ּ��ϴ� ������ ������ ���� ����.
* FUNC : show_arr_comm
* PARAM : row - ��, cal - ��
* RETURN : None
* COMM : 2���� �迭�� ������ �޾� ���
*/

// arr���� �ѹ��� ȣ���ϴ� �Լ� ��� 

// �Լ� ����: ���α׷��� ������ �����ϰ� �ϴ� ���� (���ȭ)���̺귯��!
// ���� �ٸ� �迭���� �޾Ƽ� ����ϱ�

void show_arr_comm(int arr[][3], int row, int col) 
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
}
