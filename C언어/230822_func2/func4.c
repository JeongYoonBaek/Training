#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void show_arr_comm(int a[2][3]);
// 2���� �迭
int main()
{
	int arr1[2][3] = { // 2�� 3�� // arr1 �迭 ���
		{1, 2, 3},
		{4, 5, 6}
	};
	int arr2[2][3] = {
		{10},
		{20, 30},
	};
	int arr3[2][3] = { 100, 200, 300, 400 }; // arr3 �迭 ���
	
	show_arr_comm(arr1);
	show_arr_comm(arr2);
	show_arr_comm(arr3);
}
// arr���� �ѹ��� ȣ���ϴ� �Լ� ��� 

// �Լ� ����: ���α׷��� ������ �����ϰ� �ϴ� ���� (���ȭ)���̺귯��!
void show_arr_comm(int a[2][3]) // ���� ũ��� �������� 
                                // but ���� ũ��� ���
	{
		for (int i = 0; i < 2; i++) { // 2��
			for (int j = 0; j < 3; j++) { // 3�� 
				printf("%d\t", a[i][j]); // ��,�� ��� 
			}  // 1����, 2���� �迭 �Ű����� ����
			printf("\n");
		}
	}