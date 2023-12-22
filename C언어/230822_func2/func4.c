#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void show_arr_comm(int a[2][3]);
// 2차원 배열
int main()
{
	int arr1[2][3] = { // 2행 3열 // arr1 배열 출력
		{1, 2, 3},
		{4, 5, 6}
	};
	int arr2[2][3] = {
		{10},
		{20, 30},
	};
	int arr3[2][3] = { 100, 200, 300, 400 }; // arr3 배열 출력
	
	show_arr_comm(arr1);
	show_arr_comm(arr2);
	show_arr_comm(arr3);
}
// arr값을 한번에 호출하는 함수 출력 

// 함수 역할: 프로그래밍 구조를 간결하게 하는 역할 (모듈화)라이브러리!
void show_arr_comm(int a[2][3]) // 행의 크기는 생략가능 
                                // but 열의 크기는 명시
	{
		for (int i = 0; i < 2; i++) { // 2행
			for (int j = 0; j < 3; j++) { // 3열 
				printf("%d\t", a[i][j]); // 행,열 출력 
			}  // 1차원, 2차원 배열 매개변수 전달
			printf("\n");
		}
	}