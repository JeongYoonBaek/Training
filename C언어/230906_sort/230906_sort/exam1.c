#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // ��,���
#include <stdlib.h> // ���Ĵٵ� ���̺귯�� srand()

int main()
{   
	int j = 0;
	int temp[] = { 8, 3, 1, 4 };
	for (int i = 0; i < 5; i++) {
		int key = temp[i]; // �迭 2��° ��ġ���� Ű���� ����
		for (j = i - 1; j >= 0 && temp[j] > key; j--) { // ���ʿ� �ִ� ���� ����
				temp[j + 1] = temp[j];
			}
			// �ڸ� �̵��� ������ Ű���� ���ڸ��� ����
			temp[j + 1] = key;
		}
	for (int i = 0; i < 4; i++) {
		printf("%d\t", temp[i]);
	}
}