#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// #define ARR1_ROW_D 3 // 전처리기
// 방법 2) 열을 똑같이 해서 출력해보기 

void show_arr_comm(int arr[][3], int row, int col);
// 열의 크기가 똑같을땐 행의 정보를 무시하고 열의 크기를 명시함.

int main()
{
	// 실전에서는 하드코딩은 금지!
	// 하드코딩된 값들은 상수 변수(const) 또는 #define을 사용
	// const int (Constant) 상수 변수는 대부분 대문자로 표기
	// const int ARR1_ROW = 3;
	// const int ARR1_COL = 3;
	int arr1[2][3] = { // 2행 4열 // arr1 배열 출력
		{1, 2, 3},
		{4, 5, 6},
	};
	show_arr_comm(arr1, 2, 3); // 숫자 값을 코딩 : hard coding

	int arr2[3][3] = {
		{10},
		{20, 30},
		{40, 50, 60}
	};
	show_arr_comm(arr2, 3, 3);

	int arr3[2][3] = { 100, 200, 300, 400 };
	show_arr_comm(arr3, 2 ,3 ); // 배열주소, 행, 열의 정보
}

/* 복잡한 코드는 주석하는 습관을 가지는 것이 좋다.
* FUNC : show_arr_comm
* PARAM : row - 행, cal - 열
* RETURN : None
* COMM : 2차원 배열의 정보를 받아 출력
*/

// arr값을 한번에 호출하는 함수 출력 

// 함수 역할: 프로그래밍 구조를 간결하게 하는 역할 (모듈화)라이브러리!
// 서로 다른 배열값을 받아서 출력하기

void show_arr_comm(int arr[][3], int row, int col) 
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
}
