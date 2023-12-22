#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // 입,출력
#include <stdlib.h> // 스탠다드 라이브러리 srand()

int main()
{   
	int j = 0;
	int temp[] = { 8, 3, 1, 4 };
	for (int i = 0; i < 5; i++) {
		int key = temp[i]; // 배열 2번째 위치부터 키값을 받음
		for (j = i - 1; j >= 0 && temp[j] > key; j--) { // 왼쪽에 있는 값을 비교함
				temp[j + 1] = temp[j];
			}
			// 자리 이동이 끝나고 키값을 빈자리에 삽입
			temp[j + 1] = key;
		}
	for (int i = 0; i < 4; i++) {
		printf("%d\t", temp[i]);
	}
}