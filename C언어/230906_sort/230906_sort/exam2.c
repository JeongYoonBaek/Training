#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // ��,���
#include <stdlib.h> // ���Ĵٵ� ���̺귯�� srand()

int main()
{
	int j = 0;
	int arr[] = { 8, 3, 1, 4 };
	int point[] = { 0 };

	/*int t = arr[i]; ��� (if��) ����� �� ���
	arr[i] = arr[j];
	arr[j] = t; */

	for (int i = 0; i < 4; i++) {
		int point[] = arr[i];
		for (j = i + 1; j < 4; j++) {
			int t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
			if (arr[j] > point) {
			}
		for (int i = 0; i < 4; i++) {
			printf("%d\t", arr[i]);
			}
		}
	}
}