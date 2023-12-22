#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void show_arr_comm(int arr1[2][4], 
	 int arr2[3][3], int arr3[2][2]);
// 2차원 배열
int main()
{
	// 2차원 배열의 열의 크기가 다른 경우에는 
	// 매개변수 전달이 까다롭다
	int arr1[2][4] = { // 2행 4열 // arr1 배열 출력
		{1, 2, 3, 30},
		{4, 5, 6, 60}
	};

	int arr2[3][3] = {
		{10},
		{20, 30},
		{40, 50, 60}
	};

	int arr3[2][2] = { 100, 200, 300, 400 }; 
	show_arr_comm(arr1, arr2, arr3);
}
// arr값을 한번에 호출하는 함수 출력 

// 함수 역할: 프로그래밍 구조를 간결하게 하는 역할 (모듈화)라이브러리!
// 서로 다른 배열값을 받아서 출력하기

// 방법 1. 호출은 되지만 재사용이 어려움 
void show_arr_comm(int arr1[2][4], 
      int arr2[3][3], int arr3[2][2])
{
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d\t", arr1[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d\t", arr2[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d\t", arr3[i][j]);
		}
		printf("\n");
	}
}
