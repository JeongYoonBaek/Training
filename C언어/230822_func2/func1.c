#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void show_arr(int a[]);
int main()
{
	// 1.배열 변수를 매개변수로 전달하는 방법
	// 2.지역변수, 전역변수 개념 이해 및 활용
	// 3.Call by Value (값에 의한 전달)
	// 4.Call by Address(주소값에 의한 전달)
	
	
	// 배열: 정보를 저장할 수 있는 연속적인 공간
	int arr[10] = { 0 }; // 정수값을 10개 저장할 수 있는 arr 배열 변수
	// 10개의 일반변수, 한공간에 10개 연속적으로 잡힘
	// 배열이 일반 변수는 아님. 
	
	int a; // 정수값을 1개만 저장하는 일반 변수 a

	// 1부터 10까지를 arr배열에 저장
	for (int i = 0; i < 10; i++) {//배열에는 무조건 반복문이 나와야 함
		arr[i] = i + 1; // 1부터 10까지 증가 (일반변수 영역)
		//printf("%d\t", arr[i]);
	}
	show_arr(arr); // 시작 주소 값을 아래 매개변수에 던져줌 
}

void show_arr(int a[]) // 배열 매개변수 넣기, a가 arr이 되기도 함
{              // 원래는 빈껍데기
	// main에서 만든 배열을 이 함수에서 출력
	// arr배열 변수의 주소값을 매개변수로 전달.
	for (int i = 0; i < 10; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}
}